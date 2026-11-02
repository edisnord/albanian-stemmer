/* Generated from albanian.sbl by Snowball 3.2.0 - https://snowballstem.org/ */

#include "stem_UTF_8_albanian.h"

#include <stddef.h>

#include "runtime/snowball_runtime.h"

struct SN_local {
    struct SN_env z;
    int i_s2;
    int i_p1;
};

typedef struct SN_local SN_local;

#ifdef SNOWBALL_BIGENDIAN
#define S(W) ((0x##W & 0xff) << 8 | 0x##W >> 8)
#else
#define S(W) (0x##W)
#endif

#ifdef __cplusplus
extern "C" {
#endif
extern int albanian_UTF_8_stem(struct SN_env * z);
#ifdef __cplusplus
}
#endif

static int r_AfterKGH(struct SN_env * z);
static int r_AfterC(struct SN_env * z);
static int r_AfterV(struct SN_env * z);
static int r_S2(struct SN_env * z);
static int r_R1(struct SN_env * z);

#define s_77 (s_1 + 1)
#define s_108 (s_8 + 3)
#define s_38 (s_12 + 2)
#define s_183 (s_18 + 2)
#define s_185 (s_25 + 4)
#define s_314 (s_41 + 1)
#define s_340 (s_57 + 5)
#define s_206 (s_64 + 5)
#define s_70 (s_69 + 2)
#define s_341 (s_102 + 1)
#define s_316 (s_141 + 3)
#define s_248 (s_152 + 4)
#define s_190 (s_212 + 2)
#define s_62 (s_218 + 3)
#define s_250 (s_306 + 1)
#define s_257 (s_308 + 1)
#define s_301 (s_116 + 2)
#define s_278 (s_245 + 2)
#define s_33 (s_172 + 1)
#define s_20 (s_170 + 1)
#define s_255 (s_335 + 1)
#define s_37 (s_53 + 3)
#define s_198 (s_95 + 3)
#define s_121 (s_256 + 2)
#define s_277 (s_133 + 2)
#define s_106 (s_52 + 1)
#define s_118 (s_19 + 3)
#define s_110 (s_247 + 1)
#define s_130 (s_282 + 1)
#define s_208 (s_298 + 2)
#define s_303 (s_48 + 4)
#define s_79 (s_3 + 1)
#define s_230 (s_54 + 4)
#define s_159 (s_310 + 3)
#define s_128 (s_27 + 3)
#define s_194 (s_122 + 6)
#define s_253 (s_2 + 2)
#define s_56 (s_146 + 4)
#define s_182 (s_330 + 4)
#define s_57 (s_184 + 3)
#define s_296 (s_281 + 3)
#define s_124 (s_227 + 6)
#define s_318 (s_337 + 1)
#define s_55 (s_45 + 2)
#define s_161 (s_262 + 2)
#define s_10 (s_58 + 2)
#define s_104 (s_49 + 3)
#define s_134 (s_43 + 2)
#define s_319 (s_309 + 2)
#define s_258 (s_99 + 1)
#define s_75 (s_120 + 1)
#define s_162 (s_13 + 3)
#define s_249 (s_337 + 2)
#define s_73 (s_331 + 2)
#define s_22 (s_35 + 3)
#define s_39 (s_59 + 2)
#define s_21 (s_84 + 2)
#define s_312 (s_156 + 3)
#define s_72 (s_201 + 3)
#define s_334 (s_223 + 3)
#define s_158 (s_226 + 1)
#define s_256 (s_151 + 1)
#define s_69 (s_265 + 1)
#define s_269 (s_174 + 4)
#define s_163 (s_338 + 1)
#define s_280 (s_264 + 2)
#define s_12 (s_66 + 2)
#define s_307 (s_86 + 4)
#define s_160 (s_36 + 3)
#define s_154 (s_180 + 4)
#define s_53 (s_210 + 2)
#define s_195 (s_233 + 3)
#define s_305 (s_213 + 3)
#define s_52 (s_76 + 2)
#define s_105 (s_101 + 3)
#define s_43 (s_150 + 4)
#define s_279 (s_177 + 4)
#define s_181 (s_50 + 4)
#define s_207 (s_333 + 2)
#define s_44 (s_231 + 4)
#define s_111 (s_260 + 3)
#define s_276 (s_270 + 4)
#define s_311 (s_288 + 5)
#define s_82 (s_85 + 7)
#define s_74 (s_131 + 4)
#define s_67 (s_238 + 5)
#define s_247 (s_89 + 2)
#define s_109 (s_315 + 4)
#define s_116 (s_321 + 4)
#define s_27 (s_129 + 1)
#define s_117 (s_136 + 4)
#define s_133 (s_172 + 5)
#define s_54 (s_290 + 3)
#define s_112 (s_157 + 4)
#define s_300 (s_210 + 7)
#define s_228 (s_86 + 7)
#define s_71 (s_237 + 5)
#define s_271 (s_64 + 8)
#define s_113 (s_293 + 5)
#define s_63 (s_11 + 7)
#define s_114 (s_165 + 5)
#define s_281 (s_203 + 3)
#define s_317 (s_221 + 4)
#define s_115 (s_35 + 6)
#define s_310 (s_203 + 13)
#define s_164 (s_61 + 2)
#define s_107 (s_96 + 3)
#define s_292 (s_225 + 3)
#define s_325 (s_98 + 3)
#define s_7 (s_189 + 2)
#define s_193 (s_335 + 4)
#define s_320 (s_244 + 3)
#define s_283 (s_287 + 4)
#define s_266 (s_14 + 4)
#define s_119 (s_34 + 2)
#define s_304 (s_46 + 4)
#define s_323 (s_147 + 4)
#define s_246 (s_30 + 3)
#define s_120 (s_80 + 2)
#define s_259 (s_123 + 3)
#define s_262 (s_29 + 4)
#define s_171 (s_268 + 5)
#define s_178 (s_102 + 5)
#define s_179 (s_272 + 5)
#define s_328 (s_188 + 4)
#define s_187 (s_192 + 5)
#define s_200 (s_96 + 5)
#define s_18 (s_81 + 5)
#define s_291 (s_329 + 4)
#define s_308 (s_332 + 4)
#define s_263 (s_153 + 4)
#define s_205 (s_78 + 3)
#define s_285 (s_211 + 4)
#define s_338 (s_51 + 3)
#define s_324 (s_92 + 5)
#define s_100 (s_45 + 4)
#define s_309 (s_42 + 5)
#define s_302 (s_135 + 5)
#define s_202 (s_299 + 6)
#define s_204 (s_295 + 6)
#define s_261 (s_217 + 5)
#define s_336 (s_99 + 5)
#define s_273 (s_132 + 5)
#define s_306 (s_137 + 5)
#define s_289 (s_155 + 5)
#define s_252 (s_225 + 5)
#define s_167 (s_197 + 6)
#define s_337 (s_87 + 6)
#define s_102 (s_61 + 4)
#define s_335 (s_232 + 6)
#define s_297 (s_224 + 5)
#define s_287 (s_169 + 5)
#define s_173 (s_19 + 7)
#define s_175 (s_176 + 7)
#define s_264 (s_191 + 5)
#define s_265 (s_239 + 5)
#define s_251 (s_331 + 6)
#define s_254 (s_244 + 6)
#define s_199 (s_127 + 7)
#define s_275 (s_242 + 6)
#define s_298 (s_219 + 5)
#define s_196 (s_235 + 7)
#define s_282 (s_189 + 6)
#define s_186 (s_333 + 9)
#define s_1 (s_36 + 8)
#define s_294 (s_209 + 6)
#define s_272 (s_339 + 7)
#define s_274 (s_223 + 7)
#define s_268 (s_59 + 7)
#define s_201 (s_32 + 8)
#define s_286 (s_240 + 7)
#define s_299 (s_145 + 6)
#define s_270 (s_151 + 7)
#define s_267 (s_174 + 7)
#define s_295 (s_8 + 7)
#define s_101 (s_29 + 8)
#define s_326 (s_48 + 8)
#define s_260 (s_180 + 8)
#define s_284 (s_233 + 8)
#define s_168 (s_288 + 10)
#define s_166 (s_137 + 11)
#define s_103 (s_42 + 10)
#define s_313 (s_85 + 10)
#define s_197 (s_50 + 9)
#define s_290 (s_245 + 8)
#define s_293 (s_16 + 7)
#define s_188 (s_241 + 13)
#define s_329 (s_224 + 12)
#define s_288 (s_218 + 8)
#define s_339 (s_232 + 12)
#define s_203 (s_184 + 11)
static const symbol s_0[] = {
    'e', 'f', 'i', 'k', 'a', 's', 'i', 't',
    'e', 't'
};
static const symbol s_157[] = {
    'k', 'u', 'z', 'h', 'i', 'n', 'f', 'o',
    'r', 'm', 'a', 'c', 'i'
};
static const symbol s_2[] = {
    'a', 'd', 'r', 'e', 's', 't', 'o', 'r',
    'a', 'n', 't'
};
static const symbol s_3[] = {
    'a', 'f', 'a', 't', 'k', 'e', 'q', 'e',
    's', 'i'
};
static const symbol s_4[] = { 'a', 'f', 'e', 'r', 's', 'i' };
static const symbol s_5[] = { 'a', 'f', 't', 'e', 's', 'i' };
static const symbol s_6[] = { 'a', 'g', 'j', 'e', 'n', 'c', 'i' };
static const symbol s_241[] = {
    'p', 'r', 'o', 'f', 'e', 's', 'i', 'o',
    'n', 'a', 'l', 'i', 'z', 'm', 'o', 't',
    'i', 'v', 'i', 'd', 'e', 'o'
};
static const symbol s_8[] = {
    'a', 'k', 's', 'i', 'd', 'e', 'n', 't',
    'e', 'l', 'e', 'f', 'o', 'n', 'x', 'i',
    'r', 'r'
};
static const symbol s_9[] = {
    'a', 'k', 't', 'i', 'v', 'i', 't', 'e',
    't'
};
static const symbol s_221[] = {
    'p', 'e', 'r', 'p', 'u', 'n', 'i', 'v',
    'e', 'r', 's', 'i', 't', 'e', 't'
};
static const symbol s_11[] = {
    'a', 'l', 'e', 'k', 's', 'a', 'n', 'd',
    'r', 'e', 'j', 't', 'e', 's', 'i'
};
static const symbol s_333[] = {
    'v', 'l', 'o', 'r', 'g', 'a', 'n', 'i',
    'z', 'm', 'o', 'm', 'e', 'n', 't'
};
static const symbol s_13[] = { 'a', 'n', 'g', 'l', 'i', 'r', 'i' };
static const symbol s_14[] = { 'a', 'n', 'k', 'e', 's', 'e', 'r', 'i' };
static const symbol s_15[] = { 'a', 'p', 'l', 'i', 'k', 'a', 'c', 'i' };
static const symbol s_16[] = {
    'a', 'r', 'g', 'u', 'm', 'e', 'n', 't',
    'a', 'v', 'o', 'l', 'i', 'n', 's', 't',
    'i', 't', 'u', 'c', 'i'
};
static const symbol s_17[] = {
    'a', 'r', 'k', 'e', 'o', 'l', 'o', 'g',
    'j', 'i'
};
static const symbol s_223[] = {
    'p', 'e', 'r', 'v', 'o', 'n', 'e', 's',
    'h', 'p', 'e', 'j', 't', 'e', 's', 'i'
};
static const symbol s_19[] = {
    'a', 'r', 'r', 'i', 's', 'h', 'i', 'm',
    'b', 'l', 'i', 'd', 'h'
};
static const symbol s_209[] = {
    'p', 'a', 'c', 'i', 'e', 'n', 't', 'e',
    'k', 'n', 'o', 'l', 'o', 'g', 'j', 'i'
};
static const symbol s_191[] = {
    'm', 'u', 'n', 'g', 'e', 's', 'a', 's',
    'i', 'g', 'u', 'r', 'i'
};
static const symbol s_225[] = {
    'p', 'j', 'e', 's', 'y', 'r', 'e', 'n',
    'd', 'e', 's', 'i'
};
static const symbol s_23[] = { 'a', 'u', 's', 't', 'r', 'a', 'l', 'i' };
static const symbol s_24[] = { 'a', 'u', 's', 't', 'r', 'i' };
static const symbol s_25[] = { 'a', 'u', 't', 'o', 'm', 'j', 'e', 't' };
static const symbol s_26[] = {
    'a', 'u', 't', 'o', 'r', 'i', 't', 'e',
    't'
};
static const symbol s_184[] = {
    'm', 'j', 'e', 'd', 'i', 's', 'k', 'r',
    'i', 'm', 'i', 'n', 'j', 'e', 's', 'i',
    's', 't', 'e', 'm', 'p', 'e', 'r', 'a',
    't', 'u', 'a', 'l', 'e', 't', 'e', 'r',
    's', 'i'
};
static const symbol s_28[] = { 'b', 'a', 'l', 'l', 'q' };
static const symbol s_29[] = {
    'b', 'a', 'n', 'e', 's', 'a', 'l', 'i',
    'h', 'a', 'x', 'h', 'i', 's', 't', 'o',
    'r', 'i'
};
static const symbol s_30[] = {
    'b', 'a', 'n', 'q', 'e', 'v', 'e', 'r',
    'i'
};
static const symbol s_31[] = { 'b', 'a', 'r', 'a', 'z', 'i' };
static const symbol s_32[] = {
    'b', 'a', 's', 'h', 'k', 'e', 'p', 'u',
    'n', 'g', 'r', 'e', 'm', 'o', 'c', 'i'
};
static const symbol s_212[] = {
    'p', 'a', 'm', 'u', 'n', 'd', 'e', 's',
    'i'
};
static const symbol s_34[] = { 'b', 'e', 'j', 'a', 'p', 'o', 'n', 'i' };
static const symbol s_35[] = {
    'b', 'e', 'r', 'a', 't', 'h', 'i', 'n',
    't', 'e', 'n', 's', 'i', 't', 'e', 't'
};
static const symbol s_36[] = {
    'b', 'e', 'r', 'l', 'i', 'c', 'e', 'n',
    'c', 'e', 'r', 'e', 'm', 'o', 'n', 'i'
};
static const symbol s_180[] = {
    'm', 'e', 's', 'h', 'k', 'u', 'f', 'i',
    'r', 'u', 't', 'i', 'n', 'f', 'e', 'k',
    's', 'i'
};
static const symbol s_218[] = {
    'p', 'e', 'r', 'd', 'o', 'r', 'u', 'e',
    's', 't', 'r', 'u', 'k', 't', 'u', 'r',
    'i', 'z', 'm', 'a', 'q', 'e', 'd', 'o',
    'n', 'i'
};
static const symbol s_40[] = { 'b', 'r', 'i', 't', 'a', 'n', 'i' };
static const symbol s_41[] = { 'b', 'u', 'j', 'q', 'e', 's', 'i' };
static const symbol s_42[] = {
    'b', 'u', 'x', 'h', 'e', 't', 'r', 'u',
    'r', 'd', 'h', 'e', 'r', 'c', 'e', 'g',
    'o', 'v', 'i', 'n'
};
static const symbol s_217[] = {
    'p', 'e', 'n', 'g', 'e', 's', 'a', 'k',
    't', 'e', 's', 'i'
};
static const symbol s_227[] = {
    'p', 'o', 'l', 'i', 't', 'i', 'k', 'a',
    'n', 'a', 'b', 'i', 's'
};
static const symbol s_45[] = {
    'c', 'u', 'd', 'i', 'h', 'a', 'p', 'e',
    's', 'i', 'r'
};
static const symbol s_46[] = { 'd', 'e', 'b', 'a', 't', 'h', 'o', 't' };
static const symbol s_47[] = {
    'd', 'e', 'm', 'o', 'k', 'r', 'a', 'c',
    'i'
};
static const symbol s_48[] = {
    'd', 'e', 'p', 'u', 't', 'e', 't', 'o',
    'v', 'e', 'p', 'r', 'i', 'm', 't', 'a',
    'r', 'i'
};
static const symbol s_49[] = { 'd', 'e', 's', 'h', 'i', 'q' };
static const symbol s_50[] = {
    'd', 'e', 's', 'h', 'm', 'i', 'l', 'i',
    'o', 'n', 'd', 'j', 'e', 'k', 'i', 'm',
    'a', 'n', 'd', 'a', 't'
};
static const symbol s_51[] = {
    'd', 'e', 't', 'y', 'l', 'l', 'o', 'g',
    'a', 'r', 'i'
};
static const symbol s_214[] = {
    'p', 'a', 'r', 't', 'n', 'e', 'r', 'i',
    't', 'e', 't'
};
static const symbol s_238[] = {
    'p', 'r', 'o', 'c', 'e', 'd', 'u', 'r',
    'r', 'e', 's'
};
static const symbol s_210[] = {
    'p', 'a', 'd', 'i', 'a', 'b', 'e', 't',
    'e', 'r', 'a', 'p', 'i'
};
static const symbol s_233[] = {
    'p', 'r', 'i', 'n', 'd', 'a', 'l', 'e',
    's', 't', 'a', 'b', 'i', 'l', 'i', 't',
    'e', 't'
};
static const symbol s_224[] = {
    'p', 'e', 't', 'r', 'i', 't', 'e', 'n',
    't', 'a', 't', 'i', 'v', 'i', 'r', 'u',
    's', 'u', 'k', 's', 'e', 's'
};
static const symbol s_315[] = {
    'u', 'k', 'r', 'a', 'i', 'n', 'c', 'i',
    'd', 'e', 'n', 't'
};
static const symbol s_58[] = { 'd', 'j', 'a', 'l', 'b', 'i' };
static const symbol s_59[] = {
    'd', 'o', 'b', 'i', 'z', 'n', 'e', 's',
    'h', 'e', 'n', 'i', 'm', 'a', 's', 'q'
};
static const symbol s_60[] = { 'd', 'o', 'k', 'u', 'm', 'e', 'n', 't' };
static const symbol s_61[] = {
    'd', 'o', 'l', 'u', 'h', 'e', 'd', 'h',
    'i', 'm', 'e', 'n', 'y'
};
static const symbol s_240[] = {
    'p', 'r', 'o', 'd', 'h', 'u', 'e', 's',
    't', 'r', 'a', 't', 'e', 'g', 'j', 'i'
};
static const symbol s_64[] = {
    'd', 'r', 'e', 'j', 't', 'o', 'r', 'e',
    's', 'h', 'k', 'r', 'e', 's'
};
static const symbol s_65[] = { 'd', 'r', 'e', 'j', 't', 'o', 'r', 'i' };
static const symbol s_66[] = {
    'd', 'u', 'a', 'm', 'b', 'i', 'e', 'n',
    't'
};
static const symbol s_235[] = {
    'p', 'r', 'i', 's', 'h', 't', 'i', 'n',
    'd', 'e', 'r', 't', 'e', 's'
};
static const symbol s_68[] = { 'e', 'k', 'o', 'n', 'o', 'm', 'i' };
static const symbol s_222[] = {
    'p', 'e', 'r', 's', 'o', 'n', 'a', 'l',
    'i', 't', 'e', 't'
};
static const symbol s_243[] = { 'p', 'r', 'o', 'n', 'e', 's', 'i' };
static const symbol s_172[] = {
    'm', 'b', 'a', 's', 'h', 'k', 'i', 's',
    'h', 't', 'e', 's'
};
static const symbol s_231[] = {
    'p', 'o', 'z', 'i', 'c', 'i', 'l', 'e',
    's', 'i'
};
static const symbol s_213[] = {
    'p', 'a', 'r', 't', 'i', 't', 'u', 'l',
    'l'
};
static const symbol s_242[] = {
    'p', 'r', 'o', 'g', 'r', 'e', 's', 'h',
    'q', 'i', 'p', 'e', 'r', 'i'
};
static const symbol s_76[] = {
    'e', 'r', 'd', 'h', 'u', 'n', 'g', 'a',
    'r', 'i'
};
static const symbol s_78[] = {
    'e', 'u', 'r', 'o', 'p', 'e', 'r', 'a',
    'c', 'i'
};
static const symbol s_216[] = { 'p', 'a', 'v', 'a', 'r', 'e', 's', 'i' };
static const symbol s_80[] = {
    'f', 'e', 'j', 'e', 'p', 'e', 'r', 's',
    'i'
};
static const symbol s_81[] = {
    'f', 'e', 'r', 'i', 'z', 'a', 'r', 'm',
    'i', 'q'
};
static const symbol s_174[] = {
    'm', 'b', 'r', 'o', 's', 'h', 'e', 's',
    'h', 'e', 'n', 'd', 'e', 't', 'e', 's',
    'i'
};
static const symbol s_83[] = { 'f', 'j', 'a', 'l', 'i' };
static const symbol s_84[] = { 'f', 'l', 'a', 's', 't', 'r', 'i', 't' };
static const symbol s_85[] = {
    'f', 'o', 't', 'o', 'g', 'r', 'a', 'f',
    'i', 'g', 'u', 'j', 'e', 's', 'j', 'e',
    'l', 'l', 'e', 's'
};
static const symbol s_86[] = {
    'f', 's', 'h', 'a', 't', 'r', 'o', 'p',
    'o', 'l', 'o', 'n', 'i'
};
static const symbol s_87[] = {
    'f', 'u', 'n', 'd', 'j', 'a', 'v', 'u',
    'r', 'a', 'd', 'i', 'o'
};
static const symbol s_88[] = { 'f', 'u', 'n', 'k', 's', 'i' };
static const symbol s_89[] = {
    'f', 'u', 'q', 'i', 'n', 'd', 'u', 's',
    't', 'r', 'i'
};
static const symbol s_90[] = { 'g', 'a', 'r', 'a', 'n', 'c', 'i' };
static const symbol s_91[] = {
    'g', 'a', 't', 'i', 's', 'h', 'm', 'e',
    'r', 'i'
};
static const symbol s_92[] = {
    'g', 'j', 'a', 'k', 'o', 'v', 'e', 'c',
    'o', 'r', 'i'
};
static const symbol s_93[] = { 'g', 'j', 'a', 't', 'e', 's', 'i' };
static const symbol s_94[] = { 'g', 'j', 'e', 'j' };
static const symbol s_95[] = { 'g', 'j', 'e', 'n', 'e', 'v', 'o' };
static const symbol s_96[] = {
    'g', 'j', 'u', 'h', 'y', 'n', 'g', 'j',
    'y'
};
static const symbol s_97[] = { 'g', 'r', 'e', 'q', 'i' };
static const symbol s_98[] = { 'g', 'r', 'e', 'v', 'e', 'l', 'l' };
static const symbol s_99[] = {
    'g', 'r', 'u', 'g', 'o', 'v', 'u', 'l',
    'l', 'n', 'e', 't'
};
static const symbol s_215[] = { 'p', 'a', 's', 'q', 'y' };
static const symbol s_229[] = { 'p', 'o', 'p', 'u', 'l', 'l' };
static const symbol s_177[] = {
    'm', 'e', 'n', 'd', 's', 'h', 't', 'r',
    'e', 's'
};
static const symbol s_165[] = {
    'm', 'a', 'g', 'a', 'z', 'i', 'n', 't',
    'e', 'g', 'r', 'i', 't', 'e', 't'
};
static const symbol s_176[] = {
    'm', 'e', 'k', 'a', 'n', 'i', 'z', 'm',
    'e', 'h', 'm', 'e', 't'
};
static const symbol s_331[] = {
    'v', 'j', 'e', 'n', 'd', 'r', 'r', 'e',
    'a', 'l', 'i', 't', 'e', 't'
};
static const symbol s_330[] = {
    'v', 'i', 't', 'a', 'm', 'i', 'n', 'i',
    's', 't', 'r', 'i'
};
static const symbol s_244[] = {
    'p', 'r', 'o', 'v', 'a', 'j', 'r', 'e',
    'z', 'u', 'l', 't', 'a', 't'
};
static const symbol s_237[] = {
    'p', 'r', 'o', 'b', 'l', 'e', 'm', 'i',
    'g', 'r', 'a', 'n', 't'
};
static const symbol s_226[] = { 'p', 'l', 'a', 'r', 't', 'e', 's', 'i' };
static const symbol s_170[] = {
    'm', 'a', 'r', 't', 'i', 'k', 'u', 'l',
    'l'
};
static const symbol s_169[] = {
    'm', 'a', 'r', 't', 'e', 's', 't', 'r',
    'e', 's', 'o', 'l', 'l'
};
static const symbol s_192[] = {
    'm', 'u', 's', 'l', 'i', 'm', 'o', 's',
    'q'
};
static const symbol s_211[] = {
    'p', 'a', 'g', 'e', 's', 't', 'a', 't',
    'u', 's'
};
static const symbol s_219[] = {
    'p', 'e', 'r', 'm', 'e', 't', 'e', 'o',
    'r', 'i', 'g', 'j', 'i', 'n'
};
static const symbol s_239[] = {
    'p', 'r', 'o', 'c', 'e', 's', 'e', 'l',
    'e', 'm', 'e', 'n', 't'
};
static const symbol s_220[] = {
    'p', 'e', 'r', 'p', 'a', 'r', 'e', 's',
    'i'
};
static const symbol s_322[] = {
    'v', 'a', 'z', 'h', 'd', 'i', 'm', 'e',
    's', 'i'
};
static const symbol s_236[] = {
    'p', 'r', 'i', 't', 's', 'h', 'm', 'e',
    'r', 'i'
};
static const symbol s_232[] = {
    'p', 'r', 'e', 's', 'h', 'e', 'v', 'r',
    'i', 't', 'm', 'u', 'z', 'e', 'd', 'h',
    'e', 'n', 'e', 's', 'h', 'o', 'h', 'i',
    'm', 'e', 'r', 'r'
};
static const symbol s_332[] = {
    'v', 'l', 'e', 'j', 't', 'r', 'u', 'a',
    'l', 'l'
};
static const symbol s_122[] = {
    'k', 'a', 'm', 'p', 'i', 'o', 'n', 'a',
    't', 'y', 'r'
};
static const symbol s_123[] = {
    'k', 'a', 'm', 'r', 'u', 'm', 'a', 'n',
    'i'
};
static const symbol s_245[] = {
    'p', 'u', 's', 'h', 't', 'e', 't', 'a',
    's', 'u', 'e', 'd', 'i', 'a', 's', 'p',
    'o', 'r', 'o', 's', 'i'
};
static const symbol s_125[] = { 'k', 'a', 'n', 'd', 'i', 'd', 'a', 't' };
static const symbol s_126[] = {
    'k', 'a', 'p', 'a', 'c', 'i', 't', 'e',
    't'
};
static const symbol s_127[] = {
    'k', 'a', 'r', 'a', 'n', 't', 'i', 'n',
    'g', 'a', 'r', 'k', 'e', 's'
};
static const symbol s_321[] = {
    'v', 'a', 'k', 's', 'i', 'n', 't', 'e',
    'r', 'e', 's', 'i'
};
static const symbol s_129[] = {
    'k', 'a', 'v', 'o', 'k', 'a', 't', 'e',
    'g', 'o', 'r', 'i'
};
static const symbol s_327[] = {
    'v', 'e', 's', 'h', 't', 'i', 'r', 'e',
    's', 'i'
};
static const symbol s_131[] = {
    'k', 'e', 'r', 'c', 'e', 'n', 'e', 'r',
    'g', 'j', 'i'
};
static const symbol s_132[] = {
    'k', 'e', 'r', 'k', 'e', 's', 'h', 'o',
    'q', 'e', 'r', 'i'
};
static const symbol s_234[] = {
    'p', 'r', 'i', 'o', 'r', 'i', 't', 'e',
    't'
};
static const symbol s_189[] = {
    'm', 'u', 'a', 'k', 's', 'e', 's', 'k',
    'e', 'n', 'a', 'q', 'e', 's', 'i'
};
static const symbol s_135[] = {
    'k', 'l', 'i', 'e', 'n', 't', 'e', 'r',
    'm', 'e', 't'
};
static const symbol s_136[] = {
    'k', 'o', 'k', 'a', 'i', 'n', 't', 'e',
    'r', 'n', 'e', 't'
};
static const symbol s_137[] = {
    'k', 'o', 'm', 'e', 'n', 't', 'r', 'a',
    'j', 'n', 'i', 'm', 'a', 'k', 'i', 'n',
    'e', 'r', 'i'
};
static const symbol s_138[] = { 'k', 'o', 'm', 'i', 's', 'i' };
static const symbol s_139[] = { 'k', 'o', 'm', 'p', 'a', 'n', 'i' };
static const symbol s_140[] = {
    'k', 'o', 'm', 'p', 'r', 'o', 'm', 'i',
    's'
};
static const symbol s_141[] = {
    'k', 'o', 'm', 'u', 'n', 'i', 't', 'e',
    't'
};
static const symbol s_142[] = {
    'k', 'o', 'n', 's', 'e', 'n', 's', 'u',
    's'
};
static const symbol s_143[] = {
    'k', 'o', 'n', 't', 'a', 'b', 'i', 'l',
    'i', 't', 'e', 't'
};
static const symbol s_144[] = {
    'k', 'o', 'n', 't', 'r', 'i', 'b', 'u',
    't'
};
static const symbol s_145[] = {
    'k', 'o', 'n', 'v', 'e', 'n', 't', 'e',
    'p', 'e', 'l', 'e', 'n', 'j', 'e', 'r',
    'i'
};
static const symbol s_146[] = {
    'k', 'o', 'o', 'r', 'd', 'i', 'n', 'j',
    'i', 't', 'e', 't'
};
static const symbol s_147[] = { 'k', 'o', 's', 'o', 'v', 'd', 'i', 'q' };
static const symbol s_148[] = { 'k', 'o', 's', 't', 'o' };
static const symbol s_149[] = { 'k', 'r', 'e', 'd', 'i' };
static const symbol s_150[] = {
    'k', 'r', 'o', 'a', 'c', 'i', 'k', 'l',
    'a', 's'
};
static const symbol s_151[] = {
    'k', 'r', 'r', 'j', 'e', 't', 'e', 's',
    'h', 'k', 'o', 's', 'h', 't', 'e', 'p',
    'i'
};
static const symbol s_152[] = {
    'k', 'r', 'y', 'e', 'q', 'y', 't', 'e',
    't'
};
static const symbol s_153[] = {
    'k', 't', 'h', 'e', 's', 'a', 'n', 'k',
    's', 'i'
};
static const symbol s_156[] = { 'k', 'u', 'l', 't', 'u', 'r', 'q', 'i' };
static const symbol s_155[] = {
    'k', 'u', 'j', 't', 'e', 's', 't', 'u',
    'd', 'e', 'n', 't'
};

static const unsigned short a_0[] = {
    0x0000 , 0xC3C3 , 0x0003 , 0x0000 , 0xA7AB , 0xFFFE , 0xFFFF
};

static const unsigned short a_1[] = {
    0x0000 , 0x7A61 , 0x001C , 0x01A9 , 0x02A6 , 0x02D8 , 0x04B2 , 0x0539 ,
    0x0626 , 0x06CD , 0x080D , 0x08C3 , 0x0908 , 0x0AB6 , 0x0B6E , 0x0DFD ,
    0x0F3C , 0x0F7B , 0x1158 , 0x1197 , 0x1280 , 0x14DA , 0x1636 , 0x169E ,
    0x0000 , 0x0000 , 0x1812 , 0x1822 , 0x0000 , 0x7664 , 0x0031 , 0x0000 ,
    0x0036 , 0x0063 , 0x0000 , 0x0000 , 0x0000 , 0x006D , 0x0097 , 0x00A9 ,
    0x00AF , 0x0000 , 0x00BC , 0x0000 , 0x00D0 , 0x0171 , 0x017E , 0x0183 ,
    0x01A4 , 0x0000 , 0x0004 , 0xFFFF , S(6572), S(6573), 0x0000 , 0x7461 ,
    0x004C , 0x0000 , 0x0000 , 0x0000 , 0x004F , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0054 , 0x0000 , 0x7474 , 0xFFFE , 0x0000 ,
    0x0003 , 0xFFFD , S(7372), S(0069), 0x0000 , 0x0003 , 0x0059 , S(7365),
    S(0069), 0x0004 , 0x7374 , 0x005D , 0x0060 , 0x0000 , 0x6868 , 0xFFFC ,
    0x0000 , 0x6565 , 0xFFFC , 0x0000 , 0x0005 , 0x0069 , S(656A), S(636E),
    S(0069), 0x0005 , 0x0002 , 0xFFFB , S(6574), 0x0000 , 0x7374 , 0x0071 ,
    0x0091 , 0x0000 , 0x6569 , 0x0075 , 0x0078 , 0x0000 , 0x7373 , 0xFFFA ,
    0x0000 , 0x646F , 0x007C , 0x0081 , 0x0000 , 0x0004 , 0xFFF8 , S(6E65),
    S(6574), 0x0000 , 0x0002 , 0x0085 , S(656E), 0x0007 , 0x7673 , 0x008B ,
    0xFFF9 , 0x0000 , 0x008E , 0x0000 , 0x6868 , 0xFFF9 , 0x0000 , 0x6565 ,
    0xFFF9 , 0x0000 , 0x0006 , 0xFFF7 , S(7669), S(7469), S(7465), 0x0000 ,
    0x6265 , 0x009B , 0x00A2 , 0x0000 , 0x0002 , 0x009F , S(6E69), 0x000A ,
    0x6161 , 0xFFF6 , 0x0000 , 0x0007 , 0xFFF5 , S(736B), S(6E61), S(6164),
    S(0072), 0x0000 , 0x0006 , 0xFFF4 , S(6962), S(6E65), S(6574), 0x0000 ,
    0x676B , 0x00B3 , 0x00B7 , 0x0000 , 0x0002 , 0xFFF3 , S(696C), 0x0000 ,
    0x0003 , 0xFFF2 , S(7365), S(0065), 0x0000 , 0x0009 , 0x00C4 , S(696C),
    S(616B), S(6963), S(6E6F), S(0065), 0x000F , 0x7673 , 0x00CA , 0xFFF1 ,
    0x0000 , 0x00CD , 0x0000 , 0x6868 , 0xFFF1 , 0x0000 , 0x6565 , 0xFFF1 ,
    0x0000 , 0x7464 , 0x00E3 , 0x0000 , 0x0000 , 0x00ED , 0x0000 , 0x0000 ,
    0x0000 , 0x00F3 , 0x0000 , 0x00FA , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x00FF , 0x0000 , 0x0160 , 0x0000 , 0x6868 , 0x00E6 , 0x0000 , 0x6575 ,
    0xFFB2 , 0x00EA , 0x0000 , 0x7272 , 0xFFB2 , 0x0000 , 0x0006 , 0xFFF0 ,
    S(6D75), S(6E65), S(6574), 0x0000 , 0x0007 , 0xFFEF , S(6F65), S(6F6C),
    S(6A67), S(0069), 0x0000 , 0x0004 , 0xFFEE , S(7169), S(6574), 0x0000 ,
    0x6969 , 0x0102 , 0x0000 , 0x7468 , 0x0111 , 0x0000 , 0x0121 , 0x0000 ,
    0x0000 , 0x0000 , 0x0134 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x013C , 0x0000 , 0x6565 , 0x0114 , 0x0000 , 0x746A , 0xFFED , 0x0000 ,
    0x0000 , 0x0000 , 0xFFED , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0xFFED , 0x0013 , 0x6E61 , 0xFFED , 0x0000 , 0x0000 , 0x0000 , 0xFFED ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0131 ,
    0x0131 , 0x0000 , 0x6565 , 0xFFED , 0x0013 , 0x6974 , 0x0138 , 0x0131 ,
    0x0013 , 0x6D6E , 0xFFED , 0xFFED , 0x0013 , 0x7561 , 0xFFED , 0x0000 ,
    0x0000 , 0x0000 , 0x0153 , 0x0000 , 0x0000 , 0x0000 , 0xFFED , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x015D , 0x0013 , 0x746D , 0xFFED , 0xFFED , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0xFFED , 0x0000 , 0x7272 , 0xFFED ,
    0x0000 , 0x0004 , 0x0165 , S(6B69), S(6A75), 0x0014 , 0x7673 , 0x016B ,
    0xFFEC , 0x0000 , 0x016E , 0x0000 , 0x6868 , 0xFFEC , 0x0000 , 0x6565 ,
    0xFFEC , 0x0000 , 0x6874 , 0x0175 , 0x0179 , 0x0000 , 0x0002 , 0xFF88 ,
    S(6574), 0x0000 , 0x0003 , 0xFFEB , S(6972), S(0074), 0x0000 , 0x0004 ,
    0xFFEA , S(6968), S(656E), 0x0000 , 0x7374 , 0x0187 , 0x0193 , 0x0000 ,
    0x0002 , 0x018B , S(7274), 0x0000 , 0x6169 , 0x018F , 0xFFE8 , 0x0000 ,
    0x0002 , 0xFFE9 , S(696C), 0x0000 , 0x6F6F , 0x0196 , 0x0000 , 0x6D72 ,
    0x019A , 0x019F , 0x0000 , 0x0003 , 0xFFE7 , S(656A), S(0074), 0x0000 ,
    0x0004 , 0xFFE6 , S(7469), S(7465), 0x0000 , 0x0004 , 0xFFE5 , S(6B6F),
    S(7461), 0x0000 , 0x7561 , 0x01C0 , 0x0000 , 0x0000 , 0x0000 , 0x01F7 ,
    0x0000 , 0x0000 , 0x0000 , 0x0277 , 0x028A , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0292 , 0x0000 , 0x0000 , 0x0298 ,
    0x0000 , 0x736C , 0x01CA , 0x0000 , 0x01CF , 0x0000 , 0x0000 , 0x0000 ,
    0x01DA , 0x01DF , 0x0000 , 0x0004 , 0xFFE4 , S(6B6C), S(6E61), 0x0000 ,
    0x656B , 0x01D3 , 0x01D7 , 0x0000 , 0x0002 , 0xFFE3 , S(6573), 0x0000 ,
    0x6161 , 0xFFE2 , 0x0000 , 0x0003 , 0xFFE1 , S(7A61), S(0069), 0x0000 ,
    0x0002 , 0x01E3 , S(6B68), 0x0000 , 0x6569 , 0x01E7 , 0x01ED , 0x0000 ,
    0x0005 , 0xFFE0 , S(7570), S(696E), S(006D), 0x0021 , 0x7374 , 0x01F1 ,
    0x01F4 , 0x0000 , 0x6868 , 0xFFDF , 0x0000 , 0x6565 , 0xFFDF , 0x0000 ,
    0x7466 , 0x0208 , 0x0000 , 0x020C , 0x0000 , 0x022E , 0x0000 , 0x0000 ,
    0x0000 , 0x0239 , 0x0000 , 0x0000 , 0x0000 , 0x0255 , 0x026A , 0x026D ,
    0x0000 , 0x0002 , 0xFFDE , S(6574), 0x0000 , 0x6575 , 0x0210 , 0x022A ,
    0x0000 , 0x746A , 0xFFDE , 0x0000 , 0x0000 , 0x021D , 0x021D , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0220 , 0xFFDE , 0x0022 , 0x6969 , 0xFFDE ,
    0x0000 , 0x6868 , 0x0223 , 0x0022 , 0x6169 , 0xFFDE , 0x0227 , 0x0000 ,
    0x6E6E , 0xFFDE , 0x0022 , 0x0002 , 0xFFDE , S(696E), 0x0000 , 0x696D ,
    0x0232 , 0x0236 , 0x0000 , 0x0002 , 0xFFDE , S(696E), 0x0000 , 0x6565 ,
    0xFFDE , 0x0022 , 0x7465 , 0xFFDE , 0x0000 , 0x0000 , 0x0000 , 0x024B ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0236 , 0x0022 , 0x746D , 0xFFDE , 0xFFDE , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0xFFDE , 0x0000 , 0x6C61 , 0x0263 ,
    0x0000 , 0x0000 , 0x0000 , 0xFFDE , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0266 , 0x0000 , 0x7474 , 0xFFDD , 0x0000 , 0x0002 ,
    0xFFDC , S(6E69), 0x0000 , 0x6868 , 0xFFDE , 0x0000 , 0x6565 , 0x0270 ,
    0x0022 , 0x6A6A , 0x0273 , 0x0000 , 0x6165 , 0xFFDB , 0xFFDB , 0x0000 ,
    0x657A , 0x027B , 0x0282 , 0x0000 , 0x6D73 , 0xFFDA , 0x027F , 0x0000 ,
    0x6868 , 0xFFDA , 0x0000 , 0x0003 , 0x0287 , S(656E), S(0073), 0x0027 ,
    0x6565 , 0xFFD9 , 0x0000 , 0x0002 , 0x028E , S(7265), 0x0026 , 0x6569 ,
    0xFFDA , 0xFFDA , 0x0000 , 0x0005 , 0xFFD8 , S(7469), S(6E61), S(0069),
    0x0000 , 0x6A78 , 0x029C , 0x02A1 , 0x0000 , 0x0004 , 0xFFD7 , S(6571),
    S(6973), 0x0000 , 0x0003 , 0xFFD6 , S(6568), S(0074), 0x0000 , 0x7565 ,
    0x02B9 , 0x0000 , 0x0000 , 0x0000 , 0x02C3 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x02D4 , 0x0000 , 0x0006 , 0x02BF , S(6572), S(6F6D), S(696E), 0x002B ,
    0x0002 , 0xFFD5 , S(6574), 0x0000 , 0x6B6C , 0x02C7 , 0x02CB , 0x0000 ,
    0x0002 , 0xFFD4 , S(6C65), 0x0000 , 0x0003 , 0x02D0 , S(7365), S(0069),
    0x002D , 0x0002 , 0xFFD3 , S(6574), 0x0000 , 0x0002 , 0xFFD2 , S(6964),
    0x0000 , 0x7561 , 0x02EF , 0x0000 , 0x0000 , 0x0000 , 0x0317 , 0x0000 ,
    0x0000 , 0x036D , 0x03A3 , 0x041D , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0430 , 0x0000 , 0x0000 , 0x046E , 0x0000 , 0x0000 , 0x048E , 0x0000 ,
    0x6C73 , 0x02F3 , 0x02FA , 0x003E , 0x6569 , 0xFFC2 , 0x02F7 , 0x0000 ,
    0x6D6D , 0xFFC2 , 0x0000 , 0x6868 , 0x02FD , 0x0000 , 0x756B , 0x030A ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x030D , 0x0314 , 0x0000 , 0x6161 , 0xFFBD , 0x0000 , 0x6575 , 0xFFBD ,
    0x0311 , 0x0000 , 0x6E6E , 0xFFBD , 0x0000 , 0x7272 , 0xFFBD , 0x0000 ,
    0x7462 , 0x032C , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0xFFC2 , 0x0330 , 0x0000 , 0x0000 , 0x033A ,
    0x0000 , 0x0000 , 0x033F , 0x0364 , 0x0000 , 0x0002 , 0xFFD1 , S(7461),
    0x0000 , 0x0006 , 0x0336 , S(6B6F), S(6172), S(6963), 0x0030 , 0x0002 ,
    0xFFD0 , S(6574), 0x0000 , 0x0004 , 0xFFCF , S(7475), S(7465), 0x0000 ,
    0x6868 , 0x0342 , 0x0000 , 0x6D61 , 0xFFBD , 0x0000 , 0x0000 , 0x0000 ,
    0x0351 , 0x0000 , 0x0000 , 0x0000 , 0x0355 , 0x0000 , 0x0000 , 0x0000 ,
    0x035D , 0x0043 , 0x6D6E , 0xFFBD , 0xFFBD , 0x0043 , 0x0002 , 0x0359 ,
    S(6572), 0x0032 , 0x6E73 , 0xFFCE , 0xFFCE , 0x0000 , 0x6969 , 0x0360 ,
    0x0033 , 0x0002 , 0xFFCD , S(6574), 0x0000 , 0x0003 , 0x0369 , S(7279),
    S(0065), 0x0034 , 0x6E73 , 0xFFCC , 0xFFCC , 0x0000 , 0x7561 , 0x0384 ,
    0x0000 , 0x0000 , 0x0000 , 0x0398 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x039F , 0x007A , 0x746D , 0x038E , 0x0391 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0394 , 0x038E , 0x0000 , 0x6565 ,
    0xFF86 , 0x007A , 0x6565 , 0xFF86 , 0x0000 , 0x0002 , 0xFF86 , S(6568),
    0x0000 , 0x6E6E , 0x039B , 0x0000 , 0x6574 , 0xFF86 , 0x038E , 0x0000 ,
    0x0002 , 0xFFCB , S(656E), 0x0000 , 0x7461 , 0x03B9 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x03C6 , 0x03E9 , 0x03EC , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x040A ,
    0x0415 , 0x0000 , 0x6273 , 0x03BD , 0x03C1 , 0x0000 , 0x0002 , 0xFFCA ,
    S(7465), 0x0000 , 0x0004 , 0xFFC9 , S(6F70), S(6172), 0x003E , 0x7465 ,
    0x03D8 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x03DB , 0x0000 , 0x0000 ,
    0x0000 , 0x03DF , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x03E6 ,
    0x0000 , 0x7474 , 0xFFC2 , 0x0000 , 0x6165 , 0xFFC2 , 0xFFC2 , 0x0000 ,
    0x6969 , 0x03E2 , 0x003E , 0x6D6E , 0xFFC2 , 0xFFC2 , 0x0000 , 0x6565 ,
    0xFFC2 , 0x0000 , 0x6565 , 0xFFC8 , 0x0000 , 0x7461 , 0xFFC8 , 0x0000 ,
    0x0000 , 0x0000 , 0xFFC8 , 0x0000 , 0x0000 , 0x0000 , 0x0402 , 0x0405 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x03E9 , 0x0000 , 0x6D6D , 0xFFC8 , 0x0000 , 0x0004 , 0xFFC7 ,
    S(7469), S(7465), 0x0000 , 0x686B , 0xFFC8 , 0x040E , 0x0000 , 0x0007 ,
    0xFFC6 , S(6972), S(696D), S(696E), S(006D), 0x0000 , 0x6975 , 0xFFC8 ,
    0x0419 , 0x0000 , 0x6E72 , 0xFFC8 , 0xFFC8 , 0x0000 , 0x0002 , 0x0421 ,
    S(6D65), 0x003B , 0x7673 , 0x0427 , 0x042A , 0x0000 , 0x042D , 0x0000 ,
    0x6868 , 0xFFC5 , 0x003B , 0x6565 , 0xFFC5 , 0x0000 , 0x6565 , 0xFFC5 ,
    0x0000 , 0x7362 , 0x0444 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x044B , 0x044F , 0x0000 , 0x0000 , 0x0455 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0466 , 0x0000 , 0x6969 , 0x0447 , 0x003C ,
    0x0002 , 0xFFC4 , S(6574), 0x0000 , 0x6165 , 0xFFBD , 0xFFBD , 0x0000 ,
    0x0006 , 0xFFC3 , S(6D75), S(6E65), S(6574), 0x0043 , 0x6974 , 0x0459 ,
    0x0463 , 0x0043 , 0x746D , 0xFFBD , 0xFFBD , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0xFFBD , 0x0000 , 0x6565 , 0xFFBD , 0x0000 , 0x0002 ,
    0x046A , S(6968), 0x0000 , 0x6E74 , 0xFFBD , 0xFFBD , 0x0000 , 0x0003 ,
    0x0473 , S(6A65), S(0074), 0x0000 , 0x656F , 0x0477 , 0x047B , 0x0000 ,
    0x0002 , 0xFFC0 , S(6973), 0x0000 , 0x7272 , 0x047E , 0x0000 , 0x6569 ,
    0x0482 , 0x048A , 0x0000 , 0x0002 , 0x0486 , S(6873), 0x0000 , 0x6165 ,
    0xFFBF , 0xFFBF , 0x0000 , 0x0002 , 0xFFBE , S(6574), 0x0000 , 0x6172 ,
    0x0492 , 0x04AD , 0x0043 , 0x736A , 0x044B , 0x0000 , 0xFFC2 , 0x0000 ,
    0xFFBD , 0x0000 , 0x0000 , 0x0000 , 0x049E , 0x04AA , 0x003F , 0x7673 ,
    0x04A4 , 0xFFC1 , 0x0000 , 0x04A7 , 0x0000 , 0x6868 , 0xFFC1 , 0x0000 ,
    0x6565 , 0xFFC1 , 0x0000 , 0x6868 , 0xFFBD , 0x0000 , 0x0003 , 0xFFBC ,
    S(6572), S(0073), 0x0000 , 0x7566 , 0x04C4 , 0x0000 , 0x0000 , 0x0000 ,
    0x04CB , 0x04D2 , 0x04DC , 0x04E2 , 0x050B , 0x0000 , 0x0520 , 0x0000 ,
    0x0525 , 0x0000 , 0x0000 , 0x052E , 0x0000 , 0x0008 , 0xFFBB , S(6B69),
    S(7361), S(7469), S(7465), 0x0000 , 0x6161 , 0x04CE , 0x004E , 0x0002 ,
    0xFFB2 , S(696E), 0x0000 , 0x0005 , 0x04D8 , S(6E6F), S(6D6F), S(0069),
    0x0046 , 0x0002 , 0xFFBA , S(6574), 0x0000 , 0x0006 , 0xFFB9 , S(6D65),
    S(6E65), S(6574), 0x0000 , 0x6F61 , 0xFFB8 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x04F3 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x04F9 , 0x0000 , 0x0006 , 0xFFB7 , S(7267), S(6E61),
    S(6574), 0x0000 , 0x0005 , 0x04FF , S(6963), S(6E6F), S(0065), 0x004A ,
    0x7673 , 0x0505 , 0xFFB6 , 0x0000 , 0x0508 , 0x0000 , 0x6868 , 0xFFB6 ,
    0x0000 , 0x6565 , 0xFFB6 , 0x0000 , 0x6465 , 0x050F , 0x0517 , 0x0000 ,
    0x0003 , 0x0514 , S(7265), S(0072), 0x004B , 0x6161 , 0xFFB5 , 0x0000 ,
    0x0004 , 0x051C , S(6772), S(696A), 0x004C , 0x0002 , 0xFFB4 , S(6574),
    0x0000 , 0x0004 , 0xFFB3 , S(7265), S(6973), 0x0000 , 0x6164 , 0xFFB1 ,
    0x0529 , 0x0000 , 0x0003 , 0xFFB2 , S(6568), S(006D), 0x0000 , 0x0002 ,
    0x0532 , S(6F72), 0x0000 , 0x6E73 , 0xFFB0 , 0x0536 , 0x0000 , 0x6868 ,
    0xFFB0 , 0x0000 , 0x7561 , 0x0550 , 0x0000 , 0x0000 , 0x0000 , 0x0561 ,
    0x0000 , 0x0000 , 0x0000 , 0x0571 , 0x057A , 0x0000 , 0x057F , 0x0000 ,
    0x0000 , 0x05C2 , 0x0000 , 0x0000 , 0x0000 , 0x05F4 , 0x0000 , 0x0600 ,
    0x0000 , 0x0007 , 0x0557 , S(6B74), S(7165), S(7365), S(0069), 0x0051 ,
    0x7374 , 0x055B , 0x055E , 0x0000 , 0x6868 , 0xFFAF , 0x0000 , 0x6565 ,
    0xFFAF , 0x0052 , 0x736E , 0x0569 , 0x0000 , 0x0000 , 0x0000 , 0x056C ,
    0x0569 , 0x0000 , 0x6565 , 0xFFAE , 0x0000 , 0x0004 , 0xFFAD , S(7A69),
    S(6A61), 0x0000 , 0x0004 , 0x0576 , S(7567), S(6572), 0x0054 , 0x6E73 ,
    0xFFAC , 0xFFAC , 0x0000 , 0x0003 , 0xFFAB , S(6C61), S(0069), 0x0000 ,
    0x6961 , 0x058A , 0x0000 , 0x0000 , 0x0000 , 0x0594 , 0x0000 , 0x0000 ,
    0x0000 , 0x0597 , 0x0000 , 0x7373 , 0x058D , 0x0056 , 0x6569 , 0xFFAA ,
    0x0591 , 0x0000 , 0x6D6D , 0xFFAA , 0x0000 , 0x7474 , 0xFFAA , 0x0000 ,
    0x7374 , 0x059B , 0x05B2 , 0x0000 , 0x746A , 0x05A8 , 0x0000 , 0x0000 ,
    0x0000 , 0x05AB , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x05A8 ,
    0x0000 , 0x6565 , 0xFFAA , 0x0000 , 0x6969 , 0x05AE , 0x0056 , 0x6D6E ,
    0xFFAA , 0xFFAA , 0x0000 , 0x6565 , 0x05B5 , 0x0000 , 0x746A , 0xFFAA ,
    0x0000 , 0x0000 , 0x0000 , 0xFFAA , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0xFFAA , 0x0000 , 0x6C74 , 0x05C6 , 0x05E4 , 0x0056 , 0x7561 ,
    0xFFAA , 0x0000 , 0x0000 , 0x0000 , 0x05DD , 0x0000 , 0x0000 , 0x0000 ,
    0xFFAA , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x05E1 , 0x0000 , 0x6D6E , 0xFFAA ,
    0xFFAA , 0x0000 , 0x7272 , 0xFFAA , 0x0000 , 0x0006 , 0x05EA , S(676F),
    S(6172), S(6966), 0x0000 , 0x7374 , 0x05EE , 0x05F1 , 0x0000 , 0x6868 ,
    0xFFA9 , 0x0000 , 0x6565 , 0xFFA9 , 0x0000 , 0x0003 , 0x05F9 , S(6168),
    S(0074), 0x0058 , 0x6969 , 0x05FC , 0x0058 , 0x6E74 , 0xFFA8 , 0xFFA8 ,
    0x0000 , 0x6E71 , 0x0604 , 0x061F , 0x0000 , 0x646B , 0x0608 , 0x060D ,
    0x0000 , 0x0004 , 0xFFA7 , S(616A), S(6576), 0x0000 , 0x0005 , 0x0613 ,
    S(6973), S(6E6F), S(0065), 0x005A , 0x7673 , 0x0619 , 0xFFA6 , 0x0000 ,
    0x061C , 0x0000 , 0x6868 , 0xFFA6 , 0x0000 , 0x6565 , 0xFFA6 , 0x0000 ,
    0x6969 , 0x0622 , 0x005B , 0x0002 , 0xFFA5 , S(6574), 0x0000 , 0x7261 ,
    0x063A , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x064E , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x06B3 , 0x0000 , 0x7274 , 0x063E , 0x0647 , 0x0000 , 0x0004 ,
    0x0643 , S(6E61), S(6963), 0x005C , 0x0002 , 0xFFA4 , S(6574), 0x0000 ,
    0x0007 , 0xFFA3 , S(7369), S(6D68), S(7265), S(0069), 0x0000 , 0x7561 ,
    0x0665 , 0x0000 , 0x0000 , 0x0000 , 0x0673 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x06AB , 0x0000 , 0x6B74 , 0x0669 ,
    0x066E , 0x0000 , 0x0003 , 0xFFA2 , S(766F), S(0065), 0x0000 , 0x0003 ,
    0xFFA1 , S(7365), S(0069), 0x0000 , 0x746A , 0x0680 , 0x0000 , 0x0000 ,
    0x0000 , 0x068F , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x06A8 ,
    0x0060 , 0x6E65 , 0xFFA0 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x068C , 0x068C , 0x0000 , 0x6565 , 0xFFA0 , 0x0000 ,
    0x7465 , 0x06A1 , 0x0000 , 0x0000 , 0x0000 , 0x06A5 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x068C , 0x0000 , 0x0002 , 0xFF9F , S(6576), 0x0000 , 0x6D6D , 0xFFA0 ,
    0x0000 , 0x6969 , 0xFFA0 , 0x0000 , 0x0002 , 0x06AF , S(6568), 0x0000 ,
    0x6E74 , 0xFF9E , 0xFF9E , 0x0000 , 0x6165 , 0x06B7 , 0x06C3 , 0x0065 ,
    0x7673 , 0x06BD , 0x06C0 , 0x0000 , 0x06C0 , 0x0000 , 0x6868 , 0xFF9B ,
    0x0000 , 0x6565 , 0xFF9B , 0x0000 , 0x7176 , 0x06C7 , 0x06CA , 0x0000 ,
    0x6969 , 0xFF9D , 0x0000 , 0x6565 , 0xFF9C , 0x0000 , 0x7961 , 0x06E8 ,
    0x0000 , 0x0000 , 0x0000 , 0x0707 , 0x0000 , 0x0000 , 0x0000 , 0x075D ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x07B1 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x07D6 , 0x0000 , 0x0000 , 0x0000 , 0x07DC ,
    0x0000 , 0x7870 , 0x06F3 , 0x0000 , 0x0700 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0703 , 0x0000 , 0x0005 , 0x06F9 , S(7365), S(7269),
    S(0061), 0x0066 , 0x7476 , 0xFF9A , 0x06FD , 0x0000 , 0x6565 , 0xFF9A ,
    0x0000 , 0x6969 , 0xFFED , 0x0000 , 0x0002 , 0xFF99 , S(6968), 0x0000 ,
    0x7264 , 0x0718 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0739 , 0x0756 ,
    0x0000 , 0x6868 , 0x071B , 0x0068 , 0x7565 , 0x072E , 0x0000 , 0x0000 ,
    0x0000 , 0x0732 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0735 , 0x0068 , 0x0002 ,
    0xFF98 , S(6873), 0x0000 , 0x6E6E , 0xFF98 , 0x0000 , 0x6E72 , 0xFF98 ,
    0xFF98 , 0x006A , 0x7565 , 0x074C , 0x0000 , 0x0000 , 0x0000 , 0x0750 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0753 , 0x006A , 0x0002 , 0xFF96 , S(6873),
    0x0000 , 0x6E6E , 0xFF96 , 0x0000 , 0x7272 , 0xFF96 , 0x0000 , 0x0008 ,
    0xFF97 , S(6563), S(6F67), S(6976), S(656E), 0x0000 , 0x7364 , 0x076F ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x079D , 0x0000 , 0x07A8 , 0x0000 ,
    0x6868 , 0x0772 , 0x0068 , 0x6E65 , 0x077E , 0x0000 , 0x0000 , 0x0000 ,
    0x0793 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0797 , 0x0000 , 0x746A ,
    0xFF98 , 0x0000 , 0x0000 , 0x0000 , 0x078B , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x078E , 0xFF98 , 0x0068 , 0x6969 , 0xFF98 , 0x0000 , 0x0003 ,
    0xFF98 , S(6968), S(006E), 0x0000 , 0x0002 , 0xFF98 , S(696E), 0x0000 ,
    0x6969 , 0x079A , 0x0068 , 0x6E6E , 0xFF98 , 0x0000 , 0x6974 , 0x07A1 ,
    0x07A5 , 0x0000 , 0x0002 , 0xFF96 , S(696E), 0x0000 , 0x6565 , 0xFF96 ,
    0x0000 , 0x0004 , 0x07AD , S(6F74), S(6972), 0x006B , 0x0002 , 0xFF95 ,
    S(6574), 0x0000 , 0x6471 , 0x07B5 , 0x07C7 , 0x0000 , 0x6868 , 0x07B8 ,
    0x0068 , 0x6961 , 0xFF98 , 0x0000 , 0x0000 , 0x0000 , 0x07C3 , 0x0000 ,
    0x0000 , 0x0000 , 0xFF98 , 0x0000 , 0x6D6E , 0xFF98 , 0xFF98 , 0x006A ,
    0x6961 , 0xFF96 , 0x0000 , 0x0000 , 0x0000 , 0x07D2 , 0x0000 , 0x0000 ,
    0x0000 , 0xFF96 , 0x0000 , 0x6D6E , 0xFF96 , 0xFF96 , 0x0000 , 0x0005 ,
    0xFF94 , S(676E), S(7261), S(0069), 0x006D , 0x7368 , 0x07EA , 0x0000 ,
    0x07EE , 0x0800 , 0x0000 , 0x07FD , 0x0803 , 0x0000 , 0x0000 , 0x0000 ,
    0x0807 , 0x080A , 0x0000 , 0x0002 , 0xFF93 , S(7465), 0x0000 , 0x6D61 ,
    0xFF93 , 0x0000 , 0x0000 , 0x0000 , 0xFF93 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x07FD , 0x0000 , 0x6565 , 0xFF93 ,
    0x0000 , 0x6161 , 0xFF93 , 0x0000 , 0x0002 , 0xFF93 , S(6574), 0x006D ,
    0x6565 , 0xFF93 , 0x0000 , 0x6868 , 0xFF93 , 0x0000 , 0x7364 , 0x081F ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x082C , 0x0000 , 0x08B5 , 0x0000 , 0x0000 , 0x08B9 , 0x0000 ,
    0x6565 , 0x0822 , 0x0000 , 0x7374 , 0x0826 , 0x0829 , 0x0000 , 0x6868 ,
    0xFF92 , 0x0000 , 0x6565 , 0xFF92 , 0x0000 , 0x7463 , 0x0840 , 0x0846 ,
    0x0000 , 0x0850 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0879 , 0x088D ,
    0x0000 , 0x0006 , 0xFF91 , S(6469), S(6E65), S(6574), 0x0000 , 0x0005 ,
    0x084C , S(7375), S(7274), S(0069), 0x0070 , 0x0002 , 0xFF90 , S(6574),
    0x0000 , 0x656F , 0x0854 , 0x0866 , 0x0000 , 0x0006 , 0x085A , S(736B),
    S(6F69), S(656E), 0x0071 , 0x7673 , 0x0860 , 0xFF8F , 0x0000 , 0x0863 ,
    0x0000 , 0x6868 , 0xFF8F , 0x0000 , 0x6565 , 0xFF8F , 0x0000 , 0x0008 ,
    0x086D , S(6D72), S(6361), S(6F69), S(656E), 0x0072 , 0x7673 , 0x0873 ,
    0xFF8E , 0x0000 , 0x0876 , 0x0000 , 0x6868 , 0xFF8E , 0x0000 , 0x6565 ,
    0xFF8E , 0x0000 , 0x0009 , 0x0881 , S(6974), S(7574), S(6963), S(6E6F),
    S(0065), 0x0073 , 0x7673 , 0x0887 , 0xFF8D , 0x0000 , 0x088A , 0x0000 ,
    0x6868 , 0xFF8D , 0x0000 , 0x6565 , 0xFF8D , 0x0000 , 0x6565 , 0x0890 ,
    0x0000 , 0x7267 , 0x089E , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x08A4 , 0x0000 , 0x0000 , 0x0000 , 0x08AA , 0x0000 , 0x0005 ,
    0xFF8C , S(6972), S(6574), S(0074), 0x0000 , 0x0005 , 0xFF8B , S(6973),
    S(6574), S(0074), 0x0000 , 0x656E , 0x08AE , 0x08B1 , 0x0000 , 0x7373 ,
    0xFF8A , 0x0000 , 0x0002 , 0xFF89 , S(7465), 0x007A , 0x0002 , 0xFF86 ,
    S(7465), 0x0000 , 0x6868 , 0x08BC , 0x0000 , 0x6569 , 0xFF88 , 0x08C0 ,
    0x0000 , 0x7474 , 0xFF88 , 0x0000 , 0x6961 , 0x08CE , 0x0000 , 0x0000 ,
    0x0000 , 0x08EA , 0x0000 , 0x0000 , 0x0000 , 0x0904 , 0x0000 , 0x7070 ,
    0x08D1 , 0x007A , 0x6F65 , 0x08DE , 0x0000 , 0x0000 , 0x0000 , 0x08E2 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x08E6 , 0x007A , 0x0002 ,
    0xFF86 , S(6873), 0x0000 , 0x6D6E , 0xFF86 , 0xFF86 , 0x0000 , 0x0002 ,
    0xFF87 , S(696E), 0x0000 , 0x746D , 0xFF88 , 0x0000 , 0x0000 , 0x08F4 ,
    0x0000 , 0x0000 , 0x08FC , 0x08FF , 0x0000 , 0x6974 , 0x08F8 , 0x038E ,
    0x0000 , 0x0002 , 0xFF86 , S(696E), 0x0000 , 0x6868 , 0xFF88 , 0x0000 ,
    0x0003 , 0xFF85 , S(7365), S(0065), 0x0078 , 0x0002 , 0xFF88 , S(696E),
    0x0000 , 0x7561 , 0x091F , 0x0000 , 0x0000 , 0x0000 , 0x0969 , 0x0000 ,
    0x0000 , 0x0000 , 0x0996 , 0x0000 , 0x0000 , 0x099B , 0x0000 , 0x0000 ,
    0x09A8 , 0x0000 , 0x0000 , 0x0A39 , 0x0000 , 0x0A6A , 0x0A6F , 0x0000 ,
    0x766D , 0x092B , 0x0940 , 0x0000 , 0x094E , 0x0000 , 0x0954 , 0x0000 ,
    0x095A , 0x0000 , 0x0964 , 0x0000 , 0x6570 , 0x092F , 0x093A , 0x0000 ,
    0x0002 , 0x0933 , S(6172), 0x007D , 0x7476 , 0xFF83 , 0x0937 , 0x0000 ,
    0x6565 , 0xFF83 , 0x0000 , 0x0005 , 0xFF84 , S(6F69), S(616E), S(0074),
    0x0000 , 0x6164 , 0x0944 , 0x0949 , 0x0000 , 0x0003 , 0xFF82 , S(6962),
    S(0073), 0x0000 , 0x0004 , 0xFF81 , S(6469), S(7461), 0x0000 , 0x0006 ,
    0xFF80 , S(6361), S(7469), S(7465), 0x0000 , 0x0006 , 0xFF7F , S(6E61),
    S(6974), S(656E), 0x0000 , 0x0005 , 0x0960 , S(6765), S(726F), S(0069),
    0x0082 , 0x0002 , 0xFF7E , S(6574), 0x0000 , 0x0004 , 0xFF7D , S(6A61),
    S(7365), 0x0000 , 0x726D , 0x0971 , 0x0974 , 0x0000 , 0x0000 , 0x0000 ,
    0x0988 , 0x0087 , 0x6969 , 0xFF79 , 0x0000 , 0x6961 , 0x097F , 0x0000 ,
    0x0000 , 0x0000 , 0xFF79 , 0x0000 , 0x0000 , 0x0000 , 0xFF79 , 0x0000 ,
    0x0004 , 0x0984 , S(6571), S(6973), 0x0084 , 0x0002 , 0xFF7C , S(6574),
    0x0000 , 0x636B , 0x098C , 0x0991 , 0x0000 , 0x0004 , 0xFF7B , S(6E65),
    S(6D69), 0x0000 , 0x0003 , 0xFF7A , S(7365), S(0065), 0x0000 , 0x0004 ,
    0xFF79 , S(6873), S(6D69), 0x0000 , 0x6169 , 0x099F , 0x09A3 , 0x0000 ,
    0x0002 , 0xFF78 , S(6573), 0x0000 , 0x0004 , 0xFF77 , S(6E65), S(6574),
    0x0000 , 0x736B , 0x09B3 , 0x0000 , 0x09B8 , 0x0A03 , 0x0A24 , 0x0000 ,
    0x0000 , 0x0000 , 0x0A2A , 0x0000 , 0x0004 , 0xFF76 , S(6961), S(656E),
    0x0000 , 0x7565 , 0x09CB , 0x0000 , 0x0000 , 0x0000 , 0x09D0 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x09DD , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x09F7 , 0x0000 , 0x0003 , 0xFF75 , S(746E), S(0065),
    0x0000 , 0x0005 , 0x09D6 , S(6973), S(6E6F), S(0065), 0x008C , 0x7476 ,
    0xFF74 , 0x09DA , 0x0000 , 0x6565 , 0xFF74 , 0x0000 , 0x6172 , 0x09E1 ,
    0x09EF , 0x0000 , 0x0002 , 0x09E5 , S(696E), 0x008D , 0x7374 , 0x09E9 ,
    0x09EC , 0x0000 , 0x6868 , 0xFF73 , 0x0000 , 0x6565 , 0xFF73 , 0x0000 ,
    0x0004 , 0x09F4 , S(6D6F), S(7369), 0x008E , 0x6565 , 0xFF72 , 0x0000 ,
    0x6E6E , 0x09FA , 0x0000 , 0x6569 , 0xFF71 , 0x09FE , 0x0000 , 0x0003 ,
    0xFF70 , S(6574), S(0074), 0x0000 , 0x7673 , 0x0A09 , 0x0A0F , 0x0000 ,
    0x0A1F , 0x0000 , 0x0005 , 0xFF6F , S(6E65), S(7573), S(0073), 0x0000 ,
    0x6172 , 0x0A13 , 0x0A1A , 0x0000 , 0x0007 , 0xFF6E , S(6962), S(696C),
    S(6574), S(0074), 0x0000 , 0x0004 , 0xFF6D , S(6269), S(7475), 0x0000 ,
    0x0004 , 0xFF6C , S(6E65), S(6574), 0x0000 , 0x0006 , 0xFF6B , S(6472),
    S(6E69), S(6D69), 0x0000 , 0x6F74 , 0x0A2E , 0x0A35 , 0x0000 , 0x7676 ,
    0x0A31 , 0x0000 , 0x6165 , 0xFF6A , 0xFF6A , 0x0000 , 0x0002 , 0xFF69 ,
    S(6E6F), 0x0000 , 0x7965 , 0x0A50 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0A5F , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0A64 ,
    0x0000 , 0x6475 , 0x0A54 , 0x0A5B , 0x0000 , 0x6969 , 0x0A57 , 0x0098 ,
    0x0002 , 0xFF68 , S(6574), 0x0000 , 0x6E74 , 0xFF66 , 0xFF66 , 0x0000 ,
    0x0003 , 0xFF67 , S(6361), S(0069), 0x0000 , 0x0006 , 0xFF65 , S(7165),
    S(7479), S(7465), 0x0000 , 0x0004 , 0xFF64 , S(6568), S(6573), 0x0000 ,
    0x7A66 , 0x0A86 , 0x0000 , 0x0000 , 0x0000 , 0x0AA3 , 0x0000 , 0x0AA8 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0AB1 , 0x0000 , 0x6969 ,
    0x0A89 , 0x009D , 0x6A6E , 0x0A8D , 0x0A9C , 0x009D , 0x7673 , 0x0A93 ,
    0x0A96 , 0x0000 , 0x0A99 , 0x0000 , 0x6868 , 0xFF63 , 0x009D , 0x6565 ,
    0xFF63 , 0x0000 , 0x6565 , 0xFF63 , 0x0000 , 0x6A6A , 0x0A9F , 0x009D ,
    0x7476 , 0x0A99 , 0x0A99 , 0x0000 , 0x0004 , 0xFF62 , S(6574), S(6573),
    0x0000 , 0x0004 , 0x0AAD , S(7574), S(6572), 0x009F , 0x6E73 , 0xFF61 ,
    0xFF61 , 0x0000 , 0x0004 , 0xFF60 , S(6968), S(656E), 0x0000 , 0x7561 ,
    0x0ACD , 0x0000 , 0x0000 , 0x0000 , 0x0ADE , 0x0000 , 0x0000 , 0x0000 ,
    0x0AF3 , 0x0000 , 0x0000 , 0x0B1D , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0B23 , 0x0000 , 0x7273 , 0x0AD1 ,
    0x0ADA , 0x0000 , 0x0004 , 0x0AD6 , S(6574), S(6973), 0x00A1 , 0x0002 ,
    0xFF5F , S(6574), 0x0000 , 0x0002 , 0xFF5C , S(6568), 0x0000 , 0x746E ,
    0x0AE7 , 0x0000 , 0x0000 , 0x0000 , 0x0AEA , 0x0000 , 0x0AEE , 0x0000 ,
    0x6565 , 0xFF5C , 0x0000 , 0x6569 , 0xFF5C , 0xFF5C , 0x0000 , 0x0004 ,
    0xFF5E , S(7265), S(6973), 0x0000 , 0x7263 , 0x0B05 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0B0A , 0x0000 , 0x0000 , 0x0000 , 0x0B18 , 0x0000 , 0x0004 , 0xFF5D ,
    S(6E65), S(6173), 0x0000 , 0x6974 , 0x0B0E , 0x0AE7 , 0x00A4 , 0x746D ,
    0xFF5C , 0xFF5C , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0xFF5C ,
    0x0000 , 0x0003 , 0xFF5B , S(7469), S(0065), 0x0000 , 0x0005 , 0xFF5A ,
    S(676F), S(7261), S(0069), 0x0000 , 0x6161 , 0x0B26 , 0x0000 , 0x736A ,
    0x0B32 , 0x0000 , 0x0000 , 0x0000 , 0x0B52 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0B6B , 0x00A7 , 0x7461 , 0xFF59 , 0x0000 , 0x0000 , 0x0000 ,
    0xFF59 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0B48 , 0x0B48 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0B4B ,
    0x0000 , 0x6565 , 0xFF59 , 0x00A7 , 0x6975 , 0xFF59 , 0x0B4F , 0x0000 ,
    0x7272 , 0xFF59 , 0x0000 , 0x7461 , 0xFF59 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0B68 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0B48 ,
    0x0000 , 0x6D6D , 0xFF59 , 0x0000 , 0x6868 , 0xFF59 , 0x0000 , 0x7561 ,
    0x0B85 , 0x0BE2 , 0x0000 , 0x0000 , 0x0D02 , 0x0000 , 0x0000 , 0x0000 ,
    0x0D55 , 0x0D83 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0D91 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0DB0 , 0x0000 , 0x7367 , 0x0B94 ,
    0x0000 , 0x0000 , 0x0000 , 0x0B9A , 0x0000 , 0x0000 , 0x0BA7 , 0x0000 ,
    0x0000 , 0x0BAC , 0x0BB2 , 0x0BD2 , 0x0000 , 0x0005 , 0xFF58 , S(7A61),
    S(6E69), S(0065), 0x0000 , 0x0003 , 0x0B9F , S(6E69), S(0065), 0x00A9 ,
    0x0002 , 0x0BA3 , S(6972), 0x00AA , 0x0002 , 0xFF56 , S(6574), 0x0000 ,
    0x0003 , 0xFF55 , S(6164), S(0074), 0x0000 , 0x0005 , 0xFF54 , S(6465),
    S(6E6F), S(0069), 0x0000 , 0x7469 , 0x0BC0 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0BC4 , 0x0000 , 0x0BC7 ,
    0x0000 , 0x6D6E , 0xFF49 , 0xFF49 , 0x00B7 , 0x6565 , 0xFF49 , 0x0000 ,
    0x6569 , 0x0BCB , 0x0BCF , 0x0000 , 0x0002 , 0xFF53 , S(6573), 0x0000 ,
    0x6E6E , 0xFF52 , 0x0000 , 0x686B , 0x0BD6 , 0x0BDF , 0x0000 , 0x0004 ,
    0x0BDB , S(756B), S(6C6C), 0x00B8 , 0x0002 , 0xFF48 , S(6E69), 0x0000 ,
    0x6161 , 0xFF51 , 0x0000 , 0x7261 , 0x0BF6 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0C5A ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0CA5 , 0x0000 , 0x6E68 ,
    0x0BFF , 0x0000 , 0x0C17 , 0x0000 , 0x0000 , 0x0000 , 0x0C56 , 0x0000 ,
    0x6565 , 0x0C02 , 0x0000 , 0x746A , 0xFF50 , 0x0000 , 0x0000 , 0x0C0F ,
    0xFF50 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0C12 , 0xFF50 , 0x0000 ,
    0x6969 , 0xFF50 , 0x0000 , 0x0003 , 0xFF50 , S(6968), S(006E), 0x00B0 ,
    0x7461 , 0xFF50 , 0x0000 , 0x0000 , 0x0000 , 0x0C2D , 0x0000 , 0x0000 ,
    0x0000 , 0x0C31 , 0x0000 , 0x0000 , 0x0000 , 0x0C35 , 0x0C35 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0C38 , 0x00B0 , 0x0002 , 0xFF50 ,
    S(696E), 0x0000 , 0x0002 , 0xFF50 , S(696E), 0x0000 , 0x6565 , 0xFF50 ,
    0x00B0 , 0x7561 , 0xFF50 , 0x0000 , 0x0000 , 0x0000 , 0x0C4F , 0x0000 ,
    0x0000 , 0x0000 , 0xFF50 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0C53 , 0x00B0 ,
    0x6D6E , 0xFF50 , 0xFF50 , 0x0000 , 0x7272 , 0xFF50 , 0x00B0 , 0x6974 ,
    0x0C4F , 0x0C35 , 0x0000 , 0x6F65 , 0x0C67 , 0x0000 , 0x0000 , 0x0000 ,
    0x0C89 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0C9D , 0x0000 ,
    0x0002 , 0x0C6B , S(6864), 0x00B1 , 0x7565 , 0x0C7E , 0x0000 , 0x0000 ,
    0x0000 , 0x0C82 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0C86 , 0x00B1 , 0x0002 ,
    0xFF4F , S(6873), 0x0000 , 0x6D6E , 0xFF4F , 0xFF4F , 0x0000 , 0x7272 ,
    0xFF4F , 0x0000 , 0x0002 , 0x0C8D , S(6864), 0x0000 , 0x6574 , 0x0C91 ,
    0x0C9A , 0x0000 , 0x6A73 , 0xFF4F , 0x0C95 , 0x0000 , 0x0003 , 0xFF4F ,
    S(6968), S(006E), 0x0000 , 0x6565 , 0xFF4F , 0x0000 , 0x0002 , 0x0CA1 ,
    S(6864), 0x00B1 , 0x6569 , 0x0C82 , 0xFF4F , 0x0000 , 0x6F6F , 0x0CA8 ,
    0x0000 , 0x6E68 , 0x0CB1 , 0x0000 , 0x0CCC , 0x0000 , 0x0000 , 0x0000 ,
    0x0CFE , 0x0000 , 0x6565 , 0x0CB4 , 0x0000 , 0x746A , 0xFF4E , 0x0000 ,
    0x0000 , 0x0CC1 , 0x0CC4 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0CC7 ,
    0xFF4E , 0x0000 , 0x6969 , 0xFF4E , 0x00B2 , 0x6969 , 0xFF4E , 0x0000 ,
    0x0003 , 0xFF4E , S(6968), S(006E), 0x00B2 , 0x7465 , 0xFF4E , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0CDE , 0x0CDE ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0CE1 , 0x0000 , 0x6565 ,
    0xFF4E , 0x00B2 , 0x7561 , 0xFF4E , 0x0000 , 0x0000 , 0x0000 , 0x0CF8 ,
    0x0000 , 0x0000 , 0x0000 , 0xFF4E , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0CFB ,
    0x00B2 , 0x6E6E , 0xFF4E , 0x0000 , 0x7272 , 0xFF4E , 0x00B2 , 0x6974 ,
    0x0CF8 , 0x0CDE , 0x0000 , 0x7368 , 0x0D10 , 0x0000 , 0x0000 , 0x0D15 ,
    0x0000 , 0x0000 , 0x0D1B , 0x0000 , 0x0000 , 0x0000 , 0x0D2B , 0x0D4F ,
    0x0000 , 0x0003 , 0xFF4D , S(656D), S(0074), 0x0000 , 0x0006 , 0xFF4C ,
    S(6E61), S(7A69), S(6D65), 0x0000 , 0x6479 , 0x0D1F , 0x0D23 , 0x00B5 ,
    0x0002 , 0xFF4B , S(6574), 0x0000 , 0x0002 , 0x0D27 , S(6572), 0x00B6 ,
    0x6E73 , 0xFF4A , 0xFF4A , 0x0000 , 0x7465 , 0x0D3D , 0x0000 , 0x0000 ,
    0x0000 , 0xFF49 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0D41 , 0x0000 ,
    0x0000 , 0x0000 , 0x0D44 , 0x0000 , 0x0D48 , 0x0000 , 0x6E74 , 0xFF49 ,
    0xFF49 , 0x0000 , 0x6969 , 0xFF49 , 0x0000 , 0x7475 , 0x0D48 , 0x0D4B ,
    0x0000 , 0x6565 , 0xFF49 , 0x0000 , 0x0002 , 0xFF49 , S(696E), 0x0000 ,
    0x0005 , 0xFF48 , S(6B68), S(6A75), S(0074), 0x0000 , 0x726C , 0x0D5E ,
    0x0000 , 0x0D6E , 0x0000 , 0x0000 , 0x0D75 , 0x0D7F , 0x0000 , 0x696A ,
    0x0D62 , 0x0D6A , 0x0000 , 0x0002 , 0x0D66 , S(6E6F), 0x00B9 , 0x6569 ,
    0xFF47 , 0xFF47 , 0x0000 , 0x0002 , 0xFF47 , S(6E6F), 0x0000 , 0x0007 ,
    0xFF46 , S(7369), S(7274), S(7469), S(0065), 0x0000 , 0x7374 , 0x0D79 ,
    0x0D7C , 0x0000 , 0x6868 , 0xFF45 , 0x00BB , 0x6565 , 0xFF45 , 0x0000 ,
    0x0002 , 0x0D3D , S(6572), 0x0000 , 0x6565 , 0x0D86 , 0x0000 , 0x6474 ,
    0x0D8A , 0xFF43 , 0x0000 , 0x0002 , 0x0D8E , S(7369), 0x00BC , 0x6565 ,
    0xFF44 , 0x0000 , 0x746D , 0x0D9B , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0DA0 , 0x0DA7 , 0x0DAB , 0x0000 , 0x0004 , 0xFF42 , S(6E65), S(6574),
    0x0000 , 0x6565 , 0x0DA3 , 0x0000 , 0x6D74 , 0xFF49 , 0xFF49 , 0x0000 ,
    0x0002 , 0xFF41 , S(616B), 0x0000 , 0x0003 , 0xFF40 , S(7669), S(0065),
    0x0000 , 0x7A61 , 0x0DCC , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0DD3 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0DEB , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0DF8 , 0x0000 , 0x6A72 , 0x0DD0 , 0xFF49 ,
    0x0000 , 0x7474 , 0xFF3F , 0x0000 , 0x6467 , 0x0DD7 , 0x0DE6 , 0x0000 ,
    0x0003 , 0x0DDC , S(7365), S(0069), 0x00C2 , 0x7374 , 0x0DE0 , 0x0DE3 ,
    0x0000 , 0x6868 , 0xFF3E , 0x00C2 , 0x6565 , 0xFF3E , 0x0000 , 0x0003 ,
    0xFF3D , S(7365), S(0065), 0x0000 , 0x0006 , 0x0DF1 , S(696C), S(616D),
    S(656E), 0x0000 , 0x7476 , 0xFF3C , 0x0DF5 , 0x0000 , 0x6565 , 0xFF3C ,
    0x0000 , 0x0003 , 0xFF3B , S(7465), S(0065), 0x0000 , 0x7861 , 0x0E17 ,
    0x0000 , 0x0000 , 0x0E20 , 0x0EA1 , 0x0000 , 0x0EB4 , 0x0000 , 0x0000 ,
    0x0EF2 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0F04 , 0x0000 ,
    0x0004 , 0x0E1C , S(7974), S(6172), 0x00C7 , 0x0002 , 0xFF39 , S(6576),
    0x0000 , 0x6F61 , 0x0E31 , 0x0000 , 0x0000 , 0x0000 , 0x0E36 , 0x0000 ,
    0x0000 , 0x0000 , 0x0E3C , 0x0E72 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0E8F , 0x0000 , 0x0004 , 0xFF38 , S(656C), S(6573), 0x0000 , 0x0005 ,
    0xFF37 , S(7472), S(7365), S(0065), 0x0000 , 0x7171 , 0x0E3F , 0x00CA ,
    0x7465 , 0x0E51 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0E66 , 0x0000 ,
    0x0000 , 0x0000 , 0x0E69 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0E6F , 0x00CA , 0x746A , 0xFF36 , 0x0000 , 0x0000 , 0x0000 , 0x0E5E ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0E61 , 0xFF36 , 0x00CA , 0x6969 ,
    0xFF36 , 0x0000 , 0x0003 , 0xFF36 , S(6968), S(006E), 0x0000 , 0x6161 ,
    0xFF36 , 0x0000 , 0x6969 , 0x0E6C , 0x00CA , 0x6E6E , 0xFF36 , 0x0000 ,
    0x6565 , 0xFF36 , 0x0000 , 0x0002 , 0x0E76 , S(6B65), 0x00CA , 0x7565 ,
    0xFF36 , 0x0000 , 0x0000 , 0x0000 , 0x0E89 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0E8C , 0x0000 , 0x6E6E , 0xFF36 , 0x0000 , 0x7272 , 0xFF36 , 0x0000 ,
    0x7171 , 0x0E92 , 0x00CA , 0x6961 , 0xFF36 , 0x0000 , 0x0000 , 0x0000 ,
    0x0E9D , 0x0000 , 0x0000 , 0x0000 , 0xFF36 , 0x0000 , 0x6D6E , 0xFF36 ,
    0xFF36 , 0x0000 , 0x7476 , 0x0EA5 , 0x0EAF , 0x00C6 , 0x6565 , 0x0EA8 ,
    0x0000 , 0x7476 , 0xFF3A , 0x0EAC , 0x0000 , 0x6565 , 0xFF3A , 0x0000 ,
    0x0003 , 0xFF35 , S(6A6F), S(0065), 0x0000 , 0x7261 , 0x0EC8 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0ECE ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0ED7 ,
    0x0000 , 0x0005 , 0xFF34 , S(6B72), S(7365), S(0065), 0x0000 , 0x0003 ,
    0x0ED3 , S(7279), S(0065), 0x00CD , 0x6E73 , 0xFF33 , 0xFF33 , 0x0000 ,
    0x6569 , 0x0EDB , 0x0EE5 , 0x00CE , 0x6A73 , 0x0EDF , 0x0EE2 , 0x0000 ,
    0x6565 , 0xFF32 , 0x0000 , 0x6868 , 0xFF32 , 0x0000 , 0x7474 , 0x0EE8 ,
    0x0000 , 0x6575 , 0x0EEC , 0x0EEF , 0x0000 , 0x6D6D , 0xFF32 , 0x0000 ,
    0x7272 , 0xFF32 , 0x0000 , 0x6565 , 0x0EF5 , 0x0000 , 0x7273 , 0x0EF9 ,
    0x0F01 , 0x0000 , 0x0002 , 0x0EFD , S(7A65), 0x00CF , 0x0002 , 0xFF31 ,
    S(6576), 0x0000 , 0x6969 , 0xFF30 , 0x0000 , 0x6F69 , 0x0F0D , 0x0F12 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0F1E , 0x0000 , 0x0004 , 0xFF2F ,
    S(7272), S(6574), 0x0000 , 0x0003 , 0x0F17 , S(7265), S(0072), 0x00D1 ,
    0x6569 , 0xFF2F , 0x0F1B , 0x0000 , 0x6D6D , 0xFF2F , 0x0000 , 0x7272 ,
    0x0F21 , 0x00D1 , 0x7261 , 0xFF2F , 0x0000 , 0x0000 , 0x0000 , 0x0F35 ,
    0x0000 , 0x0000 , 0x0000 , 0xFF2F , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0F38 , 0x0000 , 0x6E6E , 0xFF2F ,
    0x0000 , 0x6569 , 0x0F35 , 0xFF2F , 0x0000 , 0x7072 , 0x0F40 , 0x0F53 ,
    0x0000 , 0x0008 , 0x0F47 , S(7265), S(6361), S(6F69), S(656E), 0x00D2 ,
    0x7673 , 0x0F4D , 0xFF2E , 0x0000 , 0x0F50 , 0x0000 , 0x6868 , 0xFF2E ,
    0x0000 , 0x6565 , 0xFF2E , 0x0000 , 0x6961 , 0xFF2D , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0F5E , 0x0000 , 0x0F75 , 0x0000 , 0x0002 ,
    0x0F62 , S(6E61), 0x0000 , 0x6569 , 0x0F66 , 0x0F70 , 0x0000 , 0x7376 ,
    0x0F6A , 0x0F6D , 0x0000 , 0x6868 , 0xFF2C , 0x0000 , 0x6565 , 0xFF2C ,
    0x0000 , 0x0003 , 0xFF2B , S(657A), S(006D), 0x0000 , 0x0005 , 0xFF2A ,
    S(6A67), S(6E69), S(0065), 0x0000 , 0x7561 , 0x0F92 , 0x0000 , 0x0000 ,
    0x0000 , 0x1012 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1062 , 0x0000 ,
    0x1067 , 0x0000 , 0x0000 , 0x107E , 0x0000 , 0x0000 , 0x10C2 , 0x0000 ,
    0x0000 , 0x1152 , 0x0000 , 0x7663 , 0x0FA8 , 0x0FAE , 0x0000 , 0x0000 ,
    0x0FB1 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0FB6 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0FBC , 0x0FD3 , 0x1004 , 0x0000 , 0x100C ,
    0x0000 , 0x0005 , 0xFF29 , S(6569), S(746E), S(0065), 0x0000 , 0x6969 ,
    0xFF28 , 0x0000 , 0x0003 , 0xFF27 , S(7365), S(0065), 0x0000 , 0x0006 ,
    0xFF26 , S(6E75), S(6564), S(6973), 0x0000 , 0x7474 , 0x0FBF , 0x0000 ,
    0x696E , 0x0FC3 , 0x0FCD , 0x00DB , 0x7374 , 0x0FC7 , 0x0FCA , 0x0000 ,
    0x6868 , 0xFF25 , 0x0000 , 0x6565 , 0xFF25 , 0x0000 , 0x0006 , 0xFF24 ,
    S(7265), S(7469), S(7465), 0x0000 , 0x7565 , 0xFF79 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0FE6 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0FF8 , 0x0000 , 0x0000 , 0x0000 , 0x1001 , 0x0000 , 0x6165 ,
    0x0FEA , 0x0FEE , 0x0087 , 0x6D6E , 0xFF79 , 0xFF79 , 0x0087 , 0x6D73 ,
    0x0FF2 , 0x0FF5 , 0x0000 , 0x6969 , 0xFF79 , 0x0000 , 0x6868 , 0xFF79 ,
    0x0000 , 0x0003 , 0x0FFD , S(7279), S(0065), 0x00DD , 0x6E73 , 0xFF23 ,
    0xFF23 , 0x0000 , 0x7272 , 0xFF79 , 0x0000 , 0x6575 , 0x1008 , 0x1001 ,
    0x0000 , 0x6D74 , 0xFF79 , 0xFF79 , 0x0000 , 0x0005 , 0xFF22 , S(7261),
    S(7365), S(0069), 0x0000 , 0x746E , 0x101B , 0x0000 , 0x0000 , 0x0000 ,
    0x1020 , 0x0000 , 0x105D , 0x0000 , 0x0004 , 0xFF21 , S(6567), S(6573),
    0x0000 , 0x7664 , 0x1035 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x103B , 0x0000 , 0x0000 , 0x103F , 0x0000 ,
    0x0000 , 0x1051 , 0x0000 , 0x0000 , 0x1058 , 0x0000 , 0x0005 , 0xFF20 ,
    S(726F), S(6575), S(0073), 0x0000 , 0x0002 , 0xFF1F , S(7465), 0x0000 ,
    0x6175 , 0x1043 , 0x104C , 0x0000 , 0x0004 , 0x1048 , S(6572), S(6973),
    0x00E2 , 0x0002 , 0xFF1E , S(6574), 0x0000 , 0x0003 , 0xFF1D , S(696E),
    S(006D), 0x0000 , 0x0008 , 0xFF1C , S(6E6F), S(6C61), S(7469), S(7465),
    0x0000 , 0x0003 , 0xFF1B , S(6A6F), S(0065), 0x0000 , 0x0003 , 0xFF1A ,
    S(6972), S(0074), 0x0000 , 0x0003 , 0xFF19 , S(7365), S(0065), 0x0000 ,
    0x616C , 0x106B , 0x1079 , 0x0000 , 0x0002 , 0x106F , S(656E), 0x0000 ,
    0x7376 , 0x1073 , 0x1076 , 0x0000 , 0x6868 , 0xFF18 , 0x0000 , 0x6565 ,
    0xFF18 , 0x0000 , 0x0003 , 0xFF18 , S(6E61), S(0061), 0x0000 , 0x7A6C ,
    0x108F , 0x0000 , 0x0000 , 0x0000 , 0x10A5 , 0x0000 , 0x10B0 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x10B5 , 0x0000 ,
    0x696F , 0x1093 , 0x10A1 , 0x0000 , 0x0005 , 0x1099 , S(6974), S(616B),
    S(006E), 0x00E9 , 0x6569 , 0xFF17 , 0x109D , 0x00E9 , 0x6E74 , 0xFF17 ,
    0xFF17 , 0x0000 , 0x0002 , 0xFF16 , S(696E), 0x0000 , 0x0002 , 0x10A9 ,
    S(6A75), 0x00EB , 0x7476 , 0xFF15 , 0x10AD , 0x0000 , 0x6565 , 0xFF15 ,
    0x0000 , 0x0003 , 0xFF14 , S(736F), S(0069), 0x0000 , 0x0006 , 0x10BB ,
    S(6369), S(6F69), S(656E), 0x00ED , 0x7476 , 0xFF13 , 0x10BF , 0x0000 ,
    0x6565 , 0xFF13 , 0x0000 , 0x6F65 , 0x10CF , 0x0000 , 0x0000 , 0x0000 ,
    0x10D5 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1103 , 0x0000 ,
    0x0005 , 0xFF12 , S(6873), S(7665), S(0065), 0x0000 , 0x746E , 0x10DE ,
    0x10ED , 0x0000 , 0x0000 , 0x0000 , 0x10F3 , 0x10F9 , 0x0000 , 0x0003 ,
    0x10E3 , S(6564), S(0072), 0x00EF , 0x6976 , 0x10E7 , 0x10EA , 0x0000 ,
    0x7474 , 0xFF11 , 0x0000 , 0x6565 , 0xFF11 , 0x0000 , 0x0005 , 0xFF10 ,
    S(6972), S(6574), S(0074), 0x0000 , 0x0005 , 0xFF0F , S(7468), S(6E69),
    S(0065), 0x0000 , 0x0006 , 0x10FF , S(6873), S(656D), S(6972), 0x00F2 ,
    0x0002 , 0xFF0E , S(6574), 0x0000 , 0x7662 , 0x111A , 0x1122 , 0x1135 ,
    0x0000 , 0x113A , 0x1143 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x1148 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x114F , 0x0000 , 0x0003 , 0x111F , S(656C), S(006D), 0x00F3 ,
    0x6969 , 0xFF0D , 0x0000 , 0x6565 , 0x1125 , 0x0000 , 0x6473 , 0x1129 ,
    0x1132 , 0x0000 , 0x0003 , 0x112E , S(7275), S(0065), 0x0000 , 0x6E73 ,
    0xFF0C , 0xFF0C , 0x00F5 , 0x6565 , 0xFF0B , 0x0000 , 0x0004 , 0xFF0A ,
    S(7568), S(7365), 0x0000 , 0x000B , 0xFF09 , S(7365), S(6F69), S(616E),
    S(696C), S(657A), S(006D), 0x0000 , 0x0003 , 0xFF08 , S(6572), S(0073),
    0x0000 , 0x6565 , 0x114B , 0x00F9 , 0x0002 , 0xFF06 , S(6973), 0x0000 ,
    0x6565 , 0xFF05 , 0x0000 , 0x0005 , 0xFF04 , S(6873), S(6574), S(0074),
    0x0000 , 0x7965 , 0x116F , 0x0000 , 0x0000 , 0x0000 , 0x118D , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1192 , 0x0000 ,
    0x6E76 , 0x1173 , 0x117E , 0x0000 , 0x656B , 0xFF88 , 0x1177 , 0x0000 ,
    0x6165 , 0x117B , 0xFF88 , 0x0078 , 0x6E6E , 0xFF88 , 0x0000 , 0x0003 ,
    0x1183 , S(7265), S(0069), 0x00FD , 0x7374 , 0x1187 , 0x118A , 0x0000 ,
    0x6868 , 0xFF03 , 0x0000 , 0x6565 , 0xFF03 , 0x0000 , 0x0004 , 0xFF02 ,
    S(646E), S(6172), 0x0000 , 0x0003 , 0xFF01 , S(6574), S(0074), 0x0000 ,
    0x7561 , 0x11AE , 0x0000 , 0x0000 , 0x0000 , 0x11DE , 0x0000 , 0x0000 ,
    0x0000 , 0x1216 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x121B , 0x0000 , 0x0000 , 0x1220 , 0x0000 , 0x7364 ,
    0x11C0 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x11CB , 0x0000 ,
    0x0000 , 0x0000 , 0x11D7 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x11DA ,
    0x0000 , 0x0002 , 0x11C4 , S(6F69), 0x0000 , 0x6A6E , 0x11C8 , 0xFF00 ,
    0x0000 , 0x6161 , 0xFF00 , 0x0000 , 0x0003 , 0x11D0 , S(6E6F), S(0065),
    0x0101 , 0x7476 , 0xFEFF , 0x11D4 , 0x0000 , 0x6565 , 0xFEFF , 0x0000 ,
    0x6565 , 0xFFDA , 0x0000 , 0x0002 , 0xFFDA , S(6568), 0x0000 , 0x7A61 ,
    0x11FA , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1200 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x1209 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x1210 , 0x0000 , 0x0005 , 0xFEFE , S(696C), S(6574), S(0074),
    0x0000 , 0x6465 , 0x1204 , 0xFFDA , 0x0000 , 0x0003 , 0xFEFD , S(7365),
    S(0069), 0x0000 , 0x0007 , 0xFEFC , S(6F74), S(6172), S(746E), S(0065),
    0x0000 , 0x0005 , 0xFEFB , S(6C75), S(6174), S(0074), 0x0000 , 0x0003 ,
    0xFEFA , S(6574), S(006D), 0x0000 , 0x0003 , 0xFEF9 , S(656A), S(0074),
    0x0000 , 0x7461 , 0x1236 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x1259 , 0x125E , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1276 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x127B , 0x0000 , 0x6A73 ,
    0x123A , 0x1256 , 0x0000 , 0x7474 , 0x123D , 0x0108 , 0x7565 , 0x1250 ,
    0x0000 , 0x0000 , 0x0000 , 0xFEF8 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1253 ,
    0x0108 , 0x6E6E , 0xFEF8 , 0x0000 , 0x7272 , 0xFEF8 , 0x0000 , 0x6868 ,
    0xFEF8 , 0x0000 , 0x0003 , 0xFEF7 , S(766F), S(0061), 0x0000 , 0x6565 ,
    0x1261 , 0x0000 , 0x746A , 0xFEF8 , 0x0000 , 0x0000 , 0x126E , 0xFEF8 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1271 , 0xFEF8 , 0x0000 , 0x6969 ,
    0xFEF8 , 0x0000 , 0x0003 , 0xFEF8 , S(6968), S(006E), 0x0000 , 0x0003 ,
    0xFEF6 , S(6E61), S(0069), 0x0000 , 0x0003 , 0xFEF5 , S(6E69), S(0065),
    0x0000 , 0x7961 , 0x129B , 0x0000 , 0x0000 , 0x0000 , 0x12C7 , 0x0000 ,
    0x0000 , 0x12D6 , 0x13F5 , 0x144C , 0x1458 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x145D , 0x14B9 , 0x0000 ,
    0x0000 , 0x0000 , 0x14C9 , 0x0000 , 0x736B , 0x12A6 , 0x12AB , 0x0000 ,
    0x12AE , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x12C0 , 0x0000 , 0x0004 ,
    0xFEF4 , S(6574), S(6973), 0x0000 , 0x6969 , 0xFEF3 , 0x0000 , 0x0006 ,
    0x12B4 , S(736B), S(6F69), S(656E), 0x010E , 0x7673 , 0x12BA , 0xFEF2 ,
    0x0000 , 0x12BD , 0x0000 , 0x6868 , 0xFEF2 , 0x0000 , 0x6565 , 0xFEF2 ,
    0x0000 , 0x6969 , 0x12C3 , 0x010F , 0x0002 , 0xFEF1 , S(6574), 0x0000 ,
    0x6C72 , 0x12CB , 0x12CF , 0x0000 , 0x0002 , 0xFEF0 , S(6169), 0x0000 ,
    0x6969 , 0x12D2 , 0x0111 , 0x0002 , 0xFEEF , S(6574), 0x0000 , 0x7465 ,
    0x12E8 , 0x0000 , 0x0000 , 0x0000 , 0x1308 , 0x0000 , 0x1361 , 0x0000 ,
    0x0000 , 0x0000 , 0x13A5 , 0x13BD , 0x13CE , 0x0000 , 0x0000 , 0x13D4 ,
    0x0000 , 0x746E , 0x12F1 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1301 ,
    0xFEEB , 0x0000 , 0x6469 , 0x12F5 , 0x12FE , 0x0000 , 0x0002 , 0x12F9 ,
    S(7465), 0x0112 , 0x0003 , 0xFEED , S(7365), S(0069), 0x0000 , 0x6D6D ,
    0xFEEC , 0x0115 , 0x6569 , 0xFEEB , 0x1305 , 0x0000 , 0x6D6D , 0xFEEB ,
    0x0000 , 0x7468 , 0x1317 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1332 , 0x1339 , 0x0118 ,
    0x746A , 0x1324 , 0x0000 , 0x0000 , 0x0000 , 0x1328 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x132F , 0x0000 , 0x6165 , 0xFEE8 , 0xFEE8 ,
    0x0000 , 0x6969 , 0x132B , 0x0118 , 0x6D6E , 0xFEE8 , 0xFEE8 , 0x0000 ,
    0x6565 , 0xFEE8 , 0x0000 , 0x0002 , 0x1336 , S(696E), 0x0115 , 0x6E6E ,
    0xFEEB , 0x0000 , 0x7565 , 0x134C , 0x0000 , 0x0000 , 0x0000 , 0xFEEB ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x135E , 0x0000 , 0x746A , 0xFEEB , 0x0000 ,
    0x0000 , 0x0000 , 0xFEEB , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1359 ,
    0xFEEB , 0x0000 , 0x0003 , 0xFEEB , S(6968), S(006E), 0x0000 , 0x7272 ,
    0xFEEB , 0x0000 , 0x756F , 0x136A , 0x0000 , 0x0000 , 0x1394 , 0x0000 ,
    0x0000 , 0x1399 , 0x0116 , 0x7668 , 0x137B , 0xFEEA , 0x1382 , 0x0000 ,
    0x0000 , 0x0000 , 0x1389 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x1391 , 0x0000 , 0x6565 , 0x137E , 0x0000 , 0x6A74 ,
    0xFEEA , 0xFEEA , 0x0116 , 0x6D6E , 0x1386 , 0x1386 , 0x0000 , 0x6565 ,
    0xFEEA , 0x0116 , 0x6974 , 0x138D , 0x1386 , 0x0116 , 0x6D6E , 0xFEEA ,
    0xFEEA , 0x0000 , 0x6161 , 0xFEEA , 0x0000 , 0x0003 , 0xFEE9 , S(7365),
    S(0065), 0x0116 , 0x6165 , 0x139D , 0xFEEA , 0x0116 , 0x726D , 0xFEEA ,
    0xFEEA , 0x0000 , 0x0000 , 0x0000 , 0xFEEA , 0x0000 , 0x6871 , 0x13A9 ,
    0x13B4 , 0x0118 , 0x6569 , 0x13AD , 0x13B1 , 0x0118 , 0x0002 , 0xFEE8 ,
    S(6873), 0x0000 , 0x6E6E , 0xFEE8 , 0x0000 , 0x0003 , 0x13B9 , S(7265),
    S(0069), 0x0119 , 0x0002 , 0xFEE7 , S(6574), 0x0000 , 0x6569 , 0x13C1 ,
    0x13C7 , 0x0000 , 0x0005 , 0xFEE6 , S(746A), S(7365), S(0069), 0x0000 ,
    0x6173 , 0xFEE4 , 0x13CB , 0x0000 , 0x6565 , 0xFEE4 , 0x0000 , 0x0005 ,
    0xFEE5 , S(7069), S(7265), S(0069), 0x0000 , 0x6572 , 0x13D8 , 0x13F0 ,
    0x0000 , 0x7470 , 0x13DF , 0x0000 , 0x0000 , 0x13E9 , 0x13EC , 0x0000 ,
    0x6969 , 0x13E2 , 0x011C , 0x7374 , 0x13E6 , 0x13CB , 0x0000 , 0x6868 ,
    0xFEE4 , 0x0000 , 0x6565 , 0xFEE3 , 0x011E , 0x0002 , 0xFEE1 , S(7361),
    0x0000 , 0x0003 , 0xFEE0 , S(7365), S(0065), 0x0000 , 0x7367 , 0x1404 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1409 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x1444 , 0x0000 , 0x0003 , 0xFEDF , S(7275),
    S(0069), 0x0000 , 0x6C6C , 0x140C , 0x0000 , 0x7465 , 0x141E , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x1438 , 0x0000 , 0x0000 , 0x0000 , 0x143B ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1441 , 0x0000 , 0x746A ,
    0xFEDC , 0x0000 , 0x0000 , 0x142B , 0x142E , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x1431 , 0xFEDC , 0x0000 , 0x6969 , 0xFEDC , 0x0124 , 0x6969 ,
    0xFEDC , 0x0000 , 0x6868 , 0x1434 , 0x0124 , 0x0002 , 0xFEDC , S(6E69),
    0x0000 , 0x6161 , 0xFEDC , 0x0000 , 0x6969 , 0x143E , 0x0124 , 0x6E6E ,
    0xFEDC , 0x0000 , 0x6565 , 0xFEDC , 0x0000 , 0x0003 , 0x1449 , S(6574),
    S(006D), 0x0122 , 0x6969 , 0xFEDE , 0x0000 , 0x0003 , 0x1451 , S(6C65),
    S(006C), 0x0124 , 0x6569 , 0xFEDC , 0x1455 , 0x0000 , 0x6D6D , 0xFEDC ,
    0x0000 , 0x0003 , 0xFEDD , S(6E65), S(0065), 0x0000 , 0x7561 , 0x1474 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x1485 , 0x0000 , 0x0000 , 0x14B3 , 0x0000 , 0x6274 , 0x1478 , 0x147E ,
    0x0000 , 0x0006 , 0xFEDB , S(6C69), S(7469), S(7465), 0x0000 , 0x0002 ,
    0x1482 , S(7375), 0x0126 , 0x6565 , 0xFEDA , 0x0000 , 0x7561 , 0x149C ,
    0x0000 , 0x0000 , 0x0000 , 0x14A6 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x14A9 , 0x0000 , 0x0005 , 0x14A2 , S(6574),
    S(6A67), S(0069), 0x0127 , 0x0002 , 0xFED9 , S(6574), 0x0000 , 0x7373 ,
    0xFED8 , 0x0000 , 0x0005 , 0x14AF , S(746B), S(7275), S(0065), 0x0129 ,
    0x6E73 , 0xFED7 , 0xFED7 , 0x0000 , 0x0005 , 0xFED6 , S(6564), S(746E),
    S(0065), 0x0000 , 0x656B , 0x14BD , 0x14C1 , 0x0000 , 0x0002 , 0xFED5 ,
    S(6964), 0x0000 , 0x0003 , 0x14C6 , S(6573), S(0073), 0x012C , 0x6565 ,
    0xFED4 , 0x012D , 0x7673 , 0x14CF , 0x14D7 , 0x0000 , 0x14D7 , 0x0000 ,
    0x6874 , 0xFED3 , 0x14D3 , 0x0000 , 0x0002 , 0xFEDE , S(6D65), 0x0000 ,
    0x6565 , 0xFED3 , 0x0000 , 0x7561 , 0x14F1 , 0x0000 , 0x0000 , 0x0000 ,
    0x14F7 , 0x0000 , 0x0000 , 0x1561 , 0x15E2 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x15EE , 0x0000 , 0x0000 ,
    0x1621 , 0x0000 , 0x0006 , 0xFED2 , S(6F76), S(696C), S(656E), 0x0000 ,
    0x746B , 0x1503 , 0x150E , 0x151B , 0x1526 , 0x152C , 0x1534 , 0x0000 ,
    0x153A , 0x0000 , 0x1559 , 0x0000 , 0x0007 , 0x150A , S(6F6E), S(6F6C),
    S(6A67), S(0069), 0x012F , 0x0002 , 0xFED1 , S(6574), 0x0000 , 0x0004 ,
    0x1513 , S(6665), S(6E6F), 0x0130 , 0x6569 , 0xFED0 , 0x1517 , 0x0130 ,
    0x6E74 , 0xFED0 , 0xFED0 , 0x0000 , 0x0008 , 0x1522 , S(6570), S(6172),
    S(7574), S(6572), 0x0131 , 0x6E73 , 0xFECF , 0xFECF , 0x0000 , 0x0006 ,
    0xFECE , S(6174), S(6974), S(6576), 0x0000 , 0x0002 , 0x1530 , S(6972),
    0x0133 , 0x0002 , 0xFECD , S(6574), 0x0000 , 0x0005 , 0xFECC , S(6C65),
    S(6E65), S(0065), 0x0000 , 0x6D61 , 0x1549 , 0x0000 , 0x0000 , 0x0000 ,
    0x1551 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x1555 , 0x0000 , 0x0002 , 0x154D , S(6970), 0x0135 , 0x0002 , 0xFECB ,
    S(6574), 0x0000 , 0x0002 , 0xFECA , S(6973), 0x0000 , 0x0002 , 0xFEC9 ,
    S(7465), 0x0000 , 0x0002 , 0x155D , S(766F), 0x0000 , 0x6165 , 0xFEC8 ,
    0xFEC8 , 0x0000 , 0x7561 , 0x1578 , 0x0000 , 0x0000 , 0x0000 , 0x157D ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x1587 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x15BC ,
    0x0000 , 0x0003 , 0xFEC7 , S(6873), S(0065), 0x0139 , 0x6D6E , 0x1581 ,
    0x1584 , 0x0139 , 0x6969 , 0xFEC7 , 0x0000 , 0x6565 , 0xFEC7 , 0x0000 ,
    0x746A , 0x1594 , 0x0000 , 0x0000 , 0xFEC7 , 0x1597 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x159F , 0xFEC7 , 0x0000 , 0x6161 , 0xFEC7 , 0x0000 ,
    0x6569 , 0xFEC7 , 0x159B , 0x0139 , 0x6D6E , 0xFEC7 , 0xFEC7 , 0x0000 ,
    0x6868 , 0x15A2 , 0x0000 , 0x7461 , 0xFEC7 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x15B8 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1584 ,
    0x0000 , 0x6D6E , 0xFEC7 , 0xFEC7 , 0x0000 , 0x6168 , 0x15C0 , 0x15D2 ,
    0x0000 , 0x6A73 , 0x15C4 , 0x15CF , 0x0139 , 0x6961 , 0xFEC7 , 0x0000 ,
    0x0000 , 0x0000 , 0xFEC7 , 0x0000 , 0x0000 , 0x0000 , 0xFEC7 , 0x0000 ,
    0x6868 , 0xFEC7 , 0x0000 , 0x6565 , 0x15D5 , 0x0000 , 0x746A , 0xFEC7 ,
    0x0000 , 0x0000 , 0x0000 , 0xFEC7 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0xFEC7 , 0x0000 , 0x0003 , 0x15E7 , S(7574), S(006A), 0x013A ,
    0x7476 , 0xFEC6 , 0x15EB , 0x0000 , 0x6565 , 0xFEC6 , 0x0000 , 0x7561 ,
    0x1605 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x160A , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x161D , 0x0000 , 0x0004 , 0xFEC5 ,
    S(6E6A), S(6D69), 0x0000 , 0x6A70 , 0x160E , 0x1618 , 0x0000 , 0x6565 ,
    0x1611 , 0x013D , 0x7476 , 0xFEC3 , 0x1615 , 0x0000 , 0x6565 , 0xFEC3 ,
    0x0000 , 0x0003 , 0xFEC4 , S(6A6F), S(0065), 0x013E , 0x0002 , 0xFEC2 ,
    S(6574), 0x0000 , 0x6172 , 0x1625 , 0x162A , 0x0000 , 0x0003 , 0xFEC1 ,
    S(656C), S(0074), 0x0000 , 0x6971 , 0x162E , 0x1633 , 0x0000 , 0x0003 ,
    0xFEC0 , S(657A), S(006D), 0x0000 , 0x6969 , 0xFEBF , 0x0000 , 0x726A ,
    0x1641 , 0x166A , 0x0000 , 0x0000 , 0x1670 , 0x0000 , 0x0000 , 0x0000 ,
    0x1682 , 0x0000 , 0x7265 , 0x1651 , 0x0000 , 0x0000 , 0x0000 , 0x1658 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x165B ,
    0x1660 , 0x0000 , 0x0007 , 0xFEBD , S(6A73), S(6C65), S(656C), S(0073),
    0x0142 , 0x6E6E , 0xFEBE , 0x0000 , 0x0004 , 0xFEBC , S(7265), S(6576),
    0x0000 , 0x6161 , 0x1663 , 0x0142 , 0x7476 , 0xFEBE , 0x1667 , 0x0000 ,
    0x6565 , 0xFEBE , 0x0144 , 0x0005 , 0xFEBB , S(6172), S(6E69), S(0065),
    0x0000 , 0x6969 , 0x1673 , 0x0000 , 0x7476 , 0x1677 , 0x167B , 0x0000 ,
    0x0002 , 0xFEBA , S(7465), 0x0000 , 0x0007 , 0xFEB9 , S(7265), S(6973),
    S(6574), S(0074), 0x0000 , 0x6465 , 0x1686 , 0x169B , 0x0000 , 0x6868 ,
    0x1689 , 0x0000 , 0x6572 , 0x168D , 0x1690 , 0x0000 , 0x7272 , 0xFEB7 ,
    0x0000 , 0x6169 , 0x1694 , 0xFEB7 , 0x0149 , 0x7476 , 0xFEB7 , 0x1698 ,
    0x0000 , 0x6565 , 0xFEB7 , 0x0148 , 0x6E6E , 0xFEB8 , 0x0000 , 0x7561 ,
    0x16B5 , 0x0000 , 0x0000 , 0x16DB , 0x1703 , 0x0000 , 0x0000 , 0x0000 ,
    0x1751 , 0x178F , 0x0000 , 0x1796 , 0x0000 , 0x0000 , 0x17CA , 0x0000 ,
    0x0000 , 0x17CF , 0x0000 , 0x0000 , 0x1808 , 0x0000 , 0x7A6A , 0x16C8 ,
    0x16CF , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x16D4 ,
    0x0000 , 0x6969 , 0x16CB , 0x014A , 0x6E74 , 0xFEB6 , 0xFEB6 , 0x0000 ,
    0x0004 , 0xFEB5 , S(6973), S(656E), 0x0000 , 0x0007 , 0xFEB4 , S(6468),
    S(6D69), S(7365), S(0069), 0x0000 , 0x6569 , 0x16DF , 0x16F3 , 0x0000 ,
    0x6B73 , 0x16E3 , 0x16E7 , 0x0000 , 0x0002 , 0xFEB3 , S(7275), 0x014D ,
    0x6569 , 0x16EB , 0x16EF , 0x014D , 0x0002 , 0xFEB3 , S(6873), 0x0000 ,
    0x6D6E , 0xFEB3 , 0xFEB3 , 0x0000 , 0x7373 , 0x16F6 , 0x0000 , 0x6E74 ,
    0x16FA , 0x1700 , 0x0000 , 0x6969 , 0x16FD , 0x014D , 0x6E6E , 0xFEB3 ,
    0x0000 , 0x6565 , 0xFEB3 , 0x0000 , 0x7363 , 0x1716 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x171C , 0x172C ,
    0x172C , 0x0000 , 0x172F , 0x0000 , 0x0000 , 0x1740 , 0x0000 , 0x0005 ,
    0xFEB2 , S(726F), S(7469), S(0065), 0x0000 , 0x0005 , 0x1722 , S(656C),
    S(657A), S(0072), 0x014F , 0x6976 , 0x1726 , 0x1729 , 0x0000 , 0x7474 ,
    0xFEB1 , 0x0000 , 0x6565 , 0xFEB1 , 0x0000 , 0x6565 , 0xFEA4 , 0x0000 ,
    0x0007 , 0x1736 , S(6972), S(746D), S(7261), S(0069), 0x0000 , 0x7374 ,
    0x173A , 0x173D , 0x0000 , 0x6868 , 0xFEB0 , 0x0000 , 0x6565 , 0xFEB0 ,
    0x0000 , 0x0007 , 0x1747 , S(7468), S(7269), S(7365), S(0069), 0x0151 ,
    0x7374 , 0x174B , 0x174E , 0x0000 , 0x6868 , 0xFEAF , 0x0000 , 0x6565 ,
    0xFEAF , 0x0000 , 0x7464 , 0x1764 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x177B , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x1782 , 0x0000 , 0x1789 , 0x0000 , 0x0002 , 0x1768 , S(6F65),
    0x0000 , 0x736A , 0x1774 , 0x0000 , 0x0000 , 0x0000 , 0xFEAE , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x1778 , 0x0000 , 0x6165 , 0xFEAE , 0xFEAE ,
    0x0000 , 0x6868 , 0xFEAE , 0x004E , 0x6D6E , 0x177F , 0x177F , 0x0000 ,
    0x6565 , 0xFFB2 , 0x0000 , 0x0002 , 0x1786 , S(7375), 0x0153 , 0x6565 ,
    0xFEAD , 0x0000 , 0x0005 , 0xFEAC , S(6D61), S(6E69), S(0065), 0x0000 ,
    0x0002 , 0x1793 , S(6E65), 0x004E , 0x6565 , 0xFEAB , 0x0000 , 0x6F65 ,
    0x17A3 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x17C3 ,
    0x0000 , 0x0000 , 0x17C6 , 0x0000 , 0x726A , 0x17AE , 0x0000 , 0x0000 ,
    0x0000 , 0x17B5 , 0x0000 , 0x0000 , 0x0000 , 0x17BC , 0x0000 , 0x656E ,
    0xFEA9 , 0x17B2 , 0x0000 , 0x6565 , 0xFEA9 , 0x0157 , 0x6974 , 0x17B9 ,
    0x17B2 , 0x0000 , 0x6E6E , 0xFEA9 , 0x0000 , 0x6565 , 0x17BF , 0x0156 ,
    0x6E73 , 0xFEAA , 0xFEAA , 0x0000 , 0x6161 , 0xFEB1 , 0x0000 , 0x0002 ,
    0xFEA8 , S(6172), 0x0000 , 0x0004 , 0xFEA7 , S(656E), S(6573), 0x0000 ,
    0x6961 , 0x17DA , 0x0000 , 0x0000 , 0x0000 , 0x17F8 , 0x0000 , 0x0000 ,
    0x0000 , 0x17FB , 0x015A , 0x766D , 0x17E6 , 0x17E6 , 0x0000 , 0x0000 ,
    0x0000 , 0x17E6 , 0x17E9 , 0x0000 , 0xFEA6 , 0x17F5 , 0x0000 , 0x6565 ,
    0xFEA6 , 0x015A , 0x6569 , 0x17ED , 0x17F1 , 0x0000 , 0x0002 , 0xFEA6 ,
    S(6873), 0x0000 , 0x6D6E , 0xFEA6 , 0xFEA6 , 0x0000 , 0x6161 , 0xFEA6 ,
    0x0000 , 0x7474 , 0xFEA6 , 0x0000 , 0x7373 , 0x17FE , 0x0000 , 0x6E74 ,
    0x1802 , 0x17E6 , 0x0000 , 0x6969 , 0x1805 , 0x015A , 0x6E6E , 0xFEA6 ,
    0x0000 , 0x6E6C , 0x180D , 0x172C , 0x172C , 0x0000 , 0x0004 , 0xFEA5 ,
    S(6E6C), S(7465), 0x0000 , 0x0002 , 0x1816 , S(656A), 0x015D , 0x7673 ,
    0x181C , 0xFEA3 , 0x0000 , 0x181F , 0x0000 , 0x6868 , 0xFEA3 , 0x0000 ,
    0x6565 , 0xFEA3 , 0x0000 , 0x0007 , 0xFEA2 , S(6465), S(6568), S(656E),
    S(0073)
};

static const unsigned short a_2[] = {
    0x0000 , 0x7561 , 0x0017 , 0x0000 , 0x0000 , 0x0000 , 0x0043 , 0x0000 ,
    0x0000 , 0x00AD , 0x00C6 , 0x00EF , 0x0000 , 0x0000 , 0x00F9 , 0x0127 ,
    0x0000 , 0x0000 , 0x0000 , 0x0170 , 0x0177 , 0x017A , 0x01C0 , 0x4000 ,
    0x7668 , 0x0028 , 0x0000 , 0x0038 , 0x003B , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x003F , 0x0000 , 0x0000 , 0xBFFF , 0x0035 ,
    0x0000 , 0x7373 , 0x002B , 0x0000 , 0x6566 , 0x002F , 0x0035 , 0x4001 ,
    0x6868 , 0x0032 , 0x4002 , 0x6F6F , 0xBFFD , 0x0000 , 0x6F6F , 0xBFFF ,
    0x4004 , 0x6F6F , 0xBFFB , 0x4006 , 0x0002 , 0xBFF9 , S(6175), 0x4004 ,
    0x0002 , 0xBFF8 , S(6175), 0x0000 , 0x7668 , 0x0054 , 0x0000 , 0x005E ,
    0x0061 , 0x0000 , 0x0065 , 0x0075 , 0x0000 , 0x0000 , 0x0000 , 0x0061 ,
    0xBFF5 , 0x0084 , 0xC000 , 0x008E , 0x0000 , 0x0002 , 0x0058 , S(7365),
    0x4000 , 0x6868 , 0x005B , 0x4009 , 0x6F6F , 0xBFF6 , 0x400B , 0x6F6F ,
    0xBFF4 , 0x0000 , 0x0002 , 0xC000 , S(6175), 0x0000 , 0x6A6A , 0x0068 ,
    0x4000 , 0x6F65 , 0xBFF3 , 0x0000 , 0x0000 , 0x0000 , 0xBFF3 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0xBFF3 , 0x4000 , 0x616A , 0x0079 ,
    0x0080 , 0x0000 , 0x6B6B , 0x007C , 0x400E , 0x0002 , 0xBFF1 , S(6175),
    0x400E , 0x656F , 0xBFF0 , 0xBFF0 , 0x0000 , 0x666E , 0x0088 , 0x008B ,
    0x0000 , 0x6F6F , 0xC000 , 0x4000 , 0x6F6F , 0xBFF3 , 0x4000 , 0x7261 ,
    0x00A2 , 0x0000 , 0x0000 , 0x0000 , 0xBFF2 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x00A9 , 0x400E , 0x7272 , 0x00A5 , 0x4011 , 0x0002 , 0xBFEE ,
    S(6175), 0x0000 , 0x0002 , 0xBFF2 , S(6175), 0x0000 , 0x7373 , 0x00B0 ,
    0x0000 , 0x6661 , 0x00B8 , 0x0000 , 0x0000 , 0x0000 , 0x00BB , 0x008B ,
    0x4000 , 0x7272 , 0xBFED , 0x4000 , 0x6872 , 0x00BF , 0x00C2 , 0x0000 ,
    0x6F6F , 0xBFF3 , 0x0000 , 0x0002 , 0xBFF3 , S(6175), 0x4000 , 0x726D ,
    0x00CE , 0x00DC , 0xBFFF , 0x0000 , 0x0000 , 0x00EB , 0x0000 , 0x6565 ,
    0x00D1 , 0x4001 , 0x686B , 0x00D5 , 0x00D8 , 0x0000 , 0x6F6F , 0xBFEC ,
    0x4014 , 0x0002 , 0xBFEB , S(6175), 0x4001 , 0x656F , 0x00E0 , 0xBFEA ,
    0x4016 , 0x686B , 0x00E4 , 0x00E7 , 0x4017 , 0x6F6F , 0xBFE8 , 0x4017 ,
    0x0002 , 0xBFE8 , S(6175), 0x0000 , 0x0002 , 0xBFFF , S(6175), 0x400B ,
    0x656F , 0x00F3 , 0xBFE7 , 0x4019 , 0x6868 , 0x00F6 , 0x401A , 0x6F6F ,
    0xBFE5 , 0x0000 , 0x6961 , 0x0104 , 0x0000 , 0x0000 , 0x0000 , 0x010C ,
    0x0000 , 0x0000 , 0x0000 , 0x0113 , 0x401C , 0x6B75 , 0x0108 , 0xBFE3 ,
    0x401D , 0x0002 , 0xBFE2 , S(6175), 0x4000 , 0x6875 , 0x0110 , 0xBFF2 ,
    0x400E , 0x6F6F , 0xBFF0 , 0x0000 , 0x686E , 0x0117 , 0x008B , 0x0000 ,
    0x7373 , 0x011A , 0x0000 , 0x6566 , 0x011E , 0x0124 , 0x4000 , 0x6868 ,
    0x0121 , 0x401F , 0x6F6F , 0xBFE0 , 0x4000 , 0x6F6F , 0xBFE1 , 0x4000 ,
    0x7561 , 0x013E , 0x0000 , 0x0000 , 0x0000 , 0x0146 , 0x0000 , 0x0000 ,
    0x0000 , 0x014C , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0xBFFF ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0xBFFF , 0x4001 , 0x6B75 ,
    0x0142 , 0xBFEA , 0x4016 , 0x0002 , 0xBFE9 , S(6175), 0x4001 , 0x6868 ,
    0x0149 , 0x4021 , 0x6F6F , 0xBFDE , 0x4001 , 0x7268 , 0x0159 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0169 , 0x0000 , 0x0000 , 0x0000 ,
    0x016C , 0x0000 , 0x7373 , 0x015C , 0x0000 , 0x6566 , 0x0160 , 0x0166 ,
    0x4016 , 0x6868 , 0x0163 , 0x4023 , 0x6F6F , 0xBFDC , 0x4016 , 0x6F6F ,
    0xBFDD , 0x4016 , 0x6F6F , 0xBFE9 , 0x4025 , 0x0002 , 0xBFDA , S(6175),
    0x0000 , 0x6175 , 0x0174 , 0xC000 , 0x0000 , 0x7575 , 0xC000 , 0x400B ,
    0x6565 , 0xBFE7 , 0x400B , 0x7561 , 0x0191 , 0x0000 , 0x0000 , 0x0000 ,
    0x0199 , 0x0000 , 0x0000 , 0x0000 , 0x019F , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0xBFE7 , 0x4019 , 0x7275 , 0x0195 , 0xBFE6 , 0x4027 , 0x0002 , 0xBFD8 ,
    S(6175), 0x4019 , 0x6868 , 0x019C , 0x4027 , 0x6F6F , 0xBFD8 , 0x4019 ,
    0x7268 , 0x01AC , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x00F6 ,
    0x0000 , 0x0000 , 0x0000 , 0x01BC , 0x0000 , 0x7373 , 0x01AF , 0x0000 ,
    0x6566 , 0x01B3 , 0x01B9 , 0x401A , 0x6868 , 0x01B6 , 0x4029 , 0x6F6F ,
    0xBFD6 , 0x401A , 0x6F6F , 0xBFD7 , 0x402B , 0x0002 , 0xBFD4 , S(6175),
    0x4000 , 0x0002 , 0xBFFF , S(686F)
};

static const unsigned short a_3[] = {
    0x0000 , 0x6A61 , 0xFFFF , 0x0000 , 0x0000 , 0x0000 , 0xFFFF , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x000C , 0x0000 , 0x6E6E , 0x000F , 0x0000 ,
    0x6569 , 0xFFFF , 0xFFFF
};

static const unsigned short a_4[] = {
    0x0000 , 0x7265 , 0xC000 , 0x0000 , 0x0000 , 0x0010 , 0x0000 , 0xC000 ,
    0xBFFF , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0014 ,
    0x0000 , 0x0002 , 0xFFFC , S(646F), 0x0000 , 0x6565 , 0xBFFE
};

static const unsigned char g_v[] = { 17, 65, 16, 1 };

static const unsigned char g_kgh[] = { 19 };

static int r_R1(struct SN_env * z) {
    return ((SN_local *)z)->i_p1 <= z->c;
}

static int r_S2(struct SN_env * z) {
    return ((SN_local *)z)->i_s2 <= z->c;
}

static int r_AfterV(struct SN_env * z) {
    if (((SN_local *)z)->i_p1 > z->c) return 0;
    {
        int v_1 = z->l - z->c;
        if (in_grouping_b_U(z, g_v, 97, 121, 0)) return 0;
        z->c = z->l - v_1;
    }
    return 1;
}

static int r_AfterC(struct SN_env * z) {
    if (((SN_local *)z)->i_p1 > z->c) return 0;
    {
        int v_1 = z->l - z->c;
        if (out_grouping_b_U(z, g_v, 97, 121, 0)) return 0;
        z->c = z->l - v_1;
    }
    return 1;
}

static int r_AfterKGH(struct SN_env * z) {
    if (((SN_local *)z)->i_p1 > z->c) return 0;
    {
        int v_1 = z->l - z->c;
        if (in_grouping_b_U(z, g_kgh, 103, 107, 0)) return 0;
        z->c = z->l - v_1;
    }
    return 1;
}

extern int albanian_UTF_8_stem(struct SN_env * z) {
    int among_var;
    int i_pr2;
    {
        int v_1 = z->c;
        while (1) {
            int v_2 = z->c;
            while (1) {
                int v_3 = z->c;
                z->bra = z->c;
                if (z->c + 1 >= z->l || (z->p[z->c + 1] != 167 && z->p[z->c + 1] != 171)) goto lab3;
                among_var = find_among(z, a_0);
                if (!among_var) goto lab3;
                z->ket = z->c;
                switch (among_var) {
                    case 1:
                        {
                            int ret = slice_from_s(z, 1, s_0);
                            if (ret < 0) return ret;
                        }
                        break;
                    case 2:
                        {
                            int ret = slice_from_s(z, 1, s_1);
                            if (ret < 0) return ret;
                        }
                        break;
                }
                z->c = v_3;
                break;
            lab3:
                z->c = v_3;
                {
                    int ret = skip_utf8(z->p, z->c, z->l, 1);
                    if (ret < 0) goto lab2;
                    z->c = ret;
                }
            }
            continue;
        lab2:
            z->c = v_2;
            break;
        }
        z->c = v_1;
    }
    do {
        int v_4 = z->c;
        z->bra = z->c;
        if (z->c + 1 >= z->l || z->p[z->c + 1] >> 5 != 3 || !((58589174 >> (z->p[z->c + 1] & 0x1f)) & 1)) goto lab4;
        among_var = find_among(z, a_1);
        if (!among_var) goto lab4;
        z->ket = z->c;
        if (z->c < z->l) goto lab4;
        switch (among_var) {
            case 1:
                {
                    int ret = slice_from_s(z, 5, s_2);
                    if (ret < 0) return ret;
                }
                break;
            case 2:
                {
                    int ret = slice_from_s(z, 4, s_3);
                    if (ret < 0) return ret;
                }
                break;
            case 3:
                {
                    int ret = slice_from_s(z, 6, s_4);
                    if (ret < 0) return ret;
                }
                break;
            case 4:
                {
                    int ret = slice_from_s(z, 6, s_5);
                    if (ret < 0) return ret;
                }
                break;
            case 5:
                {
                    int ret = slice_from_s(z, 7, s_6);
                    if (ret < 0) return ret;
                }
                break;
            case 6:
                {
                    int ret = slice_from_s(z, 5, s_7);
                    if (ret < 0) return ret;
                }
                break;
            case 7:
                {
                    int ret = slice_from_s(z, 4, s_8);
                    if (ret < 0) return ret;
                }
                break;
            case 8:
                {
                    int ret = slice_from_s(z, 8, s_8);
                    if (ret < 0) return ret;
                }
                break;
            case 9:
                {
                    int ret = slice_from_s(z, 9, s_9);
                    if (ret < 0) return ret;
                }
                break;
            case 10:
                {
                    int ret = slice_from_s(z, 4, s_10);
                    if (ret < 0) return ret;
                }
                break;
            case 11:
                {
                    int ret = slice_from_s(z, 9, s_11);
                    if (ret < 0) return ret;
                }
                break;
            case 12:
                {
                    int ret = slice_from_s(z, 7, s_12);
                    if (ret < 0) return ret;
                }
                break;
            case 13:
                {
                    int ret = slice_from_s(z, 5, s_13);
                    if (ret < 0) return ret;
                }
                break;
            case 14:
                {
                    int ret = slice_from_s(z, 5, s_14);
                    if (ret < 0) return ret;
                }
                break;
            case 15:
                {
                    int ret = slice_from_s(z, 8, s_15);
                    if (ret < 0) return ret;
                }
                break;
            case 16:
                {
                    int ret = slice_from_s(z, 8, s_16);
                    if (ret < 0) return ret;
                }
                break;
            case 17:
                {
                    int ret = slice_from_s(z, 10, s_17);
                    if (ret < 0) return ret;
                }
                break;
            case 18:
                {
                    int ret = slice_from_s(z, 5, s_18);
                    if (ret < 0) return ret;
                }
                break;
            case 19:
                {
                    int ret = slice_from_s(z, 6, s_19);
                    if (ret < 0) return ret;
                }
                break;
            case 20:
                {
                    int ret = slice_from_s(z, 8, s_20);
                    if (ret < 0) return ret;
                }
                break;
            case 21:
                {
                    int ret = slice_from_s(z, 6, s_21);
                    if (ret < 0) return ret;
                }
                break;
            case 22:
                {
                    int ret = slice_from_s(z, 5, s_22);
                    if (ret < 0) return ret;
                }
                break;
            case 23:
                {
                    int ret = slice_from_s(z, 8, s_23);
                    if (ret < 0) return ret;
                }
                break;
            case 24:
                {
                    int ret = slice_from_s(z, 6, s_24);
                    if (ret < 0) return ret;
                }
                break;
            case 25:
                {
                    int ret = slice_from_s(z, 8, s_25);
                    if (ret < 0) return ret;
                }
                break;
            case 26:
                {
                    int ret = slice_from_s(z, 9, s_26);
                    if (ret < 0) return ret;
                }
                break;
            case 27:
                {
                    int ret = slice_from_s(z, 6, s_27);
                    if (ret < 0) return ret;
                }
                break;
            case 28:
                {
                    int ret = slice_from_s(z, 5, s_28);
                    if (ret < 0) return ret;
                }
                break;
            case 29:
                {
                    int ret = slice_from_s(z, 5, s_29);
                    if (ret < 0) return ret;
                }
                break;
            case 30:
                {
                    int ret = slice_from_s(z, 4, s_30);
                    if (ret < 0) return ret;
                }
                break;
            case 31:
                {
                    int ret = slice_from_s(z, 6, s_31);
                    if (ret < 0) return ret;
                }
                break;
            case 32:
                {
                    int ret = slice_from_s(z, 9, s_32);
                    if (ret < 0) return ret;
                }
                break;
            case 33:
                {
                    int ret = slice_from_s(z, 6, s_33);
                    if (ret < 0) return ret;
                }
                break;
            case 34:
                {
                    int ret = slice_from_s(z, 3, s_34);
                    if (ret < 0) return ret;
                }
                break;
            case 35:
                {
                    int ret = slice_from_s(z, 5, s_35);
                    if (ret < 0) return ret;
                }
                break;
            case 36:
                {
                    int ret = slice_from_s(z, 5, s_36);
                    if (ret < 0) return ret;
                }
                break;
            case 37:
                {
                    int ret = slice_from_s(z, 4, s_37);
                    if (ret < 0) return ret;
                }
                break;
            case 38:
                {
                    int ret = slice_from_s(z, 3, s_38);
                    if (ret < 0) return ret;
                }
                break;
            case 39:
                {
                    int ret = slice_from_s(z, 6, s_39);
                    if (ret < 0) return ret;
                }
                break;
            case 40:
                {
                    int ret = slice_from_s(z, 7, s_40);
                    if (ret < 0) return ret;
                }
                break;
            case 41:
                {
                    int ret = slice_from_s(z, 7, s_41);
                    if (ret < 0) return ret;
                }
                break;
            case 42:
                {
                    int ret = slice_from_s(z, 6, s_42);
                    if (ret < 0) return ret;
                }
                break;
            case 43:
                {
                    int ret = slice_from_s(z, 8, s_1);
                    if (ret < 0) return ret;
                }
                break;
            case 44:
                {
                    int ret = slice_from_s(z, 4, s_43);
                    if (ret < 0) return ret;
                }
                break;
            case 45:
                {
                    int ret = slice_from_s(z, 6, s_44);
                    if (ret < 0) return ret;
                }
                break;
            case 46:
                {
                    int ret = slice_from_s(z, 4, s_45);
                    if (ret < 0) return ret;
                }
                break;
            case 47:
                {
                    int ret = slice_from_s(z, 5, s_46);
                    if (ret < 0) return ret;
                }
                break;
            case 48:
                {
                    int ret = slice_from_s(z, 9, s_47);
                    if (ret < 0) return ret;
                }
                break;
            case 49:
                {
                    int ret = slice_from_s(z, 7, s_48);
                    if (ret < 0) return ret;
                }
                break;
            case 50:
                {
                    int ret = slice_from_s(z, 5, s_49);
                    if (ret < 0) return ret;
                }
                break;
            case 51:
                {
                    int ret = slice_from_s(z, 6, s_50);
                    if (ret < 0) return ret;
                }
                break;
            case 52:
                {
                    int ret = slice_from_s(z, 4, s_51);
                    if (ret < 0) return ret;
                }
                break;
            case 53:
                {
                    int ret = slice_from_s(z, 4, s_52);
                    if (ret < 0) return ret;
                }
                break;
            case 54:
                {
                    int ret = slice_from_s(z, 6, s_53);
                    if (ret < 0) return ret;
                }
                break;
            case 55:
                {
                    int ret = slice_from_s(z, 7, s_54);
                    if (ret < 0) return ret;
                }
                break;
            case 56:
                {
                    int ret = slice_from_s(z, 3, s_55);
                    if (ret < 0) return ret;
                }
                break;
            case 57:
                {
                    int ret = slice_from_s(z, 8, s_56);
                    if (ret < 0) return ret;
                }
                break;
            case 58:
                {
                    int ret = slice_from_s(z, 9, s_57);
                    if (ret < 0) return ret;
                }
                break;
            case 59:
                {
                    int ret = slice_from_s(z, 4, s_58);
                    if (ret < 0) return ret;
                }
                break;
            case 60:
                {
                    int ret = slice_from_s(z, 4, s_59);
                    if (ret < 0) return ret;
                }
                break;
            case 61:
                {
                    int ret = slice_from_s(z, 8, s_60);
                    if (ret < 0) return ret;
                }
                break;
            case 62:
                {
                    int ret = slice_from_s(z, 3, s_61);
                    if (ret < 0) return ret;
                }
                break;
            case 63:
                {
                    int ret = slice_from_s(z, 3, s_62);
                    if (ret < 0) return ret;
                }
                break;
            case 64:
                {
                    int ret = slice_from_s(z, 8, s_63);
                    if (ret < 0) return ret;
                }
                break;
            case 65:
                {
                    int ret = slice_from_s(z, 10, s_64);
                    if (ret < 0) return ret;
                }
                break;
            case 66:
                {
                    int ret = slice_from_s(z, 8, s_65);
                    if (ret < 0) return ret;
                }
                break;
            case 67:
                {
                    int ret = slice_from_s(z, 4, s_66);
                    if (ret < 0) return ret;
                }
                break;
            case 68:
                {
                    int ret = slice_from_s(z, 6, s_67);
                    if (ret < 0) return ret;
                }
                break;
            case 69:
                {
                    int ret = slice_from_s(z, 10, s_0);
                    if (ret < 0) return ret;
                }
                break;
            case 70:
                {
                    int ret = slice_from_s(z, 7, s_68);
                    if (ret < 0) return ret;
                }
                break;
            case 71:
                {
                    int ret = slice_from_s(z, 7, s_69);
                    if (ret < 0) return ret;
                }
                break;
            case 72:
                {
                    int ret = slice_from_s(z, 3, s_70);
                    if (ret < 0) return ret;
                }
                break;
            case 73:
                {
                    int ret = slice_from_s(z, 8, s_71);
                    if (ret < 0) return ret;
                }
                break;
            case 74:
                {
                    int ret = slice_from_s(z, 5, s_72);
                    if (ret < 0) return ret;
                }
                break;
            case 75:
                {
                    int ret = slice_from_s(z, 5, s_73);
                    if (ret < 0) return ret;
                }
                break;
            case 76:
                {
                    int ret = slice_from_s(z, 7, s_74);
                    if (ret < 0) return ret;
                }
                break;
            case 77:
                {
                    int ret = slice_from_s(z, 6, s_75);
                    if (ret < 0) return ret;
                }
                break;
            case 78:
                {
                    int ret = slice_from_s(z, 4, s_76);
                    if (ret < 0) return ret;
                }
                break;
            case 79:
                {
                    int ret = slice_from_s(z, 3, s_77);
                    if (ret < 0) return ret;
                }
                break;
            case 80:
                {
                    int ret = slice_from_s(z, 4, s_78);
                    if (ret < 0) return ret;
                }
                break;
            case 81:
                {
                    int ret = slice_from_s(z, 9, s_79);
                    if (ret < 0) return ret;
                }
                break;
            case 82:
                {
                    int ret = slice_from_s(z, 3, s_80);
                    if (ret < 0) return ret;
                }
                break;
            case 83:
                {
                    int ret = slice_from_s(z, 6, s_81);
                    if (ret < 0) return ret;
                }
                break;
            case 84:
                {
                    int ret = slice_from_s(z, 4, s_82);
                    if (ret < 0) return ret;
                }
                break;
            case 85:
                {
                    int ret = slice_from_s(z, 5, s_83);
                    if (ret < 0) return ret;
                }
                break;
            case 86:
                {
                    int ret = slice_from_s(z, 4, s_84);
                    if (ret < 0) return ret;
                }
                break;
            case 87:
                {
                    int ret = slice_from_s(z, 9, s_85);
                    if (ret < 0) return ret;
                }
                break;
            case 88:
                {
                    int ret = slice_from_s(z, 6, s_86);
                    if (ret < 0) return ret;
                }
                break;
            case 89:
                {
                    int ret = slice_from_s(z, 7, s_87);
                    if (ret < 0) return ret;
                }
                break;
            case 90:
                {
                    int ret = slice_from_s(z, 6, s_88);
                    if (ret < 0) return ret;
                }
                break;
            case 91:
                {
                    int ret = slice_from_s(z, 4, s_89);
                    if (ret < 0) return ret;
                }
                break;
            case 92:
                {
                    int ret = slice_from_s(z, 7, s_90);
                    if (ret < 0) return ret;
                }
                break;
            case 93:
                {
                    int ret = slice_from_s(z, 10, s_91);
                    if (ret < 0) return ret;
                }
                break;
            case 94:
                {
                    int ret = slice_from_s(z, 6, s_92);
                    if (ret < 0) return ret;
                }
                break;
            case 95:
                {
                    int ret = slice_from_s(z, 7, s_93);
                    if (ret < 0) return ret;
                }
                break;
            case 96:
                {
                    int ret = slice_from_s(z, 4, s_94);
                    if (ret < 0) return ret;
                }
                break;
            case 97:
                {
                    int ret = slice_from_s(z, 6, s_95);
                    if (ret < 0) return ret;
                }
                break;
            case 98:
                {
                    int ret = slice_from_s(z, 4, s_96);
                    if (ret < 0) return ret;
                }
                break;
            case 99:
                {
                    int ret = slice_from_s(z, 5, s_97);
                    if (ret < 0) return ret;
                }
                break;
            case 100:
                {
                    int ret = slice_from_s(z, 4, s_98);
                    if (ret < 0) return ret;
                }
                break;
            case 101:
                {
                    int ret = slice_from_s(z, 3, s_99);
                    if (ret < 0) return ret;
                }
                break;
            case 102:
                {
                    int ret = slice_from_s(z, 7, s_100);
                    if (ret < 0) return ret;
                }
                break;
            case 103:
                {
                    int ret = slice_from_s(z, 5, s_101);
                    if (ret < 0) return ret;
                }
                break;
            case 104:
                {
                    int ret = slice_from_s(z, 6, s_102);
                    if (ret < 0) return ret;
                }
                break;
            case 105:
                {
                    int ret = slice_from_s(z, 10, s_103);
                    if (ret < 0) return ret;
                }
                break;
            case 106:
                {
                    int ret = slice_from_s(z, 3, s_104);
                    if (ret < 0) return ret;
                }
                break;
            case 107:
                {
                    int ret = slice_from_s(z, 7, s_105);
                    if (ret < 0) return ret;
                }
                break;
            case 108:
                {
                    int ret = slice_from_s(z, 7, s_106);
                    if (ret < 0) return ret;
                }
                break;
            case 109:
                {
                    int ret = slice_from_s(z, 3, s_107);
                    if (ret < 0) return ret;
                }
                break;
            case 110:
                {
                    int ret = slice_from_s(z, 3, s_108);
                    if (ret < 0) return ret;
                }
                break;
            case 111:
                {
                    int ret = slice_from_s(z, 8, s_109);
                    if (ret < 0) return ret;
                }
                break;
            case 112:
                {
                    int ret = slice_from_s(z, 8, s_110);
                    if (ret < 0) return ret;
                }
                break;
            case 113:
                {
                    int ret = slice_from_s(z, 7, s_111);
                    if (ret < 0) return ret;
                }
                break;
            case 114:
                {
                    int ret = slice_from_s(z, 9, s_112);
                    if (ret < 0) return ret;
                }
                break;
            case 115:
                {
                    int ret = slice_from_s(z, 9, s_113);
                    if (ret < 0) return ret;
                }
                break;
            case 116:
                {
                    int ret = slice_from_s(z, 10, s_114);
                    if (ret < 0) return ret;
                }
                break;
            case 117:
                {
                    int ret = slice_from_s(z, 10, s_115);
                    if (ret < 0) return ret;
                }
                break;
            case 118:
                {
                    int ret = slice_from_s(z, 7, s_116);
                    if (ret < 0) return ret;
                }
                break;
            case 119:
                {
                    int ret = slice_from_s(z, 8, s_117);
                    if (ret < 0) return ret;
                }
                break;
            case 120:
                {
                    int ret = slice_from_s(z, 5, s_118);
                    if (ret < 0) return ret;
                }
                break;
            case 121:
                {
                    int ret = slice_from_s(z, 6, s_119);
                    if (ret < 0) return ret;
                }
                break;
            case 122:
                {
                    int ret = slice_from_s(z, 3, s_120);
                    if (ret < 0) return ret;
                }
                break;
            case 123:
                {
                    int ret = slice_from_s(z, 5, s_121);
                    if (ret < 0) return ret;
                }
                break;
            case 124:
                {
                    int ret = slice_from_s(z, 9, s_122);
                    if (ret < 0) return ret;
                }
                break;
            case 125:
                {
                    int ret = slice_from_s(z, 4, s_123);
                    if (ret < 0) return ret;
                }
                break;
            case 126:
                {
                    int ret = slice_from_s(z, 7, s_124);
                    if (ret < 0) return ret;
                }
                break;
            case 127:
                {
                    int ret = slice_from_s(z, 8, s_125);
                    if (ret < 0) return ret;
                }
                break;
            case 128:
                {
                    int ret = slice_from_s(z, 9, s_126);
                    if (ret < 0) return ret;
                }
                break;
            case 129:
                {
                    int ret = slice_from_s(z, 8, s_127);
                    if (ret < 0) return ret;
                }
                break;
            case 130:
                {
                    int ret = slice_from_s(z, 8, s_128);
                    if (ret < 0) return ret;
                }
                break;
            case 131:
                {
                    int ret = slice_from_s(z, 3, s_129);
                    if (ret < 0) return ret;
                }
                break;
            case 132:
                {
                    int ret = slice_from_s(z, 8, s_130);
                    if (ret < 0) return ret;
                }
                break;
            case 133:
                {
                    int ret = slice_from_s(z, 6, s_131);
                    if (ret < 0) return ret;
                }
                break;
            case 134:
                {
                    int ret = slice_from_s(z, 6, s_132);
                    if (ret < 0) return ret;
                }
                break;
            case 135:
                {
                    int ret = slice_from_s(z, 5, s_133);
                    if (ret < 0) return ret;
                }
                break;
            case 136:
                {
                    int ret = slice_from_s(z, 4, s_134);
                    if (ret < 0) return ret;
                }
                break;
            case 137:
                {
                    int ret = slice_from_s(z, 6, s_135);
                    if (ret < 0) return ret;
                }
                break;
            case 138:
                {
                    int ret = slice_from_s(z, 6, s_136);
                    if (ret < 0) return ret;
                }
                break;
            case 139:
                {
                    int ret = slice_from_s(z, 6, s_137);
                    if (ret < 0) return ret;
                }
                break;
            case 140:
                {
                    int ret = slice_from_s(z, 6, s_138);
                    if (ret < 0) return ret;
                }
                break;
            case 141:
                {
                    int ret = slice_from_s(z, 7, s_139);
                    if (ret < 0) return ret;
                }
                break;
            case 142:
                {
                    int ret = slice_from_s(z, 9, s_140);
                    if (ret < 0) return ret;
                }
                break;
            case 143:
                {
                    int ret = slice_from_s(z, 5, s_141);
                    if (ret < 0) return ret;
                }
                break;
            case 144:
                {
                    int ret = slice_from_s(z, 9, s_141);
                    if (ret < 0) return ret;
                }
                break;
            case 145:
                {
                    int ret = slice_from_s(z, 9, s_142);
                    if (ret < 0) return ret;
                }
                break;
            case 146:
                {
                    int ret = slice_from_s(z, 12, s_143);
                    if (ret < 0) return ret;
                }
                break;
            case 147:
                {
                    int ret = slice_from_s(z, 9, s_144);
                    if (ret < 0) return ret;
                }
                break;
            case 148:
                {
                    int ret = slice_from_s(z, 7, s_145);
                    if (ret < 0) return ret;
                }
                break;
            case 149:
                {
                    int ret = slice_from_s(z, 7, s_146);
                    if (ret < 0) return ret;
                }
                break;
            case 150:
                {
                    int ret = slice_from_s(z, 5, s_147);
                    if (ret < 0) return ret;
                }
                break;
            case 151:
                {
                    int ret = slice_from_s(z, 5, s_148);
                    if (ret < 0) return ret;
                }
                break;
            case 152:
                {
                    int ret = slice_from_s(z, 5, s_149);
                    if (ret < 0) return ret;
                }
                break;
            case 153:
                {
                    int ret = slice_from_s(z, 6, s_150);
                    if (ret < 0) return ret;
                }
                break;
            case 154:
                {
                    int ret = slice_from_s(z, 3, s_151);
                    if (ret < 0) return ret;
                }
                break;
            case 155:
                {
                    int ret = slice_from_s(z, 9, s_152);
                    if (ret < 0) return ret;
                }
                break;
            case 156:
                {
                    int ret = slice_from_s(z, 5, s_153);
                    if (ret < 0) return ret;
                }
                break;
            case 157:
                {
                    int ret = slice_from_s(z, 5, s_154);
                    if (ret < 0) return ret;
                }
                break;
            case 158:
                {
                    int ret = slice_from_s(z, 6, s_155);
                    if (ret < 0) return ret;
                }
                break;
            case 159:
                {
                    int ret = slice_from_s(z, 5, s_156);
                    if (ret < 0) return ret;
                }
                break;
            case 160:
                {
                    int ret = slice_from_s(z, 6, s_157);
                    if (ret < 0) return ret;
                }
                break;
            case 161:
                {
                    int ret = slice_from_s(z, 7, s_158);
                    if (ret < 0) return ret;
                }
                break;
            case 162:
                {
                    int ret = slice_from_s(z, 7, s_159);
                    if (ret < 0) return ret;
                }
                break;
            case 163:
                {
                    int ret = slice_from_s(z, 6, s_160);
                    if (ret < 0) return ret;
                }
                break;
            case 164:
                {
                    int ret = slice_from_s(z, 3, s_161);
                    if (ret < 0) return ret;
                }
                break;
            case 165:
                {
                    int ret = slice_from_s(z, 4, s_162);
                    if (ret < 0) return ret;
                }
                break;
            case 166:
                {
                    int ret = slice_from_s(z, 7, s_163);
                    if (ret < 0) return ret;
                }
                break;
            case 167:
                {
                    int ret = slice_from_s(z, 3, s_164);
                    if (ret < 0) return ret;
                }
                break;
            case 168:
                {
                    int ret = slice_from_s(z, 7, s_165);
                    if (ret < 0) return ret;
                }
                break;
            case 169:
                {
                    int ret = slice_from_s(z, 5, s_166);
                    if (ret < 0) return ret;
                }
                break;
            case 170:
                {
                    int ret = slice_from_s(z, 8, s_166);
                    if (ret < 0) return ret;
                }
                break;
            case 171:
                {
                    int ret = slice_from_s(z, 6, s_167);
                    if (ret < 0) return ret;
                }
                break;
            case 172:
                {
                    int ret = slice_from_s(z, 8, s_168);
                    if (ret < 0) return ret;
                }
                break;
            case 173:
                {
                    int ret = slice_from_s(z, 6, s_169);
                    if (ret < 0) return ret;
                }
                break;
            case 174:
                {
                    int ret = slice_from_s(z, 5, s_170);
                    if (ret < 0) return ret;
                }
                break;
            case 175:
                {
                    int ret = slice_from_s(z, 4, s_171);
                    if (ret < 0) return ret;
                }
                break;
            case 176:
                {
                    int ret = slice_from_s(z, 5, s_172);
                    if (ret < 0) return ret;
                }
                break;
            case 177:
                {
                    int ret = slice_from_s(z, 6, s_173);
                    if (ret < 0) return ret;
                }
                break;
            case 178:
                {
                    int ret = slice_from_s(z, 6, s_174);
                    if (ret < 0) return ret;
                }
                break;
            case 179:
                {
                    int ret = slice_from_s(z, 6, s_175);
                    if (ret < 0) return ret;
                }
                break;
            case 180:
                {
                    int ret = slice_from_s(z, 8, s_176);
                    if (ret < 0) return ret;
                }
                break;
            case 181:
                {
                    int ret = slice_from_s(z, 6, s_177);
                    if (ret < 0) return ret;
                }
                break;
            case 182:
                {
                    int ret = slice_from_s(z, 4, s_178);
                    if (ret < 0) return ret;
                }
                break;
            case 183:
                {
                    int ret = slice_from_s(z, 4, s_179);
                    if (ret < 0) return ret;
                }
                break;
            case 184:
                {
                    int ret = slice_from_s(z, 6, s_180);
                    if (ret < 0) return ret;
                }
                break;
            case 185:
                {
                    int ret = slice_from_s(z, 6, s_181);
                    if (ret < 0) return ret;
                }
                break;
            case 186:
                {
                    int ret = slice_from_s(z, 8, s_182);
                    if (ret < 0) return ret;
                }
                break;
            case 187:
                {
                    int ret = slice_from_s(z, 3, s_183);
                    if (ret < 0) return ret;
                }
                break;
            case 188:
                {
                    int ret = slice_from_s(z, 6, s_184);
                    if (ret < 0) return ret;
                }
                break;
            case 189:
                {
                    int ret = slice_from_s(z, 4, s_185);
                    if (ret < 0) return ret;
                }
                break;
            case 190:
                {
                    int ret = slice_from_s(z, 6, s_186);
                    if (ret < 0) return ret;
                }
                break;
            case 191:
                {
                    int ret = slice_from_s(z, 4, s_187);
                    if (ret < 0) return ret;
                }
                break;
            case 192:
                {
                    int ret = slice_from_s(z, 5, s_188);
                    if (ret < 0) return ret;
                }
                break;
            case 193:
                {
                    int ret = slice_from_s(z, 3, s_189);
                    if (ret < 0) return ret;
                }
                break;
            case 194:
                {
                    int ret = slice_from_s(z, 7, s_190);
                    if (ret < 0) return ret;
                }
                break;
            case 195:
                {
                    int ret = slice_from_s(z, 6, s_191);
                    if (ret < 0) return ret;
                }
                break;
            case 196:
                {
                    int ret = slice_from_s(z, 6, s_192);
                    if (ret < 0) return ret;
                }
                break;
            case 197:
                {
                    int ret = slice_from_s(z, 3, s_193);
                    if (ret < 0) return ret;
                }
                break;
            case 198:
                {
                    int ret = slice_from_s(z, 3, s_194);
                    if (ret < 0) return ret;
                }
                break;
            case 199:
                {
                    int ret = slice_from_s(z, 5, s_194);
                    if (ret < 0) return ret;
                }
                break;
            case 200:
                {
                    int ret = slice_from_s(z, 6, s_195);
                    if (ret < 0) return ret;
                }
                break;
            case 201:
                {
                    int ret = slice_from_s(z, 7, s_196);
                    if (ret < 0) return ret;
                }
                break;
            case 202:
                {
                    int ret = slice_from_s(z, 7, s_197);
                    if (ret < 0) return ret;
                }
                break;
            case 203:
                {
                    int ret = slice_from_s(z, 4, s_198);
                    if (ret < 0) return ret;
                }
                break;
            case 204:
                {
                    int ret = slice_from_s(z, 7, s_199);
                    if (ret < 0) return ret;
                }
                break;
            case 205:
                {
                    int ret = slice_from_s(z, 4, s_200);
                    if (ret < 0) return ret;
                }
                break;
            case 206:
                {
                    int ret = slice_from_s(z, 5, s_201);
                    if (ret < 0) return ret;
                }
                break;
            case 207:
                {
                    int ret = slice_from_s(z, 5, s_202);
                    if (ret < 0) return ret;
                }
                break;
            case 208:
                {
                    int ret = slice_from_s(z, 5, s_203);
                    if (ret < 0) return ret;
                }
                break;
            case 209:
                {
                    int ret = slice_from_s(z, 5, s_204);
                    if (ret < 0) return ret;
                }
                break;
            case 210:
                {
                    int ret = slice_from_s(z, 7, s_205);
                    if (ret < 0) return ret;
                }
                break;
            case 211:
                {
                    int ret = slice_from_s(z, 3, s_206);
                    if (ret < 0) return ret;
                }
                break;
            case 212:
                {
                    int ret = slice_from_s(z, 3, s_207);
                    if (ret < 0) return ret;
                }
                break;
            case 213:
                {
                    int ret = slice_from_s(z, 8, s_207);
                    if (ret < 0) return ret;
                }
                break;
            case 214:
                {
                    int ret = slice_from_s(z, 7, s_208);
                    if (ret < 0) return ret;
                }
                break;
            case 215:
                {
                    int ret = slice_from_s(z, 7, s_209);
                    if (ret < 0) return ret;
                }
                break;
            case 216:
                {
                    int ret = slice_from_s(z, 4, s_210);
                    if (ret < 0) return ret;
                }
                break;
            case 217:
                {
                    int ret = slice_from_s(z, 5, s_211);
                    if (ret < 0) return ret;
                }
                break;
            case 218:
                {
                    int ret = slice_from_s(z, 9, s_212);
                    if (ret < 0) return ret;
                }
                break;
            case 219:
                {
                    int ret = slice_from_s(z, 5, s_213);
                    if (ret < 0) return ret;
                }
                break;
            case 220:
                {
                    int ret = slice_from_s(z, 11, s_214);
                    if (ret < 0) return ret;
                }
                break;
            case 221:
                {
                    int ret = slice_from_s(z, 5, s_215);
                    if (ret < 0) return ret;
                }
                break;
            case 222:
                {
                    int ret = slice_from_s(z, 8, s_216);
                    if (ret < 0) return ret;
                }
                break;
            case 223:
                {
                    int ret = slice_from_s(z, 6, s_217);
                    if (ret < 0) return ret;
                }
                break;
            case 224:
                {
                    int ret = slice_from_s(z, 9, s_218);
                    if (ret < 0) return ret;
                }
                break;
            case 225:
                {
                    int ret = slice_from_s(z, 6, s_219);
                    if (ret < 0) return ret;
                }
                break;
            case 226:
                {
                    int ret = slice_from_s(z, 9, s_220);
                    if (ret < 0) return ret;
                }
                break;
            case 227:
                {
                    int ret = slice_from_s(z, 6, s_221);
                    if (ret < 0) return ret;
                }
                break;
            case 228:
                {
                    int ret = slice_from_s(z, 12, s_222);
                    if (ret < 0) return ret;
                }
                break;
            case 229:
                {
                    int ret = slice_from_s(z, 5, s_223);
                    if (ret < 0) return ret;
                }
                break;
            case 230:
                {
                    int ret = slice_from_s(z, 6, s_224);
                    if (ret < 0) return ret;
                }
                break;
            case 231:
                {
                    int ret = slice_from_s(z, 4, s_225);
                    if (ret < 0) return ret;
                }
                break;
            case 232:
                {
                    int ret = slice_from_s(z, 3, s_226);
                    if (ret < 0) return ret;
                }
                break;
            case 233:
                {
                    int ret = slice_from_s(z, 9, s_227);
                    if (ret < 0) return ret;
                }
                break;
            case 234:
                {
                    int ret = slice_from_s(z, 6, s_228);
                    if (ret < 0) return ret;
                }
                break;
            case 235:
                {
                    int ret = slice_from_s(z, 6, s_229);
                    if (ret < 0) return ret;
                }
                break;
            case 236:
                {
                    int ret = slice_from_s(z, 6, s_230);
                    if (ret < 0) return ret;
                }
                break;
            case 237:
                {
                    int ret = slice_from_s(z, 6, s_231);
                    if (ret < 0) return ret;
                }
                break;
            case 238:
                {
                    int ret = slice_from_s(z, 7, s_232);
                    if (ret < 0) return ret;
                }
                break;
            case 239:
                {
                    int ret = slice_from_s(z, 5, s_233);
                    if (ret < 0) return ret;
                }
                break;
            case 240:
                {
                    int ret = slice_from_s(z, 9, s_234);
                    if (ret < 0) return ret;
                }
                break;
            case 241:
                {
                    int ret = slice_from_s(z, 8, s_235);
                    if (ret < 0) return ret;
                }
                break;
            case 242:
                {
                    int ret = slice_from_s(z, 10, s_236);
                    if (ret < 0) return ret;
                }
                break;
            case 243:
                {
                    int ret = slice_from_s(z, 7, s_237);
                    if (ret < 0) return ret;
                }
                break;
            case 244:
                {
                    int ret = slice_from_s(z, 7, s_238);
                    if (ret < 0) return ret;
                }
                break;
            case 245:
                {
                    int ret = slice_from_s(z, 6, s_239);
                    if (ret < 0) return ret;
                }
                break;
            case 246:
                {
                    int ret = slice_from_s(z, 8, s_240);
                    if (ret < 0) return ret;
                }
                break;
            case 247:
                {
                    int ret = slice_from_s(z, 14, s_241);
                    if (ret < 0) return ret;
                }
                break;
            case 248:
                {
                    int ret = slice_from_s(z, 7, s_242);
                    if (ret < 0) return ret;
                }
                break;
            case 249:
                {
                    int ret = slice_from_s(z, 4, s_243);
                    if (ret < 0) return ret;
                }
                break;
            case 250:
                {
                    int ret = slice_from_s(z, 7, s_243);
                    if (ret < 0) return ret;
                }
                break;
            case 251:
                {
                    int ret = slice_from_s(z, 4, s_244);
                    if (ret < 0) return ret;
                }
                break;
            case 252:
                {
                    int ret = slice_from_s(z, 7, s_245);
                    if (ret < 0) return ret;
                }
                break;
            case 253:
                {
                    int ret = slice_from_s(z, 6, s_246);
                    if (ret < 0) return ret;
                }
                break;
            case 254:
                {
                    int ret = slice_from_s(z, 4, s_247);
                    if (ret < 0) return ret;
                }
                break;
            case 255:
                {
                    int ret = slice_from_s(z, 5, s_248);
                    if (ret < 0) return ret;
                }
                break;
            case 256:
                {
                    int ret = slice_from_s(z, 5, s_249);
                    if (ret < 0) return ret;
                }
                break;
            case 257:
                {
                    int ret = slice_from_s(z, 3, s_250);
                    if (ret < 0) return ret;
                }
                break;
            case 258:
                {
                    int ret = slice_from_s(z, 8, s_251);
                    if (ret < 0) return ret;
                }
                break;
            case 259:
                {
                    int ret = slice_from_s(z, 7, s_252);
                    if (ret < 0) return ret;
                }
                break;
            case 260:
                {
                    int ret = slice_from_s(z, 9, s_253);
                    if (ret < 0) return ret;
                }
                break;
            case 261:
                {
                    int ret = slice_from_s(z, 8, s_254);
                    if (ret < 0) return ret;
                }
                break;
            case 262:
                {
                    int ret = slice_from_s(z, 4, s_255);
                    if (ret < 0) return ret;
                }
                break;
            case 263:
                {
                    int ret = slice_from_s(z, 5, s_256);
                    if (ret < 0) return ret;
                }
                break;
            case 264:
                {
                    int ret = slice_from_s(z, 3, s_257);
                    if (ret < 0) return ret;
                }
                break;
            case 265:
                {
                    int ret = slice_from_s(z, 5, s_258);
                    if (ret < 0) return ret;
                }
                break;
            case 266:
                {
                    int ret = slice_from_s(z, 6, s_259);
                    if (ret < 0) return ret;
                }
                break;
            case 267:
                {
                    int ret = slice_from_s(z, 5, s_260);
                    if (ret < 0) return ret;
                }
                break;
            case 268:
                {
                    int ret = slice_from_s(z, 7, s_261);
                    if (ret < 0) return ret;
                }
                break;
            case 269:
                {
                    int ret = slice_from_s(z, 4, s_262);
                    if (ret < 0) return ret;
                }
                break;
            case 270:
                {
                    int ret = slice_from_s(z, 6, s_263);
                    if (ret < 0) return ret;
                }
                break;
            case 271:
                {
                    int ret = slice_from_s(z, 4, s_264);
                    if (ret < 0) return ret;
                }
                break;
            case 272:
                {
                    int ret = slice_from_s(z, 3, s_265);
                    if (ret < 0) return ret;
                }
                break;
            case 273:
                {
                    int ret = slice_from_s(z, 4, s_266);
                    if (ret < 0) return ret;
                }
                break;
            case 274:
                {
                    int ret = slice_from_s(z, 7, s_267);
                    if (ret < 0) return ret;
                }
                break;
            case 275:
                {
                    int ret = slice_from_s(z, 10, s_267);
                    if (ret < 0) return ret;
                }
                break;
            case 276:
                {
                    int ret = slice_from_s(z, 6, s_268);
                    if (ret < 0) return ret;
                }
                break;
            case 277:
                {
                    int ret = slice_from_s(z, 4, s_269);
                    if (ret < 0) return ret;
                }
                break;
            case 278:
                {
                    int ret = slice_from_s(z, 6, s_270);
                    if (ret < 0) return ret;
                }
                break;
            case 279:
                {
                    int ret = slice_from_s(z, 6, s_271);
                    if (ret < 0) return ret;
                }
                break;
            case 280:
                {
                    int ret = slice_from_s(z, 6, s_272);
                    if (ret < 0) return ret;
                }
                break;
            case 281:
                {
                    int ret = slice_from_s(z, 7, s_273);
                    if (ret < 0) return ret;
                }
                break;
            case 282:
                {
                    int ret = slice_from_s(z, 9, s_274);
                    if (ret < 0) return ret;
                }
                break;
            case 283:
                {
                    int ret = slice_from_s(z, 8, s_275);
                    if (ret < 0) return ret;
                }
                break;
            case 284:
                {
                    int ret = slice_from_s(z, 6, s_276);
                    if (ret < 0) return ret;
                }
                break;
            case 285:
                {
                    int ret = slice_from_s(z, 5, s_277);
                    if (ret < 0) return ret;
                }
                break;
            case 286:
                {
                    int ret = slice_from_s(z, 5, s_278);
                    if (ret < 0) return ret;
                }
                break;
            case 287:
                {
                    int ret = slice_from_s(z, 7, s_278);
                    if (ret < 0) return ret;
                }
                break;
            case 288:
                {
                    int ret = slice_from_s(z, 6, s_279);
                    if (ret < 0) return ret;
                }
                break;
            case 289:
                {
                    int ret = slice_from_s(z, 6, s_280);
                    if (ret < 0) return ret;
                }
                break;
            case 290:
                {
                    int ret = slice_from_s(z, 6, s_281);
                    if (ret < 0) return ret;
                }
                break;
            case 291:
                {
                    int ret = slice_from_s(z, 4, s_282);
                    if (ret < 0) return ret;
                }
                break;
            case 292:
                {
                    int ret = slice_from_s(z, 4, s_283);
                    if (ret < 0) return ret;
                }
                break;
            case 293:
                {
                    int ret = slice_from_s(z, 10, s_284);
                    if (ret < 0) return ret;
                }
                break;
            case 294:
                {
                    int ret = slice_from_s(z, 6, s_285);
                    if (ret < 0) return ret;
                }
                break;
            case 295:
                {
                    int ret = slice_from_s(z, 9, s_286);
                    if (ret < 0) return ret;
                }
                break;
            case 296:
                {
                    int ret = slice_from_s(z, 5, s_287);
                    if (ret < 0) return ret;
                }
                break;
            case 297:
                {
                    int ret = slice_from_s(z, 7, s_288);
                    if (ret < 0) return ret;
                }
                break;
            case 298:
                {
                    int ret = slice_from_s(z, 7, s_289);
                    if (ret < 0) return ret;
                }
                break;
            case 299:
                {
                    int ret = slice_from_s(z, 5, s_290);
                    if (ret < 0) return ret;
                }
                break;
            case 300:
                {
                    int ret = slice_from_s(z, 6, s_291);
                    if (ret < 0) return ret;
                }
                break;
            case 301:
                {
                    int ret = slice_from_s(z, 3, s_292);
                    if (ret < 0) return ret;
                }
                break;
            case 302:
                {
                    int ret = slice_from_s(z, 7, s_293);
                    if (ret < 0) return ret;
                }
                break;
            case 303:
                {
                    int ret = slice_from_s(z, 10, s_294);
                    if (ret < 0) return ret;
                }
                break;
            case 304:
                {
                    int ret = slice_from_s(z, 7, s_295);
                    if (ret < 0) return ret;
                }
                break;
            case 305:
                {
                    int ret = slice_from_s(z, 9, s_296);
                    if (ret < 0) return ret;
                }
                break;
            case 306:
                {
                    int ret = slice_from_s(z, 8, s_297);
                    if (ret < 0) return ret;
                }
                break;
            case 307:
                {
                    int ret = slice_from_s(z, 5, s_298);
                    if (ret < 0) return ret;
                }
                break;
            case 308:
                {
                    int ret = slice_from_s(z, 7, s_299);
                    if (ret < 0) return ret;
                }
                break;
            case 309:
                {
                    int ret = slice_from_s(z, 6, s_300);
                    if (ret < 0) return ret;
                }
                break;
            case 310:
                {
                    int ret = slice_from_s(z, 6, s_301);
                    if (ret < 0) return ret;
                }
                break;
            case 311:
                {
                    int ret = slice_from_s(z, 6, s_302);
                    if (ret < 0) return ret;
                }
                break;
            case 312:
                {
                    int ret = slice_from_s(z, 5, s_303);
                    if (ret < 0) return ret;
                }
                break;
            case 313:
                {
                    int ret = slice_from_s(z, 4, s_304);
                    if (ret < 0) return ret;
                }
                break;
            case 314:
                {
                    int ret = slice_from_s(z, 6, s_305);
                    if (ret < 0) return ret;
                }
                break;
            case 315:
                {
                    int ret = slice_from_s(z, 7, s_306);
                    if (ret < 0) return ret;
                }
                break;
            case 316:
                {
                    int ret = slice_from_s(z, 5, s_307);
                    if (ret < 0) return ret;
                }
                break;
            case 317:
                {
                    int ret = slice_from_s(z, 6, s_308);
                    if (ret < 0) return ret;
                }
                break;
            case 318:
                {
                    int ret = slice_from_s(z, 4, s_309);
                    if (ret < 0) return ret;
                }
                break;
            case 319:
                {
                    int ret = slice_from_s(z, 6, s_310);
                    if (ret < 0) return ret;
                }
                break;
            case 320:
                {
                    int ret = slice_from_s(z, 6, s_311);
                    if (ret < 0) return ret;
                }
                break;
            case 321:
                {
                    int ret = slice_from_s(z, 5, s_312);
                    if (ret < 0) return ret;
                }
                break;
            case 322:
                {
                    int ret = slice_from_s(z, 3, s_313);
                    if (ret < 0) return ret;
                }
                break;
            case 323:
                {
                    int ret = slice_from_s(z, 10, s_313);
                    if (ret < 0) return ret;
                }
                break;
            case 324:
                {
                    int ret = slice_from_s(z, 3, s_314);
                    if (ret < 0) return ret;
                }
                break;
            case 325:
                {
                    int ret = slice_from_s(z, 6, s_315);
                    if (ret < 0) return ret;
                }
                break;
            case 326:
                {
                    int ret = slice_from_s(z, 6, s_316);
                    if (ret < 0) return ret;
                }
                break;
            case 327:
                {
                    int ret = slice_from_s(z, 11, s_317);
                    if (ret < 0) return ret;
                }
                break;
            case 328:
                {
                    int ret = slice_from_s(z, 3, s_318);
                    if (ret < 0) return ret;
                }
                break;
            case 329:
                {
                    int ret = slice_from_s(z, 4, s_319);
                    if (ret < 0) return ret;
                }
                break;
            case 330:
                {
                    int ret = slice_from_s(z, 4, s_320);
                    if (ret < 0) return ret;
                }
                break;
            case 331:
                {
                    int ret = slice_from_s(z, 6, s_321);
                    if (ret < 0) return ret;
                }
                break;
            case 332:
                {
                    int ret = slice_from_s(z, 10, s_322);
                    if (ret < 0) return ret;
                }
                break;
            case 333:
                {
                    int ret = slice_from_s(z, 4, s_323);
                    if (ret < 0) return ret;
                }
                break;
            case 334:
                {
                    int ret = slice_from_s(z, 6, s_324);
                    if (ret < 0) return ret;
                }
                break;
            case 335:
                {
                    int ret = slice_from_s(z, 4, s_325);
                    if (ret < 0) return ret;
                }
                break;
            case 336:
                {
                    int ret = slice_from_s(z, 10, s_326);
                    if (ret < 0) return ret;
                }
                break;
            case 337:
                {
                    int ret = slice_from_s(z, 10, s_327);
                    if (ret < 0) return ret;
                }
                break;
            case 338:
                {
                    int ret = slice_from_s(z, 5, s_328);
                    if (ret < 0) return ret;
                }
                break;
            case 339:
                {
                    int ret = slice_from_s(z, 5, s_329);
                    if (ret < 0) return ret;
                }
                break;
            case 340:
                {
                    int ret = slice_from_s(z, 7, s_330);
                    if (ret < 0) return ret;
                }
                break;
            case 341:
                {
                    int ret = slice_from_s(z, 4, s_331);
                    if (ret < 0) return ret;
                }
                break;
            case 342:
                {
                    int ret = slice_from_s(z, 3, s_332);
                    if (ret < 0) return ret;
                }
                break;
            case 343:
                {
                    int ret = slice_from_s(z, 5, s_332);
                    if (ret < 0) return ret;
                }
                break;
            case 344:
                {
                    int ret = slice_from_s(z, 4, s_333);
                    if (ret < 0) return ret;
                }
                break;
            case 345:
                {
                    int ret = slice_from_s(z, 5, s_334);
                    if (ret < 0) return ret;
                }
                break;
            case 346:
                {
                    int ret = slice_from_s(z, 4, s_335);
                    if (ret < 0) return ret;
                }
                break;
            case 347:
                {
                    int ret = slice_from_s(z, 7, s_336);
                    if (ret < 0) return ret;
                }
                break;
            case 348:
                {
                    int ret = slice_from_s(z, 3, s_337);
                    if (ret < 0) return ret;
                }
                break;
            case 349:
                {
                    int ret = slice_from_s(z, 3, s_338);
                    if (ret < 0) return ret;
                }
                break;
            case 350:
                {
                    int ret = slice_from_s(z, 8, s_339);
                    if (ret < 0) return ret;
                }
                break;
        }
        break;
    lab4:
        z->c = v_4;
        ((SN_local *)z)->i_p1 = z->l;
        {
            int v_5 = z->c;
            {
                int ret = skip_utf8(z->p, z->c, z->l, 3);
                if (ret < 0) goto lab6;
                z->c = ret;
            }
            ((SN_local *)z)->i_p1 = z->c;
        lab6:
            z->c = v_5;
        }
        ((SN_local *)z)->i_s2 = z->l;
        {
            int v_6 = z->c;
            {
                int ret = skip_utf8(z->p, z->c, z->l, 2);
                if (ret < 0) goto lab7;
                z->c = ret;
            }
            ((SN_local *)z)->i_s2 = z->c;
        lab7:
            z->c = v_6;
        }
        i_pr2 = z->l;
        {
            int v_7 = z->c;
            {
                int ret = out_grouping_U(z, g_v, 97, 121, 1);
                if (ret < 0) goto lab8;
                z->c += ret;
            }
            {
                int ret = in_grouping_U(z, g_v, 97, 121, 1);
                if (ret < 0) goto lab8;
                z->c += ret;
            }
            {
                int ret = out_grouping_U(z, g_v, 97, 121, 1);
                if (ret < 0) goto lab8;
                z->c += ret;
            }
            {
                int ret = in_grouping_U(z, g_v, 97, 121, 1);
                if (ret < 0) goto lab8;
                z->c += ret;
            }
            i_pr2 = z->c;
        lab8:
            z->c = v_7;
        }
        z->lb = z->c; z->c = z->l;
        {
            int v_8 = z->l - z->c;
            z->ket = z->c;
            if (z->c <= z->lb || z->p[z->c - 1] >> 5 != 3 || !((3958562 >> (z->p[z->c - 1] & 0x1f)) & 1)) goto lab9;
            {
                int c0 = z->c;
                among_var = find_among_b(z, a_2);
                if ((among_var & 0x4000)) do {
                    int c = z->c;
                    switch (among_var & 0x3F) {
                        case 0: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            among_var = 0;
                            break;
                        }
                        case 1: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 1;
                            among_var = 16384;
                            continue;
                        }
                        case 2: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 4;
                            among_var = 16385;
                            continue;
                        }
                        case 3: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 5;
                            among_var = 16386;
                            continue;
                        }
                        case 4: {
                            int ret = r_AfterV(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 1;
                            among_var = 16384;
                            continue;
                        }
                        case 5: {
                            int ret = r_AfterV(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 2;
                            among_var = 16388;
                            continue;
                        }
                        case 6: {
                            int ret = r_AfterC(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 1;
                            among_var = 16384;
                            continue;
                        }
                        case 7: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 2;
                            among_var = 16390;
                            continue;
                        }
                        case 8: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 2;
                            among_var = 16388;
                            continue;
                        }
                        case 9: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 4;
                            among_var = 16384;
                            continue;
                        }
                        case 10: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 5;
                            among_var = 16393;
                            continue;
                        }
                        case 11: {
                            int ret = r_AfterV(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            among_var = 0;
                            break;
                        }
                        case 12: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 2;
                            among_var = 16395;
                            continue;
                        }
                        case 13: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 3;
                            among_var = 16384;
                            continue;
                        }
                        case 14: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 2;
                            among_var = 16384;
                            continue;
                        }
                        case 15: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 4;
                            among_var = 16398;
                            continue;
                        }
                        case 16: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 3;
                            among_var = 16398;
                            continue;
                        }
                        case 17: {
                            int ret = r_AfterV(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 3;
                            among_var = 16398;
                            continue;
                        }
                        case 18: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 4;
                            among_var = 16401;
                            continue;
                        }
                        case 19: {
                            int ret = r_AfterV(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 3;
                            among_var = 16384;
                            continue;
                        }
                        case 20: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 3;
                            among_var = 16385;
                            continue;
                        }
                        case 21: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 4;
                            among_var = 16404;
                            continue;
                        }
                        case 22: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 2;
                            among_var = 16385;
                            continue;
                        }
                        case 23: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 3;
                            among_var = 16406;
                            continue;
                        }
                        case 24: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 4;
                            among_var = 16407;
                            continue;
                        }
                        case 25: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 1;
                            among_var = 16395;
                            continue;
                        }
                        case 26: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 2;
                            among_var = 16409;
                            continue;
                        }
                        case 27: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 3;
                            among_var = 16410;
                            continue;
                        }
                        case 28: {
                            int ret = r_AfterKGH(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            among_var = 0;
                            break;
                        }
                        case 29: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 2;
                            among_var = 16412;
                            continue;
                        }
                        case 30: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 3;
                            among_var = 16413;
                            continue;
                        }
                        case 31: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 5;
                            among_var = 16384;
                            continue;
                        }
                        case 32: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 6;
                            among_var = 16415;
                            continue;
                        }
                        case 33: {
                            int ret = r_AfterV(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 2;
                            among_var = 16385;
                            continue;
                        }
                        case 34: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 3;
                            among_var = 16417;
                            continue;
                        }
                        case 35: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 5;
                            among_var = 16406;
                            continue;
                        }
                        case 36: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 6;
                            among_var = 16419;
                            continue;
                        }
                        case 37: {
                            int ret = r_AfterKGH(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 2;
                            among_var = 16385;
                            continue;
                        }
                        case 38: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 3;
                            among_var = 16421;
                            continue;
                        }
                        case 39: {
                            int ret = r_AfterV(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 2;
                            among_var = 16409;
                            continue;
                        }
                        case 40: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 3;
                            among_var = 16423;
                            continue;
                        }
                        case 41: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 5;
                            among_var = 16410;
                            continue;
                        }
                        case 42: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 6;
                            among_var = 16425;
                            continue;
                        }
                        case 43: {
                            int ret = r_AfterKGH(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 2;
                            among_var = 16409;
                            continue;
                        }
                        case 44: {
                            int ret = r_R1(z);
                            if (ret > 0) { z->c = c; among_var = 1; break; }
                            z->c = c0 - 3;
                            among_var = 16427;
                            continue;
                        }
                    }
                    break;
                } while (1);
                if (!among_var) goto lab9;
            }
            z->bra = z->c;
            {
                int ret = slice_del(z);
                if (ret < 0) return ret;
            }
        lab9:
            z->c = z->l - v_8;
        }
        {
            int v_9 = z->l - z->c;
            {
                int v_10;
                if (z->c < ((SN_local *)z)->i_p1) goto lab10;
                v_10 = z->lb; z->lb = ((SN_local *)z)->i_p1;
                z->ket = z->c;
                if (z->c <= z->lb || z->p[z->c - 1] >> 5 != 3 || !((1058 >> (z->p[z->c - 1] & 0x1f)) & 1)) { z->lb = v_10; goto lab10; }
                if (!find_among_b(z, a_3)) { z->lb = v_10; goto lab10; }
                z->bra = z->c;
                z->lb = v_10;
            }
            {
                int ret = slice_del(z);
                if (ret < 0) return ret;
            }
        lab10:
            z->c = z->l - v_9;
        }
        {
            int v_11 = z->l - z->c;
            {
                int v_12;
                if (z->c < ((SN_local *)z)->i_p1) goto lab11;
                v_12 = z->lb; z->lb = ((SN_local *)z)->i_p1;
                z->ket = z->c;
                if (!(eq_s_b(z, 2, s_340))) { z->lb = v_12; goto lab11; }
                z->bra = z->c;
                z->lb = v_12;
            }
            if (((SN_local *)z)->i_p1 > z->c) goto lab11;
            if (i_pr2 > z->c) goto lab11;
            {
                int ret = slice_del(z);
                if (ret < 0) return ret;
            }
        lab11:
            z->c = z->l - v_11;
        }
        {
            int v_13 = z->l - z->c;
            z->ket = z->c;
            if (z->c <= z->lb || z->p[z->c - 1] >> 5 != 3 || !((265504 >> (z->p[z->c - 1] & 0x1f)) & 1)) goto lab12;
            among_var = find_among_b(z, a_4);
            if ((among_var & 0x4000)) {
                int c = z->c;
                switch (among_var & 0x3) {
                    case 0: {
                        int ret = r_R1(z);
                        if (ret > 0) { z->c = c; among_var = 2; break; }
                        among_var = 0;
                        break;
                    }
                    case 1: {
                        int ret = r_S2(z);
                        if (ret > 0) { z->c = c; among_var = 1; break; }
                        among_var = 0;
                        break;
                    }
                    case 2: {
                        int ret = r_S2(z);
                        if (ret > 0) { z->c = c; among_var = 3; break; }
                        among_var = 0;
                        break;
                    }
                }
            }
            if (!among_var) goto lab12;
            z->bra = z->c;
            switch (among_var) {
                case 1:
                    {
                        int ret = slice_from_s(z, 1, s_246);
                        if (ret < 0) return ret;
                    }
                    break;
                case 2:
                    {
                        int ret = slice_del(z);
                        if (ret < 0) return ret;
                    }
                    break;
                case 3:
                    {
                        int ret = slice_from_s(z, 1, s_249);
                        if (ret < 0) return ret;
                    }
                    break;
                case 4:
                    {
                        int ret = slice_from_s(z, 3, s_341);
                        if (ret < 0) return ret;
                    }
                    break;
            }
        lab12:
            z->c = z->l - v_13;
        }
        z->c = z->lb;
    } while (0);
    return 1;
}

extern struct SN_env * albanian_UTF_8_create_env(void) {
    return SN_new_env(sizeof(SN_local));
}
