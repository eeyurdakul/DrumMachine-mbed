const uint8_t kNumChannels = 1;
const uint8_t kBitsPerSample = 16;
const uint32_t kSampleRate = 44100;
const uint32_t kSampleSize = 4410;
const float kAudioTime = 0.10000;

const uint16_t audioSample[4410] = {32768, 40750, 43455, 65, 19648, 51750, 40431, 41064, 41249, 43655, 43720, 48306, 50814, 35395, 31159, 24837, 26747, 26341, 43883, 49050, 51758, 47182, 40085, 36225, 31536, 25184, 28078, 40131, 32907, 33263, 9375, 18761, 48232, 42356, 44988, 13399, 12477, 27756, 31970, 42739, 24312, 22211, 19092, 27623, 40098, 31793, 29301, 27497, 25273, 21432, 23236, 24517, 33394, 37276, 43421, 42317, 41740, 44815, 43457, 31018, 34497, 34324, 44929, 46369, 39183, 33043, 21459, 24253, 22907, 33889, 35142, 46535, 25929, 14100, 25282, 29749, 47003, 40210, 37730, 34365, 33513, 29026, 32576, 35287, 39231, 40001, 34398, 29364, 16419, 29660, 34385, 34051, 31299, 19762, 28835, 33396, 36324, 36205, 31043, 33047, 34554, 33563, 33173, 26851, 31909, 39093, 33251, 31321, 40101, 31550, 10761, 23972, 28096, 36482, 34869, 26255, 28460, 28617, 31555, 33841, 45115, 38232, 31116, 34174, 32104, 15909, 20754, 29588, 26942, 27610, 20441, 20091, 13589, 26361, 33336, 38055, 37174, 28434, 26334, 19851, 39388, 42885, 46336, 42208, 38796, 29164, 25897, 45007, 43770, 48823, 32558, 25350, 26680, 28993, 37856, 35897, 37100, 29287, 29159, 30965, 30871, 30046, 34798, 35547, 33736, 31120, 25102, 32861, 34599, 35517, 33115, 28414, 30607, 31355, 20544, 20512, 21404, 28670, 36406, 29541, 31098, 34894, 32056, 25122, 40173, 42731, 45583, 36080, 19452, 27148, 27559, 38042, 37543, 42146, 29285, 22253, 15702, 18251, 34171, 34159, 40799, 19689, 19675, 30507, 35824, 44371, 38998, 37909, 23176, 27899, 34172, 35124, 35924, 32798, 31984, 32229, 29295, 27865, 28804, 31453, 37970, 40762, 45169, 35672, 33918, 40260, 37513, 37821, 24771, 19991, 27585, 28280, 29750, 37599, 44053, 17334, 19915, 28256, 32972, 38467, 33666, 31763, 18911, 20946, 15450, 44818, 50386, 35226, 31888, 24789, 20783, 17716, 50132, 49134, 54713, 32285, 18598, 27527, 27372, 29634, 33645, 40390, 30932, 30481, 24119, 31342, 37840, 40121, 40294, 24397, 26172, 26871, 30156, 31455, 41753, 36431, 17862, 29233, 34142, 36156, 36457, 33930, 35284, 36046, 36328, 37269, 41779, 43139, 48601, 32098, 26777, 39388, 38505, 40863, 32494, 27881, 27648, 26661, 27856, 26521, 26951, 27108, 30682, 41656, 39868, 38540, 35336, 33074, 33066, 33208, 39106, 23841, 19269, 21637, 27286, 40019, 35038, 33639, 46032, 44142, 32673, 32993, 30152, 31609, 32060, 47107, 34793, 22391, 25182, 24786, 30970, 29125, 27244, 25384, 24141, 31553, 33057, 41742, 29595, 23866, 20456, 24393, 39685, 38934, 39497, 46800, 46054, 28016, 26127, 16477, 37113, 42598, 39027, 36550, 30410, 35110, 36932, 20916, 27914, 58691, 35412, 21803, 25528, 25169, 31031, 28323, 28294, 26609, 28158, 29167, 34438, 40247, 41385, 41549, 30682, 30807, 34093, 31107, 31106, 18673, 21494, 29108, 36745, 45188, 38331, 37883, 35874, 34506, 31551, 36119, 36631, 26116, 30729, 36205, 38589, 39712, 36464, 33727, 28726, 31256, 34074, 14001, 13794, 13100, 28536, 43182, 46901, 46829, 15968, 26282, 33867, 30896, 29633, 39865, 33638, 23045, 27712, 29399, 33099, 34123, 32661, 38002, 41965, 34508, 33589, 35628, 33598, 32776, 28152, 26768, 24138, 27578, 31636, 37239, 40117, 23684, 26230, 29434, 32350, 34607, 34431, 34994, 35876, 29709, 21133, 42375, 45093, 59400, 34640, 3828, 27321, 30470, 40296, 36108, 32424, 28739, 27059, 36716, 35525, 31067, 35375, 38165, 30573, 30259, 30226, 32221, 33769, 33868, 34045, 37139, 31344, 21854, 34396, 37866, 39380, 38850, 36993, 39732, 41140, 28592, 31710, 43442, 36821, 33247, 28416, 28421, 42051, 33461, 30851, 14132, 11683, 15242, 27096, 45740, 40927, 42482, 34628, 33770, 27251, 33850, 35291, 31052, 27933, 20770, 25803, 30201, 25214, 27224, 36859, 34517, 32634, 31456, 31820, 45498, 40160, 33377, 31176, 28721, 30314, 30273, 32912, 31341, 31906, 28160, 31213, 42467, 38048, 35526, 32704, 30670, 25644, 27621, 29793, 32693, 34582, 32713, 33273, 30679, 42372, 48577, 23492, 24912, 23871, 40674, 53762, 37713, 35413, 26347, 32328, 37315, 26962, 25278, 37804, 31829, 26091, 23680, 22489, 34597, 32215, 27878, 29607, 30556, 28346, 30443, 36341, 36294, 37986, 31195, 29901, 23710, 33021, 44592, 33645, 32171, 29254, 32206, 36591, 31594, 29400, 42867, 35651, 17024, 26448, 29236, 32715, 31105, 22994, 27418, 30465, 29917, 31771, 40435, 37681, 35318, 35042, 34416, 28057, 30444, 33304, 35449, 36542, 35494, 36205, 44162, 27751, 16539, 26707, 29420, 42394, 34610, 28322, 31813, 31943, 40454, 31149, 19431, 20470, 19994, 38941, 36469, 33534, 31695, 30871, 24091, 27954, 44241, 34962, 30496, 32072, 31538, 26003, 29393, 30556, 40693, 41729, 20039, 26386, 34728, 31403, 31282, 25689, 31115, 45786, 35249, 30896, 27162, 28209, 37802, 29334, 22210, 36538, 37425, 26729, 28795, 27515, 37778, 40443, 36006, 35902, 36339, 30907, 27893, 30598, 33401, 46699, 30310, 20105, 30464, 31862, 40525, 35207, 34368, 19248, 16752, 19787, 27249, 39078, 38107, 40233, 25709, 27250, 22278, 35541, 40214, 48000, 40886, 19068, 22317, 20196, 36294, 37652, 30473, 33168, 33496, 37840, 37949, 37458, 34853, 33989, 26858, 24531, 19876, 28415, 48639, 41883, 41563, 32329, 30367, 23308, 29907, 33999, 37219, 37757, 34219, 31910, 26067, 35679, 37481, 41815, 35305, 22988, 29589, 30505, 37198, 37771, 44427, 30848, 22828, 24780, 28213, 45665, 39253, 36867, 31646, 30012, 28730, 28698, 27670, 34625, 37412, 33559, 32050, 23651, 37088, 42310, 38259, 34107, 20411, 29503, 34839, 27983, 27959, 30215, 30876, 32075, 31128, 31388, 33588, 31652, 27251, 33540, 35534, 38944, 35378, 24625, 34601, 39051, 28312, 28333, 32655, 28268, 24142, 34458, 35763, 35676, 31895, 26589, 28290, 28304, 40073, 33705, 23365, 29895, 31933, 35891, 35693, 33418, 36238, 38119, 35382, 35060, 32192, 34868, 36026, 38754, 39552, 46235, 37556, 25685, 32962, 33898, 35187, 37121, 43940, 33042, 27971, 39147, 35858, 24691, 30771, 33519, 35918, 36229, 36041, 32786, 28296, 32953, 32959, 30994, 30177, 28146, 34202, 37084, 36855, 38148, 39807, 37704, 36113, 34246, 32754, 29789, 32426, 34819, 31359, 32318, 41979, 33474, 22734, 32918, 34052, 33642, 32289, 31599, 27684, 26112, 37454, 37150, 37143, 32287, 28551, 36897, 36378, 33483, 30101, 24309, 39692, 41726, 43442, 36433, 27637, 28378, 27263, 31580, 29291, 22879, 36916, 43976, 26127, 28852, 38208, 33975, 32919, 27442, 27930, 28853, 34587, 39955, 42696, 41616, 22973, 23240, 17737, 35049, 40938, 32370, 32188, 28029, 35264, 38443, 29839, 30125, 35209, 30718, 28009, 27978, 28854, 34425, 34926, 38450, 27127, 25427, 34796, 34856, 36246, 33762, 32425, 28848, 26565, 20284, 28898, 34591, 29579, 31377, 34254, 34944, 35146, 32841, 33348, 48507, 37184, 25240, 24751, 24364, 46624, 44453, 46705, 31994, 25047, 30697, 31355, 33786, 36778, 40636, 34474, 33487, 25526, 33936, 41391, 36039, 35044, 31248, 33033, 35557, 32446, 31578, 37927, 34542, 26995, 28927, 27959, 40329, 38367, 33697, 27792, 21648, 31396, 33308, 37602, 37607, 39590, 32479, 30714, 31272, 31798, 33033, 32232, 32128, 36743, 33662, 24517, 29463, 30392, 39510, 38186, 31407, 29573, 25734, 33281, 34325, 38483, 33008, 26052, 31056, 31903, 34103, 34813, 38516, 31154, 28155, 26585, 28421, 34680, 32985, 33385, 30087, 30931, 35881, 31792, 26923, 37068, 38642, 35339, 35237, 34143, 35659, 35570, 31735, 31783, 32137, 32455, 32752, 33527, 33390, 32667, 31633, 30060, 36300, 36928, 35892, 35104, 33909, 34010, 33462, 32045, 32455, 33577, 33311, 33499, 28421, 30642, 36422, 32265, 30333, 34565, 35196, 38603, 30703, 22104, 37631, 38461, 35602, 31662, 26037, 32316, 33682, 29760, 31771, 33685, 37302, 39297, 32615, 32227, 31445, 30351, 28656, 32624, 32996, 37189, 31032, 25644, 28814, 29750, 34103, 34511, 36393, 32936, 31735, 28197, 28829, 29424, 33489, 36538, 29374, 31052, 33991, 36288, 38504, 34074, 33562, 34425, 33440, 32430, 33307, 33466, 34425, 32805, 29187, 34815, 36505, 32987, 31794, 27511, 32495, 34784, 33601, 34029, 36468, 34247, 33354, 27937, 27663, 32626, 32016, 31487, 35187, 36699, 38840, 36840, 33172, 32362, 31029, 35024, 34580, 34372, 34734, 35614, 31102, 32136, 38371, 35311, 33205, 32988, 32928, 35954, 34460, 33224, 32345, 32082, 35577, 34619, 33002, 32163, 31165, 36098, 35509, 35100, 31742, 29110, 28912, 30501, 42021, 37775, 37113, 27356, 25276, 25330, 30738, 40148, 34598, 33955, 33456, 32731, 30011, 31690, 31894, 31785, 31352, 30774, 30538, 30164, 32735, 33209, 32620, 33023, 33901, 29478, 28619, 36846, 34419, 31839, 29674, 28347, 37151, 35076, 29417, 30703, 30294, 36423, 35509, 29292, 30967, 31289, 32101, 32490, 36205, 34599, 34352, 28778, 27083, 30498, 31712, 34980, 32614, 31937, 33503, 32169, 27290, 30591, 32333, 33218, 33396, 30543, 34047, 37520, 35473, 35407, 33519, 35218, 37648, 34801, 33541, 32624, 32452, 33620, 31617, 30988, 31389, 32471, 34581, 35810, 37414, 33583, 32555, 29856, 31691, 33948, 31372, 30992, 31742, 32016, 32595, 32174, 32179, 32404, 33243, 35761, 33359, 32084, 32723, 32214, 30107, 31834, 33128, 34646, 34794, 30689, 31695, 31254, 34923, 35792, 35636, 33967, 30852, 31804, 31840, 32746, 33488, 35850, 34295, 33581, 31824, 32089, 36900, 32638, 28717, 32035, 32625, 33866, 32937, 31087, 33969, 34895, 35016, 34698, 33848, 34000, 33935, 32434, 33302, 37106, 36780, 38368, 27475, 26183, 27021, 30454, 35029, 32789, 33052, 34265, 31620, 24956, 32751, 35021, 36920, 35757, 33112, 33154, 32859, 31775, 32119, 34053, 33075, 31913, 36867, 37521, 36708, 34302, 30528, 32045, 31653, 33309, 32578, 32582, 31750, 31801, 31109, 31543, 30822, 33568, 35048, 36182, 35226, 31170, 29928, 27158, 33985, 35148, 32523, 33729, 35218, 32953, 32107, 35605, 34551, 33923, 31031, 29363, 30751, 31829, 36168, 33330, 31726, 34984, 35332, 33604, 33580, 32284, 35641, 35769, 35346, 31886, 25515, 31853, 33886, 32557, 33270, 34308, 33861, 33453, 33061, 32944, 34963, 31853, 29546, 30688, 31357, 34567, 33696, 32460, 35268, 35627, 30572, 31216, 32011, 32305, 32602, 32509, 32294, 30537, 33462, 35397, 33246, 33008, 32104, 32099, 31359, 34033, 34327, 34614, 32515, 29315, 31180, 31559, 35570, 34281, 31568, 32761, 32983, 35028, 35012, 35106, 33722, 32580, 32261, 31902, 31879, 31996, 32426, 31629, 31530, 32073, 31403, 29933, 31764, 32525, 36164, 35632, 34351, 32894, 31412, 34222, 34258, 36091, 32603, 29776, 31671, 32217, 36200, 33682, 30978, 32836, 33302, 34712, 34634, 34671, 34361, 34245, 33624, 33382, 32323, 33488, 33894, 33756, 32992, 31197, 30653, 29854, 31935, 32742, 33207, 34160, 35211, 35153, 34902, 30717, 31430, 33264, 32113, 31921, 32522, 33094, 34091, 34241, 34533, 32990, 32379, 30587, 31408, 31706, 34778, 35346, 30492, 32197, 34232, 32686, 32146, 32554, 32846, 34743, 30533, 27864, 35498, 35503, 35373, 33071, 31390, 30024, 30050, 32470, 33072, 34554, 32703, 32462, 33430, 33405, 33959, 32360, 31872, 31128, 32066, 33714, 34652, 35398, 35754, 34338, 27998, 30595, 32056, 32708, 33078, 32142, 33407, 35065, 32960, 32307, 33400, 33829, 36387, 31949, 30235, 29927, 31248, 34688, 35596, 37286, 33806, 33072, 29038, 33264, 37631, 33802, 33057, 29705, 30740, 30723, 34878, 36418, 34708, 33934, 32265, 31164, 29839, 33052, 32694, 31612, 32315, 33147, 33006, 33209, 31490, 33115, 34233, 34722, 34752, 35646, 34001, 31979, 29948, 28582, 33258, 33086, 33692, 31657, 30462, 32648, 32900, 33062, 33340, 33839, 33704, 33239, 26256, 32147, 39888, 34006, 32952, 32779, 32064, 29737, 32213, 32889, 37239, 35304, 29081, 29646, 28162, 36191, 36128, 33478, 31707, 29412, 30696, 31046, 34193, 33901, 34549, 32051, 31296, 31894, 32778, 35393, 32805, 31694, 33170, 32971, 31735, 32923, 33770, 33397, 33166, 31294, 32443, 33510, 33311, 33393, 32995, 33097, 33014, 33451, 33538, 32286, 32156, 31676, 33114, 34236, 32334, 32861, 34644, 34394, 34443, 33039, 32509, 31532, 32369, 33896, 31462, 31060, 33490, 33985, 35995, 32454, 31037, 31561, 32346, 34926, 33587, 32979, 32855, 32479, 31838, 31737, 31939, 29920, 30187, 35787, 34465, 33211, 33042, 32838, 33741, 33275, 32475, 31794, 31016, 36644, 35642, 31590, 32048, 31606, 33421, 33782, 34951, 33850, 32672, 32837, 32588, 33420, 32598, 31813, 31175, 31042, 35477, 34950, 32710, 34476, 35154, 33421, 32599, 30638, 31497, 32027, 33378, 33497, 29992, 32214, 34431, 32667, 32296, 36117, 33887, 30175, 31998, 32534, 29906, 30710, 32199, 34276, 36300, 33783, 33278, 30166, 32514, 34243, 33279, 32697, 29878, 30189, 29947, 32462, 33508, 32611, 32431, 30956, 32915, 33582, 33945, 33326, 31225, 32726, 33992, 31488, 31943, 34853, 34285, 33841, 33257, 32795, 34442, 32495, 30148, 29740, 29429, 33036, 33109, 33065, 33425, 33797, 32453, 32559, 33054, 33298, 33679, 32939, 32956, 33409, 33530, 33864, 32847, 32562, 33694, 32873, 31172, 32764, 33252, 34152, 33474, 31502, 31874, 31650, 33391, 33623, 34464, 33115, 31883, 31825, 31800, 34070, 33037, 32114, 32300, 32405, 31856, 32941, 35455, 33297, 32431, 32779, 32211, 30031, 32335, 33949, 32827, 32927, 33424, 32673, 31570, 32946, 33116, 33459, 32726, 31407, 32606, 32904, 33954, 33232, 31500, 32004, 31949, 32682, 32615, 32613, 32064, 31530, 32409, 32464, 31861, 32551, 33622, 32191, 32038, 32722, 32970, 33237, 33476, 33580, 33151, 32846, 32129, 32231, 32099, 33241, 33293, 33095, 32825, 32403, 33659, 33746, 32298, 32548, 32356, 33483, 33689, 33198, 32601, 31610, 31297, 30931, 33001, 33504, 35535, 33007, 31313, 32705, 32778, 32899, 32972, 33067, 33613, 33607, 31510, 32409, 33798, 32406, 31991, 31567, 32202, 34021, 32826, 32496, 31506, 32064, 34434, 33704, 33705, 32459, 32185, 30477, 32302, 34036, 34855, 34946, 30040, 30737, 30913, 32960, 33944, 31632, 32379, 34306, 33602, 33574, 30836, 31046, 33184, 32706, 32523, 33350, 33357, 31888, 31972, 31652, 32435, 32640, 33049, 32794, 32329, 32296, 32164, 32963, 32824, 32516, 32255, 31965, 33064, 33320, 33774, 33478, 33238, 33065, 32992, 33286, 32979, 32378, 33177, 33348, 33668, 32775, 30466, 32111, 32676, 33303, 33323, 33431, 32761, 32232, 32046, 32047, 32711, 32438, 32046, 33315, 33792, 34620, 34356, 34259, 32402, 31352, 32206, 32220, 33066, 32545, 32633, 31342, 31726, 33254, 32706, 32174, 33270, 33307, 32923, 32542, 32061, 32028, 32009, 32679, 32760, 32894, 33204, 33454, 32558, 32750, 33437, 32492, 31610, 34304, 34083, 32058, 31973, 31278, 33357, 33699, 33293, 32972, 32457, 32102, 31856, 33930, 33489, 33080, 32248, 31760, 32080, 32503, 34006, 33828, 34316, 30891, 30756, 32980, 32607, 32510, 32779, 32930, 33043, 32709, 31865, 32548, 32654, 33392, 33226, 33389, 31612, 30250, 33792, 33791, 33338, 32786, 32344, 31902, 31989, 33396, 33484, 34146, 32584, 32204, 32131, 32592, 33526, 33200, 33237, 32898, 32865, 32355, 33258, 33820, 33468, 33211, 31889, 32527, 32893, 33102, 33133, 33132, 32675, 31899, 32330, 32390, 33597, 33444, 33545, 32694, 32298, 31646, 31952, 32995, 33394, 34098, 32659, 32477, 31696, 32471, 33085, 33763, 33961, 32256, 33044, 34153, 33526, 33350, 32539, 32589, 32625, 32998, 33211, 33042, 32956, 32958, 32530, 32146, 32900, 33051, 32187, 33229, 34344, 34242, 34125, 31699, 31921, 32023, 32819, 33244, 31799, 31857, 31646, 32727, 33507, 32740, 32487, 31173, 31693, 31667, 33666, 34038, 33484, 32902, 31817, 32118, 32035, 33959, 33784, 34385, 31961, 30697, 32601, 32691, 32857, 33191, 33711, 32016, 31955, 32757, 32440, 32073, 33006, 33174, 32071, 32405, 32633, 33146, 33374, 32553, 32699, 33111, 32605, 32284, 32853, 33003, 33967, 32701, 31650, 32540, 32649, 33119, 32867, 32664, 32706, 32762, 33227, 33269, 33488, 33009, 32807, 32214, 32426, 33115, 33105, 33295, 32677, 32665, 32579, 32840, 33037, 33193, 33195, 32637, 32861, 33077, 33164, 33180, 32183, 32454, 32908, 33079, 33260, 31918, 32119, 33076, 32667, 32562, 32297, 32325, 32307, 32634, 32894, 33424, 33489, 32167, 32279, 31991, 33065, 33398, 32762, 32633, 32322, 32634, 32824, 32009, 31820, 30712, 32377, 33681, 33515, 33420, 31733, 32138, 32088, 32896, 33007, 32539, 32432, 32337, 32096, 31997, 32951, 33065, 33420, 32829, 32461, 32564, 32555, 32736, 32766, 32957, 32305, 32251, 32457, 32809, 33520, 32461, 32221, 32460, 32695, 33266, 32744, 32540, 33345, 33161, 32435, 32740, 32856, 32555, 32552, 33069, 32493, 31823, 32855, 33117, 33634, 33277, 32768, 32676, 32490, 32546, 32435, 32369, 32554, 32768, 32432, 32523, 32422, 32815, 33021, 33367, 33323, 32943, 32556, 31902, 32724, 32967, 33983, 33488, 32639, 32696, 32508, 33965, 33550, 32981, 32096, 31353, 32154, 32292, 33193, 32679, 32524, 32039, 32063, 32249, 32652, 33078, 33635, 33831, 32023, 32195, 32018, 32980, 33387, 33279, 33034, 32318, 32504, 32544, 32197, 32273, 32937, 32774, 32728, 32709, 32760, 33076, 33034, 33093, 32688, 32524, 32139, 32428, 33103, 33102, 33290, 32420, 32405, 32065, 32991, 33783, 33054, 33017, 32642, 33085, 33572, 32871, 32665, 32943, 32745, 32537, 32653, 32746, 32674, 32840, 33066, 33056, 33005, 33570, 33339, 32316, 32494, 32441, 32825, 32962, 33652, 33311, 33114, 32278, 31959, 32698, 32585, 32566, 32528, 32575, 32843, 32946, 33070, 33139, 33284, 32308, 32407, 33366, 33285, 33425, 32985, 32886, 32825, 32616, 32070, 33103, 33391, 32867, 32752, 32467, 32552, 32548, 32842, 33043, 33771, 33207, 32882, 32614, 32643, 33379, 33214, 33316, 32432, 32217, 32494, 32591, 32837, 32807, 32875, 32658, 32743, 32860, 32692, 32503, 33210, 33081, 32716, 32279, 31703, 32867, 33105, 33661, 33073, 32256, 32917, 32999, 33100, 32923, 32651, 32771, 32799, 32521, 32514, 32441, 32780, 33069, 32577, 32601, 32695, 32810, 32897, 33110, 33127, 32500, 32822, 33244, 32960, 32877, 32566, 32508, 32261, 32708, 32909, 33013, 32970, 32885, 32567, 32236, 32826, 32840, 32513, 32688, 32793, 33131, 33225, 33101, 32728, 31808, 32896, 33184, 33260, 33135, 33087, 32507, 32121, 32514, 32596, 32867, 32841, 32850, 33039, 32987, 32565, 32358, 31881, 32697, 32913, 33220, 32881, 32073, 32834, 33061, 33084, 32922, 32453, 32744, 32916, 32530, 32602, 33052, 32860, 32692, 32877, 32881, 32927, 32751, 32528, 32560, 32543, 32535, 32635, 32884, 32744, 32738, 33089, 33235, 33648, 33103, 32652, 32895, 32752, 32541, 32339, 32059, 32847, 33063, 32675, 32864, 33026, 32914, 32837, 33092, 32937, 32733, 32492, 32290, 33152, 33142, 32907, 32599, 32089, 33497, 33646, 33818, 33039, 32047, 32497, 32498, 32866, 32863, 33095, 32572, 32381, 32823, 32879, 33112, 32814, 32672, 32526, 32525, 32455, 32853, 33294, 32932, 32835, 32168, 32384, 32469, 32905, 33088, 33323, 33125, 32685, 32560, 32324, 33064, 32948, 32978, 32487, 32200, 32188, 32336, 32823, 33072, 33474, 32907, 32863, 33531, 33159, 32618, 32863, 32859, 32392, 32512, 32819, 32878, 33010, 33036, 32977, 32394, 32822, 33007, 33174, 33141, 33121, 32759, 32341, 32357, 32357, 33011, 33039, 33310, 32749, 32544, 32711, 32721, 32697, 32914, 33086, 33047, 32995, 32469, 32917, 33258, 33036, 32942, 32437, 32685, 33019, 32762, 32717, 32533, 32667, 32905, 32944, 33030, 32395, 32558, 33102, 32914, 32853, 33023, 33063, 33060, 32977, 32819, 33009, 32977, 32933, 32700, 32330, 32639, 32725, 32843, 32836, 32798, 32832, 32853, 32726, 32725, 32701, 32813, 32900, 32887, 32878, 32804, 32802, 32809, 32613, 32576, 33029, 32889, 32708, 32730, 32716, 32851, 32801, 32656, 32801, 32905, 32675, 32649, 32462, 32717, 32898, 32986, 32998, 32905, 32796, 32641, 32563, 32521, 32980, 32893, 32810, 32747, 32726, 32984, 33040, 33192, 32917, 32682, 33034, 33029, 33092, 32884, 32702, 32692, 32702, 32980, 32916, 32839, 32940, 32957, 32643, 32698, 32878, 32656, 32540, 32828, 32813, 32707, 32764, 32811, 32687, 32715, 32989, 32897, 32856, 32686, 32659, 33050, 32882, 32598, 32827, 32882, 32863, 32771, 32520, 32665, 32714, 32715, 32740, 32926, 32680, 32460, 32685, 32746, 33028, 32936, 32913, 32527, 32405, 33071, 32903, 32723, 32676, 32657, 32555, 32532, 32268, 32766, 33075, 33196, 33080, 32298, 32418, 32278, 33019, 33170, 33245, 33020, 32688, 32635, 32553, 33231, 33048, 32809, 32738, 32695, 32633, 32664, 32701, 32795, 32842, 33161, 33145, 32694, 32816, 32893, 32819, 32794, 32662, 32763, 32882, 33069, 33187, 33012, 32976, 32764, 32886, 32862, 33069, 32928, 32553, 32543, 32510, 32538, 32581, 32656, 32764, 32903, 32850, 32838, 32723, 32718, 32722, 32613, 32565, 33168, 33178, 33203, 32922, 32680, 32896, 32825, 32690, 32605, 32486, 32814, 32871, 32711, 32725, 32717, 32609, 32559, 32891, 32833, 32826, 32606, 32489, 32659, 32713, 32915, 32760, 32671, 32716, 32717, 32711, 32783, 32918, 32617, 32588, 32887, 32857, 32821, 32870, 32879, 32731, 32702, 32623, 32694, 32718, 32870, 32853, 32707, 32729, 32708, 32721, 32745, 33032, 32925, 32915, 32632, 32561, 32486, 32698, 33079, 33017, 33052, 32737, 32697, 32518, 32740, 32853, 32976, 32986, 32883, 32824, 32684, 32998, 33015, 32902, 32806, 32659, 32720, 32717, 32796, 32841, 33060, 32668, 32485, 32550, 32652, 33103, 32829, 32724, 32578, 32594, 32706, 32793, 32892, 32998, 33031, 32696, 32841, 33019, 32915, 32874, 32728, 32752, 32860, 32821, 32834, 32648, 32689, 32847, 32854, 32894, 32714, 32681, 32723, 32714, 32724, 32712, 32726, 32706, 32767, 32847, 32865, 32880, 32735, 32688, 32532, 32667, 32715, 32868, 32845, 32723, 32684, 32636, 32577, 32561, 32546, 32628, 32720, 32882, 32973, 32836, 32828, 32684, 32846, 32875, 33046, 32965, 32810, 32660, 32495, 32770, 32799, 32901, 32798, 32713, 32782, 32805, 32793, 32785, 32682, 33030, 33156, 32889, 32874, 32780, 32863, 32874, 32892, 32845, 32710, 32765, 32803, 32699, 32682, 32724, 32714, 32722, 32714, 32724, 32665, 32735, 32829, 32832, 32842, 32723, 32758, 32905, 32775, 32721, 32713, 32755, 32882, 32864, 32831, 33007, 32991, 32678, 32708, 32717, 32692, 32678, 32719, 32750, 32868, 32727, 32686, 32781, 32821, 32884, 32862, 32836, 32981, 32987, 33022, 32849, 32654, 32730, 32707, 32729, 32697, 32684, 32680, 32684, 32717, 32709, 32675, 32707, 32724, 32825, 32838, 32789, 32848, 32881, 32880, 32888, 32965, 32943, 32980, 32746, 32672, 32511, 32661, 32897, 32912, 32965, 32806, 32755, 32521, 32770, 32886, 32877, 32877, 32890, 32802, 32706, 32793, 32781, 32723, 32705, 32674, 32712, 32726, 32887, 32807, 32674, 32667, 32639, 32677, 32714, 32860, 32801, 32810, 32720, 32745, 32782, 32889, 33011, 32898, 32878, 32888, 32810, 32653, 32835, 32875, 32887, 32830, 32709, 32731, 32714, 32836, 32803, 32670, 32750, 32805, 32791, 32802, 32791, 32820, 32840, 32843, 32828, 32726, 32725, 32718, 32723, 32725, 32840, 32789, 32626, 32704, 32715, 32836, 32784, 32554, 32589, 32548, 32825, 32875, 32887, 32809, 32710, 32725, 32727, 32835, 32840, 32830, 32936, 32992, 32884, 32864, 32786, 32838, 32856, 32878, 32853, 32707, 32786, 32843, 32866, 32873, 32845, 32801, 32701, 32839, 32885, 33024, 32977, 32869, 32864, 32828, 32955, 32895, 32705, 32793, 32845, 32679, 32653, 32731, 32693, 32694, 32590, 32593, 32789, 32803, 32850, 32756, 32719, 32841, 32799, 32719, 32724, 32721, 32717, 32741, 32822, 32822, 32845, 32740, 32741, 32881, 32860, 32891, 32702, 32659, 32837, 32830, 32843, 32809, 32796, 32839, 32833, 32846, 32774, 32715, 32791, 32805, 32886, 32829, 32796, 32739, 32720, 32718, 32762, 32855, 32746, 32726, 32715, 32756, 32845, 32830, 32843, 32727, 32731, 32707, 32806, 32880, 32869, 32868, 32840, 32792, 32705, 32818, 32830, 32846, 32794, 32712, 32777, 32797, 32792, 32809, 32840, 32813, 32794, 32865, 32868, 32878, 32849, 32838, 32744, 32724, 32713, 32784, 32885, 32837, 32830, 32663, 32698, 32709, 32800, 32838, 32840, 32805, 32718, 32710, 32678, 32783, 32799, 32841, 32812, 32798, 32739, 32737, 32877, 32837, 32825, 32747, 32724, 32717, 32756, 32847, 32804, 32797, 32832, 32830, 32788, 32837, 32877, 32742, 32732, 32803, 32759, 32714, 32783, 32787, 32724, 32723, 32725, 32723, 32731, 32809, 32823, 32835, 32836, 32833, 32839, 32830, 32844, 32778, 32715, 32819, 32829, 32791, 32812, 32837, 32805, 32799, 32873, 32850, 32840, 32762, 32721, 32831, 32821, 32791, 32818, 32837, 32798, 32799, 32789, 32830, 32875, 32825, 32809, 32716, 32759, 32791, 32847, 32861, 32729, 32728, 32721, 32725, 32723, 32813, 32792, 32718, 32730, 32718, 32787, 32781, 32721, 32729, 32717, 32797, 32816, 32794, 32774, 32711, 32794, 32814, 32799, 32772, 32720, 32727, 32723, 32785, 32796, 32816, 32820, 32837, 32740, 32734, 32793, 32804, 32842, 32747, 32728, 32795, 32770, 32713, 32788, 32816, 32831, 32821, 32794, 32759, 32717, 32852, 32851, 32840, 32777, 32714, 32730, 32727, 32804, 32758, 32724, 32724, 32729, 32716, 32761, 32839, 32825, 32836, 32828, 32835, 32829, 32850, 32865, 32837, 32832, 32833, 32829, 32832, 32802, 32785, 32720, 32754, 32795, 32815, 32836, 32862, 32847, 32785, 32824, 32827, 32838, 32805, 32723, 32728, 32722, 32780, 32794, 32792, 32796, 32788, 32823, 32827, 32794, 32791, 32793, 32791, 32794, 32723, 32762, 32873, 32815, 32792, 32734, 32736, 32804, 32755, 32725, 32725, 32726, 32721, 32728, 32718, 32802, 32827, 32795, 32772, 32716, 32730, 32721, 32791, 32772, 32724, 32729, 32724, 32727, 32725, 32725, 32724, 32726, 32724, 32735, 32813, 32801, 32795, 32745, 32721, 32730, 32726, 32727, 32726, 32730, 32817, 32826, 32812, 32805, 32789, 32825, 32823, 32789, 32811, 32830, 32829, 32819, 32727, 32732, 32719, 32794, 32834, 32807, 32821, 32826, 32831, 32826, 32860, 32850, 32831, 32825, 32833, 32745, 32728, 32722, 32754, 32793, 32815, 32822, 32727, 32751, 32799, 32746, 32729, 32785, 32797, 32811, 32820, 32829, 32796, 32787, 32796, 32761, 32720, 32782, 32785, 32722, 32754, 32796, 32766, 32763, 32791, 32791, 32793, 32791, 32790, 32733, 32731, 32721, 32764, 32793, 32819, 32822, 32789, 32790, 32792, 32741, 32735, 32826, 32810, 32787, 32815, 32826, 32826, 32814, 32787, 32792, 32789, 32791, 32776, 32723, 32762, 32791, 32815, 32828, 32855, 32826, 32784, 32793, 32788, 32824, 32809, 32790, 32791, 32788, 32822, 32800, 32719, 32787, 32825, 32791, 32797, 32822, 32820, 32824, 32796, 32794, 32820, 32818, 32822, 32798, 32787, 32823, 32808, 32789, 32789, 32789, 32735, 32735, 32725, 32773, 32811, 32815, 32806, 32723, 32761, 32789, 32787, 32789, 32786, 32788, 32786, 32800, 32802, 32738, 32735, 32730, 32764, 32791, 32733, 32747, 32788, 32786, 32785, 32787, 32786, 32787, 32785, 32791, 32747, 32736, 32789, 32769, 32728, 32772, 32790, 32787, 32775, 32727, 32768, 32787, 32787, 32778, 32728, 32769, 32809, 32745, 32745, 32818, 32800, 32786, 32787, 32786, 32785, 32787, 32785, 32804, 32816, 32814, 32808, 32781, 32803, 32814, 32791, 32785, 32787, 32786, 32788, 32784, 32787, 32783, 32787, 32782, 32804, 32810, 32789, 32771, 32731, 32769, 32785, 32743, 32740, 32734, 32760, 32791, 32743, 32740, 32735, 32741, 32735, 32774, 32787, 32783, 32784, 32788, 32753, 32736, 32738, 32749, 32788, 32778, 32787, 32741, 32750, 32784, 32791, 32800, 32805, 32807, 32783, 32795, 32810, 32790, 32782, 32786, 32782, 32785, 32783, 32785, 32740, 32758, 32811, 32798, 32798, 32805, 32809, 32807, 32808, 32807, 32800, 32793, 32784, 32782, 32783, 32782, 32784, 32782, 32785, 32781, 32798, 32806, 32786, 32774, 32737, 32765, 32783, 32781, 32783, 32782, 32783, 32781, 32794, 32791, 32741, 32757, 32783, 32779, 32784, 32780, 32784, 32780, 32790, 32794, 32784, 32781, 32782, 32781, 32784, 32750, 32742, 32743, 32745, 32740, 32772, 32782, 32783, 32769, 32740, 32746, 32742, 32745, 32744, 32744, 32743, 32743, 32743, 32744, 32745, 32745, 32745, 32743, 32749, 32781, 32780, 32781, 32780, 32782, 32779, 32786, 32803, 32795, 32793, 32800, 32797, 32792, 32787, 32778, 32782, 32780, 32784, 32765, 32742, 32773, 32783, 32800, 32792, 32778, 32781, 32779, 32780, 32784, 32802, 32786, 32779, 32780, 32784, 32799, 32798, 32800, 32783, 32780, 32778, 32786, 32799, 32796, 32796, 32746, 32759, 32779, 32790, 32798, 32791, 32781, 32742, 32769, 32780, 32778, 32778, 32782, 32766, 32744, 32774, 32775, 32746, 32760, 32782, 32755, 32748, 32748, 32749, 32745, 32768, 32780, 32778, 32779, 32780, 32763, 32746, 32750, 32747, 32748, 32748, 32749, 32748, 32749, 32749, 32750, 32746, 32768, 32778, 32749, 32758, 32779, 32776, 32778, 32777, 32779, 32778, 32778, 32777, 32778, 32778, 32787, 32782, 32778, 32778, 32777, 32787, 32783, 32777, 32777, 32777, 32778, 32777, 32777, 32777, 32778, 32777, 32778, 32777, 32777, 32776, 32789, 32790, 32776, 32778, 32776, 32783, 32785, 32777, 32777, 32777, 32778, 32778, 32784, 32783, 32776, 32777, 32775, 32777, 32776, 32777, 32776, 32777, 32757, 32754, 32776, 32776, 32777, 32776, 32777, 32775, 32778, 32785, 32779, 32775, 32776, 32776, 32776, 32776, 32777, 32757, 32753, 32753, 32762, 32778, 32758, 32756, 32775, 32774, 32777, 32761, 32754, 32754, 32758, 32779, 32762, 32753, 32772, 32776, 32775, 32775, 32775, 32774, 32775, 32776, 32775, 32775, 32775, 32775, 32775, 32774, 32777, 32762, 32754, 32774, 32775, 32774, 32776, 32775, 32774, 32775, 32775, 32774, 32776, 32760, 32757, 32776, 32773, 32775, 32773, 32774, 32755, 32765, 32787, 32783, 32785, 32775, 32774, 32774, 32776, 32773, 32784, 32784, 32774, 32773, 32775, 32775, 32773, 32774, 32775, 32781, 32775, 32774, 32774, 32774, 32774, 32775, 32773, 32774, 32773, 32774, 32773, 32774, 32759, 32758, 32757, 32764, 32776, 32773, 32773, 32773, 32774, 32773, 32765, 32756, 32758, 32757, 32759, 32758, 32759, 32757, 32758, 32757, 32765, 32774, 32762, 32761, 32774, 32768, 32757, 32770, 32774, 32772, 32773, 32773, 32773, 32773, 32773, 32772, 32773, 32773, 32773, 32772, 32773, 32772, 32776, 32780, 32781, 32779, 32773, 32773, 32773, 32773, 32773, 32773, 32772, 32773, 32773, 32772, 32772, 32773, 32772, 32773, 32772, 32772, 32773, 32779, 32777, 32776, 32773, 32772, 32773, 32772, 32771, 32776, 32779, 32773, 32773, 32771, 32772, 32772, 32772, 32772, 32772, 32772, 32772, 32771, 32772, 32772, 32772, 32772, 32771, 32771, 32772, 32772, 32772, 32772, 32771, 32772, 32772, 32771, 32772, 32772, 32771, 32772, 32770, 32771, 32771, 32771, 32771, 32772, 32771, 32772, 32765, 32763, 32771, 32771, 32771, 32770, 32771, 32770, 32771, 32770, 32771, 32771, 32771, 32771, 32771, 32771, 32770, 32771, 32771, 32771, 32770, 32771, 32770, 32770, 32771, 32771, 32770, 32770, 32771, 32770, 32771, 32770, 32771, 32770, 32771, 32770, 32771, 32770, 32770, 32771, 32770, 32771, 32770, 32770, 32771, 32771, 32770, 32771, 32774, 32771, 32770, 32770, 32770, 32770, 32770, 32770, 32770, 32770, 32770, 32770, 32770, 32770, 32769, 32771, 32768, 32763, 32768, 32770, 32764, 32766, 32769, 32770, 32769, 32768, 32768, 32764, 32766, 32770, 32769, 32770, 32770, 32770, 32769, 32770, 32769, 32769, 32770, 32769, 32769, 32769, 32770, 32770, 32770, 32770, 32769, 32769, 32770, 32769, 32770, 32770, 32770, 32769, 32769, 32769, 32769, 32769, 32770, 32769, 32770, 32770, 32769, 32769, 32770, 32769, 32770, 32769, 32769, 32769, 32769, 32769, 32769, 32769, 32769, 32769, 32769, 32769, 32769, 32770, 32769, 32770, 32769, 32768, 32768, 32769, 32769, 32769, 32769, 32768, 32769, 32769, 32769, 32770, 32769, 32769, 32769, 32769, 32769, 32768, 32768, 32769, 32769, 32769, 32769, 32771, 32770, 32769, 32769, 32769, 32769, 32769, 32769, 32768, 32768, 32768, 32769, 32768, 32768, 32769, 32768, 32768, 32769, 32769, 32768, 32769, 32768, 32767, 32768, 32768, 32769, 32768, 32768, 32768, 32768, 32769, 32768, 32768, 32768, 32769, 32768, 32769, 32768, 32769, 32769, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32769, 32768, 32767, 32768, 32768, 32769, 32769, 32769, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32769, 32768, 32768, 32768, 32769, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32767, 32768, 32768, 32767, 32768, 32767, 32768, 32769, 32768, 32768, 32768, 32767, 32768, 32768, 32768, 32768, 32768, 32768, 32768, 32768};

