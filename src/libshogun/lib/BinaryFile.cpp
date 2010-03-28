#include "lib/File.h"
#include "features/SparseFeatures.h"
#include "lib/BinaryFile.h"

using namespace shogun;

CBinaryFile::CBinaryFile(FILE* f, const char* name) : CFile(f, name)
{
}

CBinaryFile::CBinaryFile(char* fname, char rw, const char* name) : CFile(fname, rw, name)
{
}

CBinaryFile::~CBinaryFile()
{
}

void CBinaryFile::set_variable_name(const char* name)
{
}

char* CBinaryFile::get_variable_name()
{
	return NULL;
}

#define GET_VECTOR(fname, sg_type, datatype)										\
void CBinaryFile::fname(sg_type*& vec, int32_t& len)								\
{																					\
	if (!file)																		\
		SG_ERROR("File invalid.\n");												\
	SGDataType dtype=read_header();													\
	if (dtype!=datatype)															\
		SG_ERROR("Datatype mismatch\n");											\
																					\
	if (fread(&len, sizeof(int32_t), 1, file)!=1)									\
		SG_ERROR("Failed to read vector length\n");									\
	vec=new sg_type[len];															\
	if (fread(vec, sizeof(sg_type), len, file)!=(size_t) len)						\
		SG_ERROR("Failed to read Matrix\n");										\
}

GET_VECTOR(get_byte_vector, uint8_t, DT_VECTOR_BYTE)
GET_VECTOR(get_char_vector, char, DT_VECTOR_CHAR)
GET_VECTOR(get_int_vector, int32_t, DT_VECTOR_INT)
GET_VECTOR(get_shortreal_vector, float32_t, DT_VECTOR_SHORTREAL)
GET_VECTOR(get_real_vector, float64_t, DT_VECTOR_REAL)
GET_VECTOR(get_short_vector, int16_t, DT_VECTOR_SHORT)
GET_VECTOR(get_word_vector, uint16_t, DT_VECTOR_WORD)
#undef GET_VECTOR

#define GET_MATRIX(fname, sg_type, datatype)										\
void CBinaryFile::fname(sg_type*& matrix, int32_t& num_feat, int32_t& num_vec)		\
{																					\
	if (!file)																		\
		SG_ERROR("File invalid.\n");												\
	SGDataType dtype=read_header();													\
	if (dtype!=datatype)															\
		SG_ERROR("Datatype mismatch\n");											\
																					\
	if (fread(&num_feat, sizeof(int32_t), 1, file)!=1 ||							\
			fread(&num_vec, sizeof(int32_t), 1, file)!=1)							\
		SG_ERROR("Failed to read Matrix dimensions\n");								\
	matrix=new sg_type[int64_t(num_feat)*num_vec];									\
	if (fread(matrix, sizeof(sg_type)*num_feat, num_vec, file)!=(size_t) num_vec)	\
		SG_ERROR("Failed to read Matrix\n");										\
}

GET_MATRIX(get_char_matrix, char, DT_DENSE_CHAR)
GET_MATRIX(get_byte_matrix, uint8_t, DT_DENSE_BYTE)
GET_MATRIX(get_int_matrix, int32_t, DT_DENSE_INT)
GET_MATRIX(get_uint_matrix, uint32_t, DT_DENSE_UINT)
GET_MATRIX(get_long_matrix, int64_t, DT_DENSE_LONG)
GET_MATRIX(get_ulong_matrix, uint64_t, DT_DENSE_ULONG)
GET_MATRIX(get_short_matrix, int16_t, DT_DENSE_SHORT)
GET_MATRIX(get_word_matrix, uint16_t, DT_DENSE_WORD)
GET_MATRIX(get_shortreal_matrix, float32_t, DT_DENSE_SHORTREAL)
GET_MATRIX(get_real_matrix, float64_t, DT_DENSE_REAL)
GET_MATRIX(get_longreal_matrix, floatmax_t, DT_DENSE_LONGREAL)
#undef GET_MATRIX

void CBinaryFile::get_byte_ndarray(uint8_t*& array, int32_t*& dims, int32_t& num_dims)
{
}

void CBinaryFile::get_char_ndarray(char*& array, int32_t*& dims, int32_t& num_dims)
{
}

void CBinaryFile::get_int_ndarray(int32_t*& array, int32_t*& dims, int32_t& num_dims)
{
}

void CBinaryFile::get_shortreal_ndarray(float32_t*& array, int32_t*& dims, int32_t& num_dims)
{
}

void CBinaryFile::get_real_ndarray(float64_t*& array, int32_t*& dims, int32_t& num_dims)
{
}

void CBinaryFile::get_short_ndarray(int16_t*& array, int32_t*& dims, int32_t& num_dims)
{
}

void CBinaryFile::get_word_ndarray(uint16_t*& array, int32_t*& dims, int32_t& num_dims)
{
}

void CBinaryFile::get_real_sparsematrix(TSparse<float64_t>*& matrix, int32_t& num_feat, int32_t& num_vec)
{
	if (!(file))
		SG_ERROR("File invalid.\n");

	SGDataType dtype=read_header();
	if (dtype!=DT_NDARRAY_REAL)
		SG_ERROR("Datatype mismatch\n");

	if (fread(&num_vec, sizeof(int32_t), 1, file)!=1)
		SG_ERROR("Failed to read number of vectors\n");

	matrix=new TSparse<float64_t>[num_vec];

	for (int32_t i=0; i<num_vec; i++)
	{
		int32_t len=0;
		if (fread(&len, sizeof(int32_t), 1, file)!=1)
			SG_ERROR("Failed to read sparse vector length of vector idx=%d\n", i);
		matrix[i].num_feat_entries=len;
		TSparseEntry<float64_t>* vec = new TSparseEntry<float64_t>[len];
		if (fread(vec, sizeof(TSparseEntry<float64_t>), len, file)!= (size_t) len)
			SG_ERROR("Failed to read sparse vector %d\n", i);
		matrix[i].features=vec;
	}
}


#define GET_STRING_LIST(fname, sg_type, datatype)												\
void CBinaryFile::fname(T_STRING<sg_type>*& strings, int32_t& num_str, int32_t& max_string_len) \
{																								\
	strings=NULL;																				\
	num_str=0;																					\
	max_string_len=0;																			\
																								\
	if (!file)																					\
		SG_ERROR("File invalid.\n");															\
																								\
	SGDataType dtype=read_header();																\
	if (dtype!=datatype)																		\
		SG_ERROR("Datatype mismatch\n");														\
																								\
	if (fread(&num_str, sizeof(int32_t), 1, file)!=1)											\
		SG_ERROR("Failed to read number of strings\n");											\
																								\
	strings=new T_STRING<sg_type>[num_str];														\
																								\
	for (int32_t i=0; i<num_str; i++)															\
	{																							\
		int32_t len=0;																			\
		if (fread(&len, sizeof(int32_t), 1, file)!=1)											\
			SG_ERROR("Failed to read string length of string with idx=%d\n", i);				\
		strings[i].length=len;																	\
		sg_type* str = new sg_type[len];														\
		if (fread(str, sizeof(sg_type), len, file)!= (size_t) len)								\
			SG_ERROR("Failed to read string %d\n", i);											\
		strings[i].string=str;																	\
	}																							\
}

GET_STRING_LIST(get_char_string_list, char, DT_STRING_CHAR)
GET_STRING_LIST(get_byte_string_list, uint8_t, DT_STRING_BYTE)
GET_STRING_LIST(get_int_string_list, int32_t, DT_STRING_INT)
GET_STRING_LIST(get_uint_string_list, uint32_t, DT_STRING_UINT)
GET_STRING_LIST(get_long_string_list, int64_t, DT_STRING_LONG)
GET_STRING_LIST(get_ulong_string_list, uint64_t, DT_STRING_ULONG)
GET_STRING_LIST(get_short_string_list, int16_t, DT_STRING_SHORT)
GET_STRING_LIST(get_word_string_list, uint16_t, DT_STRING_WORD)
GET_STRING_LIST(get_shortreal_string_list, float32_t, DT_STRING_SHORTREAL)
GET_STRING_LIST(get_real_string_list, float64_t, DT_STRING_REAL)
GET_STRING_LIST(get_longreal_string_list, floatmax_t, DT_STRING_LONGREAL)
#undef GET_STRING_LIST

/** set functions - to pass data from shogun to the target interface */

#define SET_VECTOR(fname, sg_type, dtype)							\
void CBinaryFile::fname(const sg_type* vec, int32_t len)			\
{																	\
	if (!(file && vec))												\
		SG_ERROR("File or vector invalid.\n");						\
																	\
	write_header(dtype);											\
																	\
	if (fwrite(&len, sizeof(int32_t), 1, file)!=1 ||				\
			fwrite(vec, sizeof(sg_type), len, file)!=(size_t) len)	\
		SG_ERROR("Failed to write vector\n");						\
}
SET_VECTOR(set_byte_vector, uint8_t, DT_VECTOR_BYTE)
SET_VECTOR(set_char_vector, char, DT_VECTOR_CHAR)
SET_VECTOR(set_int_vector, int32_t, DT_VECTOR_INT)
SET_VECTOR(set_shortreal_vector, float32_t, DT_VECTOR_SHORTREAL)
SET_VECTOR(set_real_vector, float64_t, DT_VECTOR_REAL)
SET_VECTOR(set_short_vector, int16_t, DT_VECTOR_SHORT)
SET_VECTOR(set_word_vector, uint16_t, DT_VECTOR_WORD)
#undef SET_VECTOR

#define SET_MATRIX(fname, sg_type, dtype) \
void CBinaryFile::fname(const sg_type* matrix, int32_t num_feat, int32_t num_vec)	\
{																					\
	if (!(file && matrix))															\
		SG_ERROR("File or matrix invalid.\n");										\
																					\
	write_header(dtype);															\
																					\
	if (fwrite(&num_feat, sizeof(int32_t), 1, file)!=1 ||							\
			fwrite(&num_vec, sizeof(int32_t), 1, file)!=1 ||						\
			fwrite(matrix, sizeof(sg_type)*num_feat, num_vec, file)!=(size_t) num_vec)	\
		SG_ERROR("Failed to write Matrix\n");										\
}
SET_MATRIX(set_char_matrix, char, DT_DENSE_CHAR)
SET_MATRIX(set_byte_matrix, uint8_t, DT_DENSE_BYTE)
SET_MATRIX(set_int_matrix, int32_t, DT_DENSE_INT)
SET_MATRIX(set_uint_matrix, uint32_t, DT_DENSE_UINT)
SET_MATRIX(set_long_matrix, int64_t, DT_DENSE_LONG)
SET_MATRIX(set_ulong_matrix, uint64_t, DT_DENSE_ULONG)
SET_MATRIX(set_short_matrix, int16_t, DT_DENSE_SHORT)
SET_MATRIX(set_word_matrix, uint16_t, DT_DENSE_WORD)
SET_MATRIX(set_shortreal_matrix, float32_t, DT_DENSE_SHORTREAL)
SET_MATRIX(set_real_matrix, float64_t, DT_DENSE_REAL)
SET_MATRIX(set_longreal_matrix, floatmax_t, DT_DENSE_LONGREAL)
#undef SET_MATRIX

void CBinaryFile::set_real_sparsematrix(const TSparse<float64_t>* matrix, int32_t num_feat, int32_t num_vec, int64_t nnz)
{
	if (!(file && matrix))
		SG_ERROR("File or matrix invalid.\n");

	write_header(DT_SPARSE_REAL);

	if (fwrite(&num_vec, sizeof(int32_t), 1, file)!=1)
		SG_ERROR("Failed to write Sparse Matrix\n");

	for (int32_t i=0; i<num_vec; i++)
	{
		TSparseEntry<float64_t>* vec = matrix[i].features;
		int32_t len=matrix[i].num_feat_entries;
		if ((fwrite(&len, sizeof(int32_t), 1, file)!=1) ||
				(fwrite(vec, sizeof(TSparseEntry<float64_t>), len, file)!= (size_t) len))
			SG_ERROR("Failed to write Sparse Matrix\n");
	}
}

#define SET_STRING_LIST(fname, sg_type, dtype) \
void CBinaryFile::fname(const T_STRING<sg_type>* strings, int32_t num_str)	\
{																						\
	if (!(file && strings))																\
		SG_ERROR("File or strings invalid.\n");											\
																						\
	write_header(dtype);																\
	for (int32_t i=0; i<num_str; i++)													\
	{																					\
		int32_t len = strings[i].length;												\
		if ((fwrite(&len, sizeof(int32_t), 1, file)!=1) ||								\
				(fwrite(strings[i].string, sizeof(sg_type), len, file)!= (size_t) len))	\
			SG_ERROR("Failed to write Sparse Matrix\n");								\
	}																					\
}
SET_STRING_LIST(set_char_string_list, char, DT_STRING_CHAR)
SET_STRING_LIST(set_byte_string_list, uint8_t, DT_STRING_BYTE)
SET_STRING_LIST(set_int_string_list, int32_t, DT_STRING_INT)
SET_STRING_LIST(set_uint_string_list, uint32_t, DT_STRING_UINT)
SET_STRING_LIST(set_long_string_list, int64_t, DT_STRING_LONG)
SET_STRING_LIST(set_ulong_string_list, uint64_t, DT_STRING_ULONG)
SET_STRING_LIST(set_short_string_list, int16_t, DT_STRING_SHORT)
SET_STRING_LIST(set_word_string_list, uint16_t, DT_STRING_WORD)
SET_STRING_LIST(set_shortreal_string_list, float32_t, DT_STRING_SHORTREAL)
SET_STRING_LIST(set_real_string_list, float64_t, DT_STRING_REAL)
SET_STRING_LIST(set_longreal_string_list, floatmax_t, DT_STRING_LONGREAL)
#undef SET_STRING_LIST


int32_t CBinaryFile::parse_first_header(SGDataType &type)
{
	    return -1;
}

int32_t CBinaryFile::parse_next_header(SGDataType &type)
{
	    return -1;
}


SGDataType CBinaryFile::read_header()
{
	ASSERT(file);

	char fourcc[4];
	uint16_t endian=0;
	uint16_t dtype=0;

	if (!((fread(&fourcc, sizeof(char), 4, file)==4) &&
			(fread(&endian, sizeof(uint16_t), 1, file)== 1) &&
			(fread(&dtype, sizeof(uint16_t), 1, file)== 1)))
		SG_ERROR("Error reading header\n");

	if (strncmp(fourcc, "SG00", 4))
		SG_ERROR("Header mismatch, expected SG00\n");

	return (SGDataType) dtype;
}

void CBinaryFile::write_header(SGDataType datatype)
{
	ASSERT(file);

	const char* fourcc="SG00";
	uint16_t endian=0x1234;
	uint16_t dtype=datatype;

	if (!((fwrite(fourcc, sizeof(char), 4, file)==4) &&
			(fwrite(&endian, sizeof(uint16_t), 1, file)==1) &&
			(fwrite(&dtype, sizeof(uint16_t), 1, file)==1)))
		SG_ERROR("Error writing header\n");
}
