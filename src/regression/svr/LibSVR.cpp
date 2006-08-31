/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 1999-2006 Soeren Sonnenburg
 * Copyright (C) 1999-2006 Fraunhofer Institute FIRST and Max-Planck-Society
 */

#include "regression/svr/LibSVR.h"
#include "lib/io.h"

CLibSVR::CLibSVR()
{
	model=NULL;
}

CLibSVR::~CLibSVR()
{
	free(model);
}

bool CLibSVR::train()
{
	free(model);

	struct svm_problem problem;
	struct svm_parameter param;
	struct svm_node* x_space;

	ASSERT(get_labels() && get_labels()->get_num_labels());
	problem.l=get_labels()->get_num_labels();
	CIO::message(M_INFO, "%d trainlabels\n", problem.l);

	problem.y=new double[problem.l];
	problem.x=new struct svm_node*[problem.l];
	x_space=new struct svm_node[2*problem.l];

	ASSERT(problem.y);
	ASSERT(problem.x);
	ASSERT(x_space);

	for (int i=0; i<problem.l; i++)
	{
		problem.y[i]=get_labels()->get_label(i);
		problem.x[i]=&x_space[2*i];
		x_space[2*i].index=i;
		x_space[2*i+1].index=-1;
	}

	int weights_label[2]={-1,+1};
	double weights[2]={1.0,get_C2()/get_C1()};

	ASSERT(get_kernel());

	param.svm_type=EPSILON_SVR; // epsilon SVR
	param.kernel_type = LINEAR;
	param.degree = 3;
	param.gamma = 0;	// 1/k
	param.coef0 = 0;
	param.nu = 0.5;
	param.kernel=get_kernel();
	param.cache_size = get_kernel()->get_cache_size();
	param.C = get_C1();
	param.eps = epsilon;
	param.p = tube_epsilon;
	param.shrinking = 1;
	param.nr_weight = 2;
	param.weight_label = weights_label;
	param.weight = weights;

	const char* error_msg = svm_check_parameter(&problem,&param);

	if(error_msg)
	{
		fprintf(stderr,"Error: %s\n",error_msg);
		exit(1);
	}

	model = svm_train(&problem, &param);

	if (model)
	{
		ASSERT(model->nr_class==2);
		ASSERT( (model->l==0) || (model->l > 0 && model->SV && model->sv_coef && model->sv_coef[0]) );

		int num_sv=model->l;

		create_new_model(num_sv);

		CSVM::set_objective(model->objective);

		set_bias(-model->rho[0]);

		for (int i=0; i<num_sv; i++)
		{
			set_support_vector(i, (model->SV[i])->index);
			set_alpha(i, model->sv_coef[0][i]);
		}

		delete[] problem.x;
		delete[] problem.y;
		delete[] x_space;

		return true;
	}
	else
		return false;
}

