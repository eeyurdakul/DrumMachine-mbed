const uint8_t kNumChannels = 1;
const uint8_t kBitsPerSample = 16;
const uint32_t kSampleRate = 44100;
const uint32_t kSampleSize = 4410;
const float kAudioTime = 0.10000;

const uint16_t audioSample[4410] = {32767, 46439, 59710, 31903, 66, 15793, 43105, 43618, 44085, 34712, 16122, 10750, 24386, 39072, 41579, 36591, 27241, 17061, 19309, 39228, 50691, 40998, 23014, 16334, 29754, 43213, 36532, 27006, 30395, 42226, 47214, 34443, 15528, 16122, 34963, 45103, 44233, 43394, 44765, 44430, 34797, 17133, 6680, 17000, 37762, 47852, 43242, 30382, 19439, 19588, 34224, 49759, 52884, 43548, 27260, 20748, 27465, 34997, 39685, 42219, 37783, 31753, 28378, 33490, 38572, 32932, 22791, 19477, 34962, 44059, 40022, 35945, 28725, 15257, 7824, 21383, 42242, 50925, 39545, 21226, 16246, 24545, 40110, 46458, 39491, 38501, 39083, 30874, 24546, 22744, 32102, 51643, 55074, 39576, 25076, 18625, 21696, 34036, 44452, 45495, 39558, 30780, 20830, 18965, 33538, 44508, 39086, 26508, 17831, 23749, 37574, 43088, 40204, 32690, 27179, 30360, 33555, 34255, 35294, 31717, 28188, 30345, 34166, 36236, 33182, 28938, 30048, 34728, 39346, 35963, 26953, 20289, 27051, 39592, 36115, 26597, 26083, 34110, 38392, 35238, 33320, 33672, 33145, 35523, 39941, 40728, 39653, 38573, 33900, 26260, 26544, 37562, 47480, 48416, 39872, 26869, 20768, 29068, 42590, 45434, 35335, 23356, 24300, 33633, 36406, 33076, 32787, 37075, 34120, 25615, 26498, 33506, 38536, 36131, 30558, 30380, 29254, 28203, 33646, 42472, 45737, 36100, 20503, 22734, 38866, 43666, 33859, 25865, 31280, 35617, 32497, 29620, 28436, 30496, 34087, 30321, 26072, 31145, 33601, 35491, 37157, 29275, 19271, 14748, 25355, 40043, 42262, 37260, 29955, 25221, 26474, 28348, 30162, 39582, 43823, 34964, 20985, 16655, 33615, 46083, 40628, 32172, 26387, 25585, 30524, 34582, 33349, 30189, 32548, 33361, 26331, 25632, 29075, 33517, 39866, 37882, 29773, 28285, 31116, 29676, 30462, 34349, 31788, 30035, 33080, 35615, 34356, 32790, 36467, 37673, 30454, 20147, 26305, 41824, 41730, 30321, 24419, 22809, 25435, 32936, 33910, 32109, 33400, 30770, 21432, 24593, 38836, 43728, 36556, 25466, 23234, 30806, 39949, 38792, 31977, 31587, 28577, 31185, 42895, 39766, 31039, 31755, 30425, 32504, 38302, 37145, 33824, 30625, 31127, 32823, 31495, 36861, 38291, 28864, 30105, 36999, 34506, 26249, 30019, 43341, 41861, 25909, 18290, 31160, 42090, 38728, 32330, 31848, 32681, 27788, 27807, 38178, 43861, 37013, 25033, 24968, 37335, 38187, 26336, 27314, 40136, 40608, 32021, 25693, 28911, 37926, 38163, 31695, 29320, 31686, 33778, 33159, 31945, 33258, 38532, 41971, 34500, 27607, 29538, 35786, 39861, 33083, 29720, 39688, 42680, 32766, 26690, 28371, 31686, 35569, 32865, 30243, 35042, 36813, 30981, 23966, 28734, 35692, 32836, 26581, 31970, 43366, 42038, 29065, 18474, 24462, 37500, 41598, 36638, 34735, 36215, 30825, 26790, 34073, 43232, 45163, 39022, 30040, 26219, 31616, 41927, 46466, 41357, 31319, 24411, 25314, 34727, 43261, 43204, 36163, 26583, 24712, 31021, 34143, 34508, 33989, 30461, 29205, 33985, 40255, 36613, 31666, 35995, 32586, 20261, 27547, 43793, 44774, 33861, 24907, 28767, 31233, 34495, 40455, 35230, 26633, 30200, 34108, 34075, 36613, 31103, 23539, 27735, 36158, 39000, 31310, 25614, 34837, 37698, 31614, 28127, 30100, 35785, 36876, 28204, 21602, 29169, 36366, 35308, 33652, 36330, 33167, 26146, 30815, 33788, 29631, 34690, 38580, 32620, 23280, 22281, 32431, 36467, 35659, 33973, 31085, 26572, 25209, 33101, 37057, 30295, 30427, 35880, 29982, 30341, 35938, 33857, 30522, 25946, 30594, 41694, 37960, 29112, 29868, 33074, 37815, 35811, 30769, 28675, 21243, 27407, 44618, 44812, 34132, 22680, 20989, 35865, 43248, 39409, 35817, 29342, 22103, 25510, 34203, 40706, 42956, 35999, 27419, 20512, 23833, 39260, 42822, 33760, 28182, 26894, 29440, 28632, 35310, 47465, 41969, 27470, 22943, 27214, 33149, 38613, 37142, 28028, 25583, 35010, 36148, 28934, 32465, 37406, 32437, 29100, 31919, 36464, 35790, 31069, 30688, 35002, 38205, 35259, 27678, 27884, 35582, 35429, 31825, 31337, 34933, 37804, 31057, 21673, 25789, 38066, 41170, 32850, 28416, 33210, 30709, 27612, 31285, 32067, 33262, 32150, 28085, 32384, 34727, 32319, 32365, 27996, 27451, 33509, 34390, 32721, 32942, 34159, 34656, 29349, 28042, 35448, 37262, 31365, 27911, 31717, 34712, 27135, 24212, 39903, 45562, 31308, 21594, 26632, 35902, 37150, 35169, 32820, 28092, 31765, 41914, 37716, 28580, 31344, 35646, 35273, 34647, 34531, 31525, 24540, 27383, 39564, 41408, 37129, 31708, 25562, 24990, 25031, 27164, 38281, 42866, 34139, 26139, 26748, 34821, 35431, 31286, 36711, 37035, 28745, 26723, 29353, 33622, 34116, 30175, 32481, 33522, 30557, 34707, 36858, 31520, 26030, 27349, 34691, 34465, 32016, 35978, 34903, 26278, 29078, 40964, 41169, 34239, 32288, 29403, 27546, 34926, 39962, 38433, 37034, 35416, 30423, 31542, 37852, 36167, 32038, 35776, 39464, 36518, 33121, 28665, 32322, 43349, 43643, 33049, 24892, 29055, 39337, 40284, 32751, 31838, 34082, 30321, 32182, 37865, 37626, 34121, 27897, 26694, 35202, 40465, 37125, 29991, 25253, 31616, 36465, 32034, 31376, 38342, 41776, 33957, 22497, 25156, 36807, 38063, 35544, 33379, 30352, 25787, 27400, 37677, 39693, 31044, 26339, 31191, 34696, 32309, 31666, 33631, 32986, 31840, 32199, 32357, 32714, 35321, 34695, 29835, 31047, 30467, 23540, 29510, 41068, 38489, 29944, 30576, 36294, 32109, 26623, 31795, 35271, 33139, 33535, 34179, 32066, 30579, 30667, 32749, 37433, 36406, 29567, 27755, 32516, 36955, 37111, 36273, 35849, 28617, 24113, 34566, 40937, 37269, 33149, 27033, 24574, 31969, 37884, 32160, 25820, 31953, 37829, 34148, 34309, 35850, 28461, 24251, 29533, 36347, 39910, 36982, 31500, 29516, 32420, 35561, 32895, 28861, 31952, 34141, 32055, 34205, 37332, 36446, 34320, 33461, 29165, 25740, 33029, 41498, 39602, 32272, 30338, 32187, 27916, 26871, 37893, 44092, 38754, 28357, 22936, 31990, 39529, 34777, 29928, 30432, 32601, 35894, 32097, 28776, 35305, 36030, 30717, 28928, 32359, 32842, 28185, 31119, 38912, 37344, 28905, 24520, 28361, 35762, 36292, 31098, 29125, 29207, 34400, 40381, 36066, 27818, 26186, 31399, 33482, 33326, 36158, 37106, 28988, 24275, 31851, 34354, 32485, 34082, 33584, 29849, 30910, 34755, 34023, 31959, 30421, 28928, 31339, 34864, 33588, 32626, 34352, 32395, 30426, 34167, 35929, 31013, 25507, 29761, 36742, 34790, 31993, 29486, 24310, 30543, 38600, 33001, 30914, 35273, 34350, 29926, 26386, 29013, 36686, 39188, 37325, 31036, 23984, 27374, 33292, 35343, 35513, 32391, 29061, 28437, 30464, 35185, 39375, 36407, 31639, 30294, 30444, 33913, 35001, 32848, 33903, 33540, 31980, 33106, 36851, 38354, 33664, 26621, 24549, 33119, 38293, 35304, 30525, 27308, 29150, 33055, 35401, 33698, 34058, 34892, 30721, 25322, 29744, 40063, 39559, 34268, 32489, 30694, 30403, 32433, 34501, 35814, 32660, 31292, 36769, 37722, 34443, 32760, 30723, 32400, 38048, 36721, 27989, 29071, 37894, 39496, 33523, 30586, 31090, 29870, 32628, 36503, 33183, 27084, 27554, 33146, 38923, 38705, 32661, 29492, 27496, 26758, 35022, 41979, 38429, 30051, 23440, 28631, 38113, 37523, 30653, 27665, 27860, 30522, 37132, 38549, 30860, 23288, 28087, 37488, 38325, 34376, 30889, 28423, 28969, 32376, 34725, 34723, 34312, 34258, 30996, 27506, 32851, 38469, 34418, 29489, 29534, 31389, 31463, 32434, 37611, 38981, 32217, 28916, 33858, 37065, 34182, 31839, 31386, 32686, 36842, 38444, 35918, 32290, 26942, 25361, 33172, 38192, 33452, 29277, 29746, 32363, 35790, 34423, 31007, 31476, 34626, 39366, 39627, 31599, 27289, 29298, 33485, 38172, 36335, 33860, 33357, 32699, 34453, 33477, 29119, 30713, 35361, 35513, 35010, 36280, 34207, 26687, 26217, 34477, 38775, 38512, 35006, 29147, 28565, 32552, 33030, 32872, 34501, 34518, 32429, 30155, 31886, 35386, 35489, 30827, 28081, 29579, 28961, 32141, 37634, 35088, 32000, 33902, 31959, 29408, 31978, 34212, 34688, 32199, 29685, 32083, 33860, 34130, 34041, 30937, 30151, 36443, 40227, 36435, 29567, 26323, 34042, 36473, 30080, 29744, 34527, 38877, 36284, 31360, 31835, 33668, 31838, 28596, 31021, 34575, 34609, 34881, 33341, 28004, 27855, 33823, 34690, 35224, 37774, 34372, 28210, 25171, 27304, 36314, 42666, 37848, 28470, 27913, 32921, 32744, 32692, 35920, 36653, 29466, 26802, 34319, 36544, 34493, 33857, 32321, 32366, 30330, 28257, 32367, 33907, 31860, 33429, 34835, 33938, 33593, 33279, 31336, 28621, 31110, 34704, 32917, 29020, 32531, 38298, 35575, 26861, 24644, 34034, 36471, 32033, 28680, 29331, 35629, 37362, 31595, 27235, 27666, 30299, 33846, 33483, 30112, 30677, 32710, 31923, 31997, 33483, 31679, 27605, 30021, 34588, 33724, 33347, 33800, 33059, 32745, 30703, 30434, 34685, 36593, 36921, 37581, 35346, 29710, 26626, 33219, 37001, 35091, 35964, 35673, 30483, 27422, 33425, 38025, 33871, 25458, 25215, 34227, 39765, 38925, 32316, 27030, 27941, 30121, 35943, 39643, 35110, 30246, 27404, 29457, 36323, 36881, 33739, 33968, 31940, 29097, 29239, 29144, 31052, 35870, 38535, 34355, 26883, 30083, 35964, 32043, 30351, 33552, 34010, 34655, 35305, 33725, 31137, 29945, 33722, 35518, 33697, 33282, 31096, 29588, 33903, 37105, 35381, 33342, 31686, 29466, 30655, 35471, 37541, 34556, 30082, 31088, 33517, 31692, 32154, 35862, 36089, 30699, 25329, 28369, 36040, 38975, 35788, 31689, 28729, 27346, 34273, 39709, 37718, 32517, 28458, 31585, 34439, 35797, 36297, 33181, 29904, 29796, 31876, 33040, 32903, 33382, 34905, 33459, 27576, 27511, 33501, 35924, 33790, 31121, 30946, 31902, 35579, 38442, 32633, 26247, 31172, 35610, 35566, 37488, 36734, 31977, 28375, 29062, 31396, 35635, 38914, 35640, 32284, 34583, 33369, 27091, 28876, 36597, 38633, 38113, 34035, 28448, 30017, 34348, 36306, 32249, 27531, 31121, 34918, 33179, 31658, 34187, 35053, 30616, 29951, 35195, 36668, 30597, 27158, 32605, 36993, 36080, 34645, 34847, 33614, 30490, 28639, 29705, 34813, 36272, 33711, 30510, 28396, 33248, 36030, 32556, 30789, 29997, 27955, 30901, 36934, 35678, 31293, 30184, 30917, 34281, 38846, 37643, 31022, 26340, 26968, 33261, 38310, 35636, 32631, 30469, 27367, 32492, 38429, 36183, 30026, 26895, 32300, 36083, 35449, 33740, 30798, 31023, 34445, 34466, 31421, 32726, 34108, 29689, 26002, 31857, 39267, 38478, 33997, 29902, 28891, 32673, 33805, 31753, 34032, 36394, 34021, 32979, 32265, 29053, 31447, 36331, 36186, 33997, 32249, 29806, 28771, 31565, 33170, 33430, 35373, 35441, 31614, 29491, 31936, 33528, 33784, 33131, 30944, 29534, 31978, 38391, 39848, 34020, 27710, 25336, 29780, 35810, 36871, 33282, 30009, 30772, 32936, 34132, 33575, 32091, 30947, 30210, 31890, 34971, 36450, 36040, 32520, 27307, 27108, 32144, 36384, 36466, 32051, 29078, 29477, 31351, 34186, 33703, 31924, 33235, 34297, 33208, 31131, 30840, 33345, 34157, 32998, 33477, 33022, 32367, 33847, 31723, 30824, 34608, 35244, 32528, 30761, 31766, 33225, 33345, 33679, 33200, 31647, 31189, 32087, 33276, 34208, 34553, 33676, 32303, 31712, 32256, 32784, 33537, 34859, 32913, 29546, 31403, 35214, 34781, 32184, 31157, 30960, 31077, 32633, 33280, 31694, 32491, 33137, 31407, 29593, 30030, 34276, 36167, 32839, 28502, 30420, 34399, 34179, 33706, 33715, 32657, 31596, 32118, 33840, 34267, 33015, 32716, 32588, 30920, 29885, 32155, 35114, 34520, 32751, 33762, 34341, 33198, 33185, 32564, 32610, 33367, 32418, 32490, 33420, 33936, 35144, 32899, 29123, 32731, 35791, 33016, 32016, 33213, 31587, 28689, 31084, 35753, 36983, 34547, 29262, 28297, 32340, 34544, 34479, 32328, 29219, 28912, 33182, 35662, 34573, 34239, 33708, 30359, 29283, 32452, 33329, 33254, 33717, 34581, 35937, 33647, 30227, 30854, 33124, 34585, 34709, 34010, 34719, 35050, 32478, 29967, 29893, 32574, 35144, 33597, 31807, 33169, 34201, 33629, 33484, 33270, 31874, 30913, 32218, 33990, 32903, 32758, 35401, 34925, 31729, 31864, 33806, 32797, 29860, 30387, 35255, 37596, 35728, 30247, 28895, 34113, 34255, 29517, 30993, 36998, 36505, 33319, 31555, 31173, 33803, 34560, 33256, 31529, 31468, 33100, 33137, 33031, 33517, 34733, 34492, 30733, 28463, 32135, 36191, 37071, 35723, 32271, 30473, 31639, 32868, 34506, 35867, 34209, 32235, 32712, 33955, 32250, 29631, 31208, 33355, 31413, 30501, 34411, 36459, 33255, 29996, 28788, 29600, 32342, 33760, 33935, 35031, 34874, 31689, 30703, 33905, 34980, 33481, 30963, 27914, 30182, 34970, 36270, 35127, 31778, 28130, 30026, 33700, 33588, 32453, 32338, 33087, 32833, 32356, 30767, 31904, 35550, 35014, 30343, 31025, 35841, 35936, 31660, 27316, 29854, 34519, 36313, 34654, 33451, 34162, 32148, 27989, 27912, 33681, 38358, 37157, 32421, 31157, 32777, 33422, 33932, 33042, 31583, 32580, 32831, 32149, 33092, 33767, 32970, 31883, 31239, 31609, 32989, 33222, 32868, 32926, 32964, 32937, 32921, 34524, 34653, 31157, 29522, 31804, 34247, 34464, 30892, 30195, 32932, 32565, 32194, 30403, 29546, 33664, 35996, 34045, 32042, 29431, 29481, 33727, 34453, 31468, 32512, 35147, 34167, 32622, 31789, 30040, 29745, 32907, 34374, 34563, 35240, 33701, 31198, 30976, 32091, 32106, 33073, 33739, 31510, 32425, 35190, 34020, 30960, 31062, 33699, 33098, 30541, 31128, 33022, 32223, 31787, 32802, 32278, 31258, 30849, 29440, 31468, 34965, 34330, 33633, 34131, 32468, 31131, 32232, 32447, 33260, 34500, 34500, 33880, 33427, 32478, 30415, 31832, 34863, 33490, 30247, 31523, 34274, 33282, 32342, 32125, 30241, 30078, 33847, 36528, 34459, 31498, 32092, 32942, 33126, 33738, 32105, 31260, 33727, 36105, 35341, 32273, 29889, 30726, 32593, 33404, 35426, 36039, 33831, 32699, 32579, 31848, 32445, 33848, 33704, 32809, 33105, 32902, 32280, 33472, 34256, 34140, 33759, 32578, 31526, 31689, 32170, 34422, 37488, 36574, 32035, 30830, 33704, 33699, 31939, 33250, 34597, 31751, 29269, 31459, 33794, 34939, 37064, 36017, 31184, 28967, 31038, 32131, 32770, 34424, 33530, 31051, 31508, 34160, 34920, 33499, 32646, 32251, 30929, 31834, 33069, 32673, 33890, 33733, 32161, 32792, 32935, 31507, 31554, 33956, 33896, 30957, 31929, 34804, 32323, 30930, 35158, 35230, 31341, 30899, 32618, 32533, 32180, 32320, 31691, 32833, 35096, 34174, 31518, 31462, 32442, 33669, 35185, 34423, 31090, 29868, 32125, 33854, 34896, 34853, 34034, 32335, 30093, 30706, 33497, 35055, 34329, 32656, 31771, 32062, 32053, 31439, 33092, 35432, 33942, 30450, 30461, 32892, 32794, 33401, 35495, 34265, 31364, 30459, 30703, 32167, 34690, 34150, 31191, 31878, 34828, 34186, 30816, 29619, 31304, 32679, 33103, 32646, 32668, 33163, 31351, 30938, 33222, 33331, 32329, 32158, 33025, 33657, 32508, 31673, 32380, 33465, 34476, 34928, 33723, 31708, 31029, 33365, 34863, 33466, 32946, 32691, 32113, 33058, 33794, 33406, 33019, 32918, 32162, 31610, 33549, 34527, 33132, 33266, 33405, 31505, 31303, 32348, 32722, 32562, 32556, 33739, 33528, 31236, 31277, 33705, 33503, 32510, 32509, 30865, 29946, 33174, 36062, 34196, 30789, 30278, 32472, 33135, 31735, 31734, 33002, 34131, 34242, 31625, 29294, 31331, 34017, 34240, 33783, 31373, 30894, 33997, 34057, 31791, 31079, 31696, 32269, 33139, 34542, 34001, 31642, 31399, 32752, 32739, 32379, 32652, 32451, 32641, 33551, 33681, 32239, 30716, 31820, 32970, 32201, 33050, 34123, 33613, 33427, 32496, 31638, 32359, 32035, 31776, 34304, 35430, 33951, 32093, 31496, 32928, 33865, 33528, 32775, 31275, 30634, 32835, 35100, 34301, 32583, 33203, 33806, 32982, 31609, 31423, 33031, 34307, 33231, 30146, 30952, 35321, 35829, 32625, 32449, 33964, 32895, 31229, 30989, 32462, 33785, 33607, 32891, 33844, 35439, 34736, 31016, 29988, 32855, 32565, 31643, 32851, 33059, 32601, 33151, 33109, 32681, 33031, 32660, 30235, 29130, 32257, 35062, 34142, 32876, 33741, 33265, 31726, 31784, 32882, 33945, 33865, 33283, 33277, 32615, 31861, 32766, 33296, 31988, 30976, 32457, 34510, 34380, 32959, 31482, 30967, 31233, 31834, 33893, 35001, 34197, 33646, 32289, 31647, 32673, 32612, 32439, 33077, 33450, 34084, 34484, 33579, 32237, 31291, 31533, 32951, 33897, 33928, 33780, 32941, 32903, 34139, 32631, 30387, 31299, 32870, 33964, 34687, 34609, 33503, 31621, 31068, 32047, 33177, 33353, 31905, 30585, 32999, 35583, 34795, 32422, 30138, 31447, 33429, 33382, 32917, 32635, 32716, 32313, 32292, 32813, 33003, 32807, 32613, 32309, 31868, 32255, 32096, 32366, 34008, 33300, 31585, 31587, 31560, 32526, 33838, 33318, 33121, 33357, 32584, 30945, 31060, 33019, 34083, 33829, 32675, 32358, 32775, 32159, 32243, 33332, 32948, 31894, 32776, 34083, 33047, 30965, 31107, 32835, 33376, 32268, 31474, 32804, 34266, 33243, 31122, 31778, 33403, 32699, 31571, 32351, 33324, 33721, 34380, 33490, 32167, 32805, 33644, 33864, 34427, 34203, 33422, 32283, 31982, 34106, 35679, 34816, 32286, 30028, 31843, 35270, 35479, 33582, 30781, 30002, 31861, 33752, 34890, 33857, 32498, 32861, 33110, 32966, 33070, 31867, 31003, 32955, 35123, 35308, 33807, 31661, 31029, 31689, 32244, 32949, 32907, 32862, 33297, 31893, 30729, 32446, 33695, 32274, 30777, 31194, 32458, 32470, 32097, 32483, 32510, 33213, 33744, 32510, 31492, 32088, 32684, 32499, 32299, 32727, 33702, 33244, 32248, 32783, 33289, 33392, 32626, 31135, 33068, 35234, 33086, 30972, 33303, 34850, 32004, 31673, 34416, 33802, 31594, 32123, 32711, 32771, 33589, 33708, 33239, 32589, 31886, 32992, 33853, 32409, 31710, 32313, 33222, 34471, 34729, 33970, 32740, 31006, 31951, 34502, 33886, 31784, 31659, 32628, 33300, 34006, 34082, 32416, 30459, 30616, 32277, 34051, 34128, 31642, 30568, 32452, 33794, 33113, 32030, 32587, 33495, 32878, 32558, 32976, 32769, 33068, 33469, 32643, 31339, 31333, 33280, 34524, 33562, 31740, 30978, 31592, 32683, 33325, 32768, 31838, 31736, 32127, 32615, 32764, 32518, 31904, 31043, 31666, 32961, 32941, 32224, 32618, 33356, 33667, 33776, 32383, 31275, 32153, 33913, 34305, 32407, 31897, 33355, 33683, 32831, 32378, 32822, 33562, 33431, 32448, 31828, 32529, 33905, 34201, 32992, 31477, 31897, 32699, 32178, 31942, 33428, 35050, 34683, 32705, 30919, 31848, 33152, 32768, 32700, 32567, 32459, 33788, 34287, 33577, 33029, 32056, 30603, 30940, 33002, 33657, 34169, 34789, 33779, 31634, 30723, 32388, 33803, 33444, 32079, 31768, 33824, 34354, 32553, 32120, 32876, 32435, 32206, 33528, 33886, 33100, 32297, 31708, 32589, 34129, 34065, 33161, 32594, 31919, 32433, 33632, 33251, 32218, 32662, 33708, 33176, 32022, 31808, 33449, 34805, 33454, 30309, 30405, 33387, 33601, 32996, 33601, 33722, 32947, 32797, 32734, 32167, 32188, 33024, 33327, 32410, 32331, 33634, 34365, 33837, 32937, 32261, 31436, 31019, 32046, 33151, 33309, 32881, 32043, 31849, 32386, 32805, 33125, 32739, 31765, 32151, 33248, 32689, 32409, 33663, 33772, 32846, 33113, 33485, 32771, 31386, 32028, 33968, 33681, 32079, 31565, 33062, 34073, 33793, 32245, 31645, 33500, 34142, 31962, 30546, 31957, 32922, 32956, 33649, 34246, 33412, 31764, 30832, 31302, 32710, 33279, 32944, 33403, 33972, 33179, 32064, 31972, 32073, 32043, 33024, 34405, 34168, 32596, 31253, 31597, 32906, 33617, 33844, 32821, 30645, 30798, 33787, 34686, 32673, 31117, 31606, 32471, 33233, 33710, 33317, 33294, 33180, 31676, 31632, 33703, 34220, 33825, 33270, 32025, 31740, 33246, 33801, 32505, 32185, 33025, 33338, 33216, 33203, 33417, 33249, 32019, 32139, 33419, 32981, 32254, 32541, 33043, 33557, 33772, 33201, 31492, 30907, 32677, 34075, 33581, 32126, 31934, 32872, 33051, 32641, 33003, 33126, 32063, 31853, 33317, 34052, 33176, 32358, 31974, 31969, 32656, 33489, 32874, 31835, 32327, 33282, 32925, 32155, 32261, 32289, 31718, 31837, 32740, 33141, 33265, 33359, 32733, 31481, 31842, 33339, 33437, 32210, 31879, 33191, 33156, 31998, 32532, 32929, 32556, 33058, 33104, 31782, 31835, 33557, 33120, 31939, 32162, 32480, 33282, 34010, 33172, 32596, 33030, 32440, 32254, 32969, 32655, 32288, 33536, 33923, 32710, 32963, 33365, 32483, 31669, 32753, 33631, 32560, 32614, 33782, 33698, 32400, 32174, 33252, 33109, 32563, 33836, 34186, 32518, 31410, 31841, 33053, 34176, 34140, 32484, 32309, 33838, 33588, 32308, 32307, 32749, 32218, 31417, 32432, 34059, 34003, 33436, 32665, 32178, 32303, 31696, 31128, 31881, 33106, 33969, 33926, 32917, 31421, 30410, 31813, 33451, 33265, 32894, 32491, 31886, 32505, 33640, 33722, 33182, 32653, 32527, 32370, 31965, 31748, 32971, 34352, 33757, 32443, 31334, 31360, 33145, 34382, 34094, 33215, 32007, 31478, 32211, 33244, 33546, 33225, 33235, 33451, 32966, 32300, 32477, 32427, 32378, 33373, 33738, 32848, 32884, 33694, 33039, 32419, 32858, 32610, 31932, 32944, 34109, 32892, 31787, 33055, 34174, 33683, 32381, 31540, 32601, 33687, 33246, 32029, 31588, 32563, 33140, 32981, 33438, 33454, 32101, 31661, 32734, 33085, 32860, 32838, 32985, 33407, 33256, 32586, 32459, 32971, 32759, 32272, 33200, 33749, 32679, 32109, 32350, 32563, 33219, 32991, 32304, 32997, 33184, 32693, 32650, 32586, 32486, 33011, 34191, 34028, 32730, 32006, 31785, 32384, 33623, 34033, 33258, 32271, 32074, 32595, 32802, 33055, 33739, 33201, 31703, 32255, 33698, 33128, 31940, 32367, 33227, 32753, 32100, 32122, 32319, 32797, 33229, 32890, 32260, 31966, 32246, 32816, 33061, 32969, 32749, 32077, 31880, 32678, 32660, 32336, 33269, 33629, 32599, 32337, 32558, 32253, 32394, 32778, 32731, 32710, 33087, 33295, 32211, 31194, 32204, 33121, 33161, 33261, 32569, 32200, 32944, 33019, 32237, 32167, 32914, 33108, 32929, 33168, 33008, 31931, 31991, 33425, 33768, 33502, 33069, 32421, 32482, 32711, 32766, 33032, 33157, 32828, 32717, 32779, 32869, 32824, 32404, 32776, 33388, 32322, 31692, 33104, 33812, 33407, 32767, 32279, 32064, 32087, 32817, 33293, 32797, 32225, 32357, 32716, 33162, 33565, 32990, 31795, 31778, 32639, 33182, 33569, 33214, 32508, 32201, 32196, 32800, 33488, 33365, 32895, 32614, 32304, 31646, 31595, 32966, 33395, 33071, 33336, 33234, 32228, 31537, 32750, 33890, 32822, 31233, 32063, 33777, 33470, 31929, 32032, 33326, 33738, 33145, 32802, 32915, 31956, 31652, 32555, 33181, 33373, 33419, 33442, 32923, 32259, 32321, 32731, 33143, 33476, 33166, 32661, 32103, 31884, 32814, 33686, 33376, 32697, 32392, 32251, 32578, 33151, 33140, 32481, 32220, 32461, 32903, 33465, 33652, 33261, 31987, 31832, 33180, 33291, 32523, 32627, 32903, 32818, 32747, 32752, 33025, 32996, 32622, 32573, 32645, 32547, 32869, 33285, 33266, 33129, 32183, 31666, 32631, 33193, 32885, 32783, 32819, 32322, 32109, 32787, 33217, 32668, 32444, 33048, 33105, 32945, 32657, 31828, 32192, 33369, 33542, 33068, 32806, 32795, 32664, 32567, 32937, 33029, 32847, 33399, 33549, 32652, 32445, 32839, 32543, 32475, 33002, 33212, 33196, 33079, 32657, 32367, 32602, 33077, 33358, 33096, 32662, 32536, 32531, 32847, 33407, 33119, 32411, 32796, 33635, 33089, 32094, 32751, 33611, 33161, 32623, 32621, 32479, 32455, 32929, 33462, 33349, 32440, 31909, 32261, 32738, 33336, 33685, 32883, 32169, 32267, 32517, 32594, 32727, 32845, 32373, 32466, 32971, 32668, 32401, 32350, 32517, 33254, 33299, 32437, 32391, 32865, 32709, 32560, 32917, 33234, 32950, 32581, 32506, 32647, 32860, 32410, 32235, 33034, 33318, 32810, 32745, 32776, 32245, 32190, 32909, 33478, 33131, 32271, 32402, 33204, 33629, 33236, 32256, 32321, 33296, 33171, 32281, 32396, 32831, 32669, 32753, 33311, 33040, 32535, 32915, 33044, 32400, 32200, 32545, 32612, 32833, 33148, 33026, 32791, 32817, 32762, 32366, 32023, 32273, 32990, 33461, 33505, 32964, 31930, 31728, 32468, 33201, 33631, 33022, 32074, 32143, 32597, 32843, 32913, 33071, 33230, 33144, 32656, 32220, 32501, 32834, 32874, 33018, 32646, 31845, 32153, 33042, 33576, 33565, 33022, 32381, 31991, 32281, 32910, 33053, 33061, 33347, 33432, 33402, 32765, 31967, 32285, 32911, 32913, 32667, 33019, 33487, 32880, 32339, 33001, 33354, 32777, 32145, 31955, 32396, 33220, 33404, 32580, 32412, 32784, 32420, 32206, 32831, 33205, 32662, 32177, 32651, 32759, 32155, 32349, 32902, 32903, 32544, 32870, 33107, 32457, 32300, 32618, 32505, 32433, 32852, 32823, 32746, 33106, 32943, 32452, 32359, 32314, 32591, 33171, 32732, 32265, 32760, 33054, 32797, 32773, 32801, 32472, 32807, 33251, 32718, 32438, 32955, 33208, 32689, 32281, 32762, 33223, 33185, 32989, 32792, 32497, 32389, 32694, 32838, 32771, 32985, 33276, 33023, 32588, 32720, 33146, 33027, 32664, 32608, 32771, 33018, 33349, 33277, 32611, 32360, 32780, 32971, 32794, 32848, 32930, 32628, 32438, 32885, 33306, 32969, 32178, 32107, 32881, 33347, 33212, 32867, 32625, 32490, 32605, 32958, 32778, 32478, 32853, 33072, 32913, 32792, 32782, 32775, 32545, 32420, 32856, 33065, 32549, 32367, 32787, 33081, 33085, 33011, 32399, 32092, 32730, 33033, 32868, 32885, 32824, 32566, 32383, 32209, 32532, 33282, 33437, 32476, 31945, 32623, 33248, 33241, 32976, 32629, 32401, 32733, 33263, 33467, 33023, 32478, 32451, 32623, 32732, 33023, 33346, 33155, 32708, 32654, 32727, 32480, 32339, 32628, 33138, 33435, 33195, 32772, 32667, 32613, 32254, 32459, 33280, 33448, 32735, 32475, 32995, 33244, 33005, 32472, 32415, 32895, 33206, 32801, 32335, 32668, 33060, 33025, 32752, 32845, 33026, 32677, 32488, 32771, 32683, 32429, 32652, 32890, 32819, 32670, 32565, 32581, 32816, 32960, 32906, 32678, 32362, 32460, 32848, 33084, 33216, 33276, 33059, 32609, 32440, 32722, 32866, 32685, 32594, 32719, 32836, 32824, 32954, 32950, 32667, 32609, 32829, 32373, 32004, 32732, 33373, 33150, 32502, 32362, 32675, 32998, 32882, 32570, 32669, 32893, 32747, 32512, 32644, 32794, 32928, 33035, 32738, 32386, 32491, 32743, 32911, 32904, 32578, 32485, 32735, 32702, 32597, 32919, 33092, 32591, 32371, 32704, 32934, 32776, 32372, 32454, 32981, 33298, 33092, 32706, 32602, 32347, 32225, 32636, 32992, 33062, 33074, 33005, 32651, 32547, 32690, 32690, 32811, 32760, 32481, 32687, 33161, 33303, 32932, 32452, 32422, 32666, 32709, 32573, 32800, 33104, 33055, 32736, 32516, 32616, 32859, 32992, 32846, 32662, 32669, 32869, 32962, 32678, 32510, 32879, 33057, 32722, 32430, 32520, 32912, 33031, 32876, 32694, 32541, 32678, 32803, 32626, 32423, 32586, 32843, 32927, 32895, 32749, 32672, 32708, 32845, 32983, 32917, 32738, 32628, 32674, 32964, 33231, 33077, 32619, 32481, 32750, 33016, 32985, 32789, 32803, 32784, 32741, 32886, 32826, 32585, 32660, 32883, 32808, 32462, 32428, 32887, 33084, 32761, 32425, 32357, 32678, 33092, 33123, 32879, 32706, 32577, 32529, 32804, 33107, 32822, 32437, 32655, 32950, 33027, 32957, 32725, 32552, 32483, 32522, 32797, 32856, 32605, 32637, 32791, 32839, 32825, 32679, 32619, 32649, 32546, 32757, 33094, 32770, 32441, 32870, 33015, 32556, 32583, 33034, 32960, 32477, 32555, 32832, 32875, 32828, 32696, 32742, 32897, 32796, 32651, 32670, 32752, 32783, 32698, 32758, 32953, 32942, 32776, 32755, 32723, 32727, 32829, 32750, 32625, 32750, 33032, 33026, 32702, 32688, 32982, 33010, 32908, 32905, 32815, 32764, 32744, 32768, 33002, 33215, 33181, 32879, 32504, 32515, 32818, 32906, 32886, 32868, 32739, 32758, 32945, 32878, 32637, 32412, 32444, 32838, 33127, 33132, 32742, 32344, 32541, 32952, 33140, 32965, 32589, 32518, 32727, 32857, 32904, 32803, 32702, 32649, 32553, 32661, 32858, 32795, 32670, 32598, 32507, 32617, 32810, 32722, 32535, 32712, 32968, 32871, 32618, 32610, 32813, 32872, 32708, 32591, 32789, 33025, 32941, 32730, 32755, 32876, 32801, 32731, 32836, 32847, 32805, 32895, 32934, 32838, 32633, 32549, 32767, 32952, 32915, 32817, 32844, 32793, 32643, 32669, 32704, 32818, 32966, 32805, 32676, 32747, 32726, 32750, 32815, 32812, 32806, 32806, 32772, 32734, 32778, 32777, 32782, 32819, 32834, 32708, 32516, 32686, 32978, 33075, 32866, 32493, 32517, 32747, 32827, 32764, 32662, 32652, 32812, 32946, 32936, 32822, 32673, 32575, 32498, 32646, 32921, 32877, 32740, 32771, 32795, 32785, 32720, 32583, 32559, 32691, 32829, 32910, 32857, 32732, 32681, 32651, 32657, 32720, 32671, 32670, 32835, 32879, 32870, 32788, 32587, 32547, 32608, 32659, 32785, 32906, 32933, 32780, 32588, 32622, 32795, 32845, 32757, 32763, 32836, 32825, 32845, 32873, 32784, 32678, 32661, 32774, 32895, 32815, 32781, 32884, 32771, 32483, 32496, 32778, 32915, 32865, 32825, 32829, 32778, 32788, 32813, 32727, 32715, 32847, 32726, 32648, 32932, 33082, 32926, 32742, 32743, 32794, 32741, 32641, 32646, 32774, 32921, 32860, 32711, 32853, 32979, 32696, 32473, 32692, 32904, 32859, 32686, 32634, 32758, 32873, 32863, 32747, 32773, 32889, 32795, 32595, 32601, 32754, 32836, 32856, 32803, 32694, 32701, 32822, 32916, 32884, 32680, 32621, 32717, 32721, 32751, 32828, 32828, 32831, 32790, 32685, 32727, 32750, 32660, 32712, 32847, 32877, 32798, 32739, 32751, 32750, 32769, 32816, 32766, 32710, 32818, 32906, 32822, 32736, 32705, 32684, 32715, 32847, 32925, 32749, 32653, 32811, 32880, 32849, 32734, 32589, 32663, 32866, 32926, 32834, 32727, 32673, 32753, 32821, 32725, 32673, 32808, 32970, 32883, 32635, 32610, 32760, 32811, 32812, 32853, 32764, 32681, 32776, 32839, 32779, 32750, 32760, 32749, 32723, 32701, 32797, 32855, 32796, 32816, 32809, 32697, 32686, 32757, 32774, 32777, 32801, 32789, 32723, 32716, 32752, 32752, 32803, 32805, 32687, 32680, 32769, 32833, 32814, 32749, 32705, 32680, 32706, 32773, 32780, 32733, 32713, 32747, 32788, 32731, 32684, 32774, 32796, 32768, 32779, 32776, 32744, 32695, 32705, 32831, 32920, 32824, 32714, 32775, 32857, 32796, 32720, 32712, 32749, 32836, 32905, 32832, 32741, 32760, 32734, 32701, 32794, 32882, 32825, 32722, 32723, 32756, 32766, 32779, 32812, 32832, 32802, 32721, 32677, 32742, 32822, 32839, 32823, 32779, 32729, 32680, 32697, 32800, 32851, 32799, 32737, 32723, 32718, 32770, 32833, 32787, 32716, 32716, 32737, 32758, 32783, 32754, 32728, 32797, 32860, 32755, 32705, 32799, 32787, 32715, 32758, 32810, 32765, 32732, 32762, 32787, 32767, 32777, 32800, 32765, 32758, 32760, 32733, 32759, 32782, 32786, 32811, 32810, 32753, 32716, 32754, 32798, 32778, 32748, 32748, 32726, 32740, 32828, 32872, 32815, 32756, 32730, 32694, 32727, 32803, 32809, 32757, 32761, 32793, 32758, 32740, 32810, 32850, 32788, 32722, 32720, 32736, 32753, 32777, 32783, 32779, 32766, 32743, 32751, 32767, 32758, 32766, 32777, 32760, 32741, 32760, 32776, 32777, 32797, 32799, 32757, 32736, 32737, 32728, 32754, 32796, 32818, 32787, 32740, 32731, 32765, 32778, 32773, 32772, 32754, 32767, 32804, 32789, 32736, 32726, 32758, 32774, 32774, 32790, 32774, 32741, 32765, 32801, 32782, 32748, 32763, 32789, 32790, 32787, 32784, 32772, 32758, 32759, 32758, 32764, 32785, 32784, 32773, 32779, 32757, 32727, 32746, 32763, 32769, 32779, 32774, 32765, 32772, 32766, 32756, 32774, 32790, 32774, 32759, 32774, 32794, 32778, 32753, 32768, 32776, 32764, 32763, 32761, 32760, 32773, 32788, 32782, 32771, 32763, 32745, 32742, 32762, 32775, 32781, 32783, 32770, 32751, 32763, 32776, 32754, 32742, 32763, 32776, 32787, 32781, 32751, 32742, 32761, 32770, 32775, 32766, 32756, 32775, 32783, 32769, 32757, 32758, 32776, 32784, 32774, 32768, 32768, 32767, 32766, 32768, 32769, 32764, 32761, 32763, 32769, 32773, 32773, 32767, 32766, 32768, 32764, 32766, 32773, 32770, 32769, 32766, 32763, 32775, 32784, 32771, 32750, 32744, 32762, 32777, 32775, 32772, 32775, 32773, 32759, 32750, 32760, 32777, 32782, 32769, 32758, 32768, 32778, 32770, 32761, 32765, 32770, 32771, 32769, 32768, 32768, 32771, 32767, 32760, 32767, 32775, 32777, 32773, 32765, 32759, 32764, 32772, 32775, 32774, 32767, 32767, 32770, 32773, 32771, 32769, 32767, 32764, 32763, 32766, 32771, 32774, 32774, 32767, 32765, 32768, 32769, 32766, 32767, 32772, 32771, 32769, 32769, 32771, 32770, 32768, 32767, 32767, 32767, 32770, 32771, 32770, 32768, 32764, 32765, 32768, 32770, 32768, 32768, 32767, 32767, 32767, 32767, 32768, 32769, 32769, 32767, 32768, 32768, 32769, 32770, 32768, 32766, 32768, 32768, 32767, 32767, 32768, 32770, 32768, 32767, 32766, 32767, 32768, 32769, 32767, 32768, 32769, 32768, 32768, 32767, 32767, 32768, 32768, 32768, 32767, 32767, 32768, 32767, 32768, 32768, 32768, 32768, 32767, 32768};
