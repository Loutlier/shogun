traindat = [0.237647629, 0.0584100077, 0.0252256721, 0.772557209, 0.728082346, 0.502987388, 0.709640741, 0.597553176, 0.718970516, 0.548809309, 0.472040552, 0.070587926, 0.459950614;0.320434673, 0.874704169, 0.517893009, 0.318035461, 0.431837482, 0.447975678, 0.589099194, 0.213923396, 0.90175492, 0.644874407, 0.645945585, 0.85694173, 0.548117546;0.196979986, 0.867267731, 0.580767859, 0.000660197094, 0.89277055, 0.532167789, 0.231852785, 0.826069503, 0.82077546, 0.677722302, 0.32355208, 0.00736405016, 0.0930591026;0.426949643, 0.520936471, 0.521816548, 0.44914082, 0.116945471, 0.557450281, 0.901296335, 0.471463836, 0.935837131, 0.597119402, 0.212608806, 0.820060087, 0.184152972;0.547263013, 0.324316086, 0.949500975, 0.159888275, 0.766903067, 0.464169584, 0.538579328, 0.141816648, 0.443435211, 0.106909611, 0.165978197, 0.965470633, 0.440684173;0.326312722, 0.184782651, 0.430428631, 0.900728303, 0.100951308, 0.0776521927, 0.946910946, 0.701053173, 0.563118253, 0.370045668, 0.865613857, 0.311643027, 0.531513917;0.451755145, 0.213340679, 0.645886951, 0.689764033, 0.0314995505, 0.772728487, 0.732833787, 0.896700956, 0.382952779, 0.0933191234, 0.733764754, 0.17144842, 0.473841517;0.474683094, 0.478775852, 0.496046484, 0.205300086, 0.000214442063, 0.330798525, 0.0284133884, 0.789781519, 0.851090231, 0.731277509, 0.286708213, 0.933634373, 0.332818418;0.190744861, 0.129934084, 0.805658435, 0.709407613, 0.911662267, 0.587120072, 0.0913291125, 0.128522461, 0.629600337, 0.994929146, 0.438754312, 0.950168562, 0.838490868;0.489599855, 0.00953023685, 0.116191522, 0.58490428, 0.56903033, 0.721767724, 0.987558845, 0.877308831, 0.281985162, 0.770616404, 0.377956562, 0.0942927116, 0.427355373;0.960108176, 0.75310023, 0.0637402514, 0.0204266992, 0.973134813, 0.197727131, 0.151462995, 0.253458299, 0.220714416, 0.00446705771, 0.745961529, 0.333820267, 0.672055256]
testdat = [0.781662498, 0.0990625305, 0.730797516, 0.66048147, 0.825170422, 0.624677135, 0.197281233, 0.51152901, 0.937429097, 0.431272401, 0.509876378, 0.120511556, 0.570307902, 0.746755131, 0.679265327, 0.102757904, 0.28977822;0.166350049, 0.620614932, 0.326881766, 0.276352604, 0.975507789, 0.253206846, 0.0773190627, 0.88897015, 0.0793067544, 0.722271828, 0.690655873, 0.107798383, 0.0679906968, 0.49532125, 0.861928713, 0.293736854, 0.393090711;0.798522276, 0.0571420834, 0.244043635, 0.767659161, 0.335080025, 0.453867889, 0.104553171, 0.656946987, 0.461321395, 0.108105602, 0.303249349, 0.52996727, 0.260020228, 0.581237881, 0.630018929, 0.667085187, 0.129395046;0.548054159, 0.297778185, 0.105591552, 0.857487699, 0.990628151, 0.995069536, 0.69665515, 0.884292149, 0.701540696, 0.371784813, 0.327005665, 0.382302598, 0.00770530154, 0.492972471, 0.0828863642, 0.53588686, 0.15742513;0.540642365, 0.792006017, 0.569560454, 0.250447487, 0.101276874, 0.182087999, 0.436636801, 0.928849805, 0.0264641003, 0.0932459772, 0.499969322, 0.19272229, 0.385898755, 0.39198164, 0.561377761, 0.170386832, 0.252449327;0.816205849, 0.628733341, 0.687355589, 0.72754033, 0.0399807559, 0.253435971, 0.932401752, 0.177487914, 0.458671884, 0.916210266, 0.55520353, 0.421089544, 0.543712439, 0.685361997, 0.899365409, 0.16122919, 0.538015857;0.801800479, 0.969126527, 0.933713243, 0.272786717, 0.604642814, 0.709902934, 0.456380931, 0.87584988, 0.138367002, 0.894877155, 0.68152783, 0.322927619, 0.778112046, 0.401115833, 0.327879177, 0.101572009, 0.940221658;0.978346884, 0.748195591, 0.864115281, 0.683102881, 0.55102259, 0.185069519, 0.693198242, 0.0792878083, 0.649876534, 0.53553553, 0.377017953, 0.966624739, 0.92826567, 0.654260529, 0.0724753837, 0.972970421, 0.302854293;0.814629185, 0.649884548, 0.394796474, 0.399394482, 0.178017387, 0.339332579, 0.144877044, 0.102702223, 0.718497546, 0.567790653, 0.757971393, 0.304278821, 0.260463218, 0.100065418, 0.988486505, 0.676934383, 0.360694105;0.0453608573, 0.246115669, 0.728874156, 0.175892097, 0.801240728, 0.502439597, 0.849997394, 0.00159542335, 0.349660805, 0.498534114, 0.544424088, 0.107700532, 0.612786479, 0.464879632, 0.86151129, 0.274085488, 0.657716509;0.0960156344, 0.754328799, 0.946693268, 0.843204976, 0.375786077, 0.592829901, 0.474940287, 0.288765441, 0.629586417, 0.512103859, 0.782732148, 0.0530442411, 0.604560719, 0.254532477, 0.696475134, 0.80533672, 0.507645956]
km_train = [0.99926598, 0.998183297, 0.998046089, 0.996547839, 0.999228651, 0.998355252, 0.999214191, 0.999171228, 0.99938577, 0.997550723, 0.999056757, 0.99914009, 0.998781324;0.998183297, 0.999679477, 0.998679727, 0.987837107, 0.999220849, 0.997696599, 0.997639839, 0.9986751, 0.999805731, 0.998563023, 0.998581578, 0.999272081, 0.997194894;0.998046089, 0.998679727, 0.999894437, 0.99867992, 0.999360549, 0.99945806, 0.999434745, 0.999366674, 0.999903765, 0.999542233, 0.998916814, 0.999895617, 0.999121826;0.996547839, 0.987837107, 0.99867992, 0.999837951, 0.998127988, 0.99919148, 0.999879878, 0.999676653, 0.999746101, 0.999533129, 0.99949613, 0.998763691, 0.999268887;0.999228651, 0.999220849, 0.999360549, 0.998127988, 0.999986457, 0.999540571, 0.999256668, 0.999228797, 0.999842578, 0.999703244, 0.999413038, 0.999451688, 0.999645476;0.998355252, 0.997696599, 0.99945806, 0.99919148, 0.999540571, 0.999737137, 0.999770553, 0.999765358, 0.999860342, 0.999680757, 0.999060929, 0.999374199, 0.999025749;0.999214191, 0.997639839, 0.999434745, 0.999879878, 0.999256668, 0.999770553, 0.99999164, 0.999933154, 0.99993584, 0.99969605, 0.999780992, 0.999384301, 0.999437575;0.999171228, 0.9986751, 0.999366674, 0.999676653, 0.999228797, 0.999765358, 0.999933154, 0.999981926, 0.999945929, 0.999818248, 0.999736668, 0.99870166, 0.999121239;0.99938577, 0.999805731, 0.999903765, 0.999746101, 0.999842578, 0.999860342, 0.99993584, 0.999945929, 0.999996053, 0.999968839, 0.999806603, 0.999961983, 0.999706229;0.997550723, 0.998563023, 0.999542233, 0.999533129, 0.999703244, 0.999680757, 0.99969605, 0.999818248, 0.999968839, 0.999965879, 0.999190765, 0.999807832, 0.999361461;0.999056757, 0.998581578, 0.998916814, 0.99949613, 0.999413038, 0.999060929, 0.999780992, 0.999736668, 0.999806603, 0.999190765, 0.999830256, 0.99903398, 0.999561258;0.99914009, 0.999272081, 0.999895617, 0.998763691, 0.999451688, 0.999374199, 0.999384301, 0.99870166, 0.999961983, 0.999807832, 0.99903398, 0.999989977, 0.999607635;0.998781324, 0.997194894, 0.999121826, 0.999268887, 0.999645476, 0.999025749, 0.999437575, 0.999121239, 0.999706229, 0.999361461, 0.999561258, 0.999607635, 0.999612453]
km_test = [0.999034684, 0.999658225, 0.999830787, 0.999464208, 0.99922336, 0.998863301, 0.999188527, 0.998853008, 0.998493229, 0.999186002, 0.999559892, 0.992241411, 0.999103764, 0.99847894, 0.999572546, 0.998742941, 0.998360231;0.999085213, 0.999148858, 0.999039236, 0.999593548, 0.999329901, 0.998222377, 0.996158411, 0.99954157, 0.997702456, 0.998386969, 0.999157866, 0.99468533, 0.996097549, 0.998535799, 0.99938942, 0.999227454, 0.994739728;0.999914537, 0.999849019, 0.999622638, 0.999412825, 0.999005155, 0.998635557, 0.998744899, 0.999789304, 0.998148136, 0.99941445, 0.999673626, 0.997625393, 0.998497334, 0.998997621, 0.999789507, 0.998900453, 0.998163197;0.999832546, 0.999448005, 0.999785809, 0.99926187, 0.999488659, 0.999141173, 0.999346523, 0.998485082, 0.999304677, 0.9997989, 0.999657645, 0.993353474, 0.99905808, 0.999236011, 0.999868939, 0.994692041, 0.999070802;0.99968789, 0.999506572, 0.999849917, 0.999771882, 0.999421561, 0.999315858, 0.997592772, 0.99949063, 0.999648599, 0.998966363, 0.999870432, 0.9904054, 0.998895345, 0.999098738, 0.999979484, 0.999476307, 0.998134795;0.999791483, 0.999559239, 0.999785535, 0.999366119, 0.999814695, 0.999530747, 0.998894682, 0.99966086, 0.999082609, 0.999494136, 0.999705537, 0.995234995, 0.999066937, 0.999223232, 0.999821713, 0.998483315, 0.998950662;0.999853115, 0.999741251, 0.999921296, 0.999780977, 0.999939263, 0.999828698, 0.999879369, 0.999870758, 0.999426762, 0.999896075, 0.999859237, 0.994831109, 0.999458459, 0.999830628, 0.999952006, 0.996356569, 0.999618867;0.999959451, 0.999738755, 0.999962903, 0.999881148, 0.999892397, 0.999743984, 0.999840055, 0.999561123, 0.999693296, 0.999869252, 0.999797744, 0.998914672, 0.999859394, 0.999858651, 0.99988857, 0.999331789, 0.999596578;0.999987535, 0.999898876, 0.999934918, 0.999968881, 0.999969796, 0.999844889, 0.999730149, 0.999943558, 0.999905759, 0.999909457, 0.999927197, 0.999364691, 0.999632047, 0.999923654, 0.999966871, 0.999838679, 0.99919875;0.999916308, 0.999345481, 0.99970844, 0.99976464, 0.999864545, 0.999322814, 0.999222714, 0.998917026, 0.999771953, 0.999667264, 0.999748981, 0.998265844, 0.998983822, 0.999598522, 0.999937308, 0.999613445, 0.998167831;0.999780611, 0.999827397, 0.999922365, 0.999724484, 0.999566521, 0.999278609, 0.999362067, 0.999323352, 0.999241279, 0.99987613, 0.999854226, 0.99457943, 0.999476891, 0.999412834, 0.999934311, 0.998507246, 0.999439199;0.999893387, 0.999932921, 0.999754204, 0.999701698, 0.999691443, 0.998819432, 0.999346243, 0.999747296, 0.999303879, 0.9996432, 0.99982122, 0.998219128, 0.998706654, 0.999211985, 0.999822261, 0.999673456, 0.997812874;0.999665269, 0.999795424, 0.999864775, 0.999412826, 0.999256756, 0.998724321, 0.998851699, 0.998752816, 0.999172597, 0.99971043, 0.999822775, 0.992482769, 0.999153075, 0.998713417, 0.999921319, 0.99862396, 0.998966634]
functionname = 'test_sigmoid_kernel'
kernelname = 'SigmoidKernel'
gamma_= 1.1000000000000001 
size_= 10 
coef0= 1.3 
