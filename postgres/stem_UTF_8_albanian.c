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

#define s_75 (s_1 + 1)
#define s_106 (s_8 + 3)
#define s_37 (s_12 + 2)
#define s_180 (s_24 + 4)
#define s_307 (s_40 + 1)
#define s_333 (s_55 + 5)
#define s_201 (s_62 + 5)
#define s_68 (s_67 + 2)
#define s_334 (s_100 + 1)
#define s_309 (s_136 + 3)
#define s_242 (s_147 + 4)
#define s_185 (s_207 + 2)
#define s_60 (s_213 + 3)
#define s_244 (s_299 + 1)
#define s_251 (s_301 + 1)
#define s_294 (s_113 + 2)
#define s_272 (s_239 + 2)
#define s_32 (s_167 + 1)
#define s_19 (s_165 + 1)
#define s_249 (s_328 + 1)
#define s_193 (s_93 + 3)
#define s_117 (s_250 + 2)
#define s_271 (s_128 + 2)
#define s_104 (s_51 + 1)
#define s_107 (s_241 + 1)
#define s_125 (s_276 + 1)
#define s_203 (s_292 + 2)
#define s_296 (s_47 + 4)
#define s_77 (s_3 + 1)
#define s_224 (s_52 + 4)
#define s_154 (s_303 + 3)
#define s_123 (s_26 + 3)
#define s_189 (s_118 + 6)
#define s_247 (s_2 + 2)
#define s_54 (s_141 + 4)
#define s_177 (s_323 + 4)
#define s_55 (s_179 + 3)
#define s_290 (s_275 + 3)
#define s_119 (s_221 + 6)
#define s_311 (s_330 + 1)
#define s_53 (s_44 + 2)
#define s_156 (s_256 + 2)
#define s_10 (s_56 + 2)
#define s_102 (s_48 + 3)
#define s_129 (s_42 + 2)
#define s_312 (s_302 + 2)
#define s_252 (s_97 + 1)
#define s_71 (s_324 + 2)
#define s_73 (s_116 + 1)
#define s_157 (s_13 + 3)
#define s_178 (s_49 + 4)
#define s_243 (s_330 + 2)
#define s_21 (s_34 + 3)
#define s_38 (s_57 + 2)
#define s_20 (s_82 + 2)
#define s_305 (s_151 + 3)
#define s_295 (s_36 + 2)
#define s_70 (s_196 + 3)
#define s_327 (s_218 + 3)
#define s_250 (s_146 + 1)
#define s_67 (s_259 + 1)
#define s_263 (s_18 + 4)
#define s_158 (s_331 + 1)
#define s_274 (s_258 + 2)
#define s_12 (s_64 + 2)
#define s_155 (s_35 + 3)
#define s_149 (s_175 + 4)
#define s_300 (s_84 + 4)
#define s_298 (s_208 + 3)
#define s_190 (s_227 + 3)
#define s_51 (s_74 + 2)
#define s_103 (s_99 + 3)
#define s_42 (s_145 + 4)
#define s_273 (s_169 + 4)
#define s_202 (s_326 + 2)
#define s_43 (s_225 + 4)
#define s_270 (s_172 + 4)
#define s_108 (s_254 + 3)
#define s_262 (s_264 + 4)
#define s_80 (s_83 + 7)
#define s_72 (s_126 + 4)
#define s_304 (s_282 + 5)
#define s_176 (s_66 + 5)
#define s_65 (s_232 + 5)
#define s_241 (s_87 + 2)
#define s_113 (s_308 + 4)
#define s_26 (s_124 + 1)
#define s_114 (s_131 + 4)
#define s_128 (s_167 + 5)
#define s_52 (s_205 + 2)
#define s_109 (s_152 + 4)
#define s_222 (s_84 + 7)
#define s_69 (s_231 + 5)
#define s_110 (s_314 + 4)
#define s_265 (s_62 + 8)
#define s_61 (s_11 + 7)
#define s_111 (s_160 + 5)
#define s_112 (s_287 + 5)
#define s_275 (s_198 + 3)
#define s_310 (s_216 + 4)
#define s_303 (s_198 + 13)
#define s_159 (s_59 + 2)
#define s_105 (s_94 + 3)
#define s_286 (s_220 + 3)
#define s_313 (s_96 + 3)
#define s_316 (s_238 + 3)
#define s_7 (s_184 + 2)
#define s_188 (s_328 + 4)
#define s_277 (s_281 + 4)
#define s_297 (s_45 + 4)
#define s_260 (s_14 + 4)
#define s_115 (s_33 + 2)
#define s_318 (s_142 + 4)
#define s_256 (s_28 + 4)
#define s_240 (s_29 + 3)
#define s_116 (s_78 + 2)
#define s_166 (s_266 + 5)
#define s_173 (s_100 + 5)
#define s_253 (s_174 + 3)
#define s_284 (s_322 + 4)
#define s_182 (s_187 + 5)
#define s_195 (s_94 + 5)
#define s_325 (s_183 + 4)
#define s_285 (s_148 + 4)
#define s_200 (s_76 + 3)
#define s_321 (s_90 + 5)
#define s_257 (s_206 + 4)
#define s_331 (s_50 + 3)
#define s_4 (s_79 + 5)
#define s_98 (s_44 + 4)
#define s_302 (s_214 + 5)
#define s_301 (s_41 + 5)
#define s_279 (s_233 + 5)
#define s_317 (s_97 + 5)
#define s_197 (s_293 + 6)
#define s_246 (s_199 + 4)
#define s_267 (s_212 + 5)
#define s_299 (s_219 + 5)
#define s_255 (s_127 + 5)
#define s_283 (s_150 + 5)
#define s_153 (s_223 + 5)
#define s_289 (s_130 + 5)
#define s_162 (s_192 + 6)
#define s_329 (s_85 + 6)
#define s_100 (s_59 + 4)
#define s_291 (s_132 + 5)
#define s_245 (s_220 + 5)
#define s_281 (s_164 + 5)
#define s_330 (s_226 + 6)
#define s_168 (s_171 + 7)
#define s_259 (s_186 + 5)
#define s_194 (s_34 + 7)
#define s_269 (s_236 + 6)
#define s_191 (s_229 + 7)
#define s_332 (s_328 + 6)
#define s_248 (s_96 + 6)
#define s_292 (s_170 + 5)
#define s_258 (s_184 + 6)
#define s_324 (s_47 + 8)
#define s_196 (s_122 + 7)
#define s_288 (s_181 + 5)
#define s_276 (s_18 + 7)
#define s_1 (s_35 + 8)
#define s_266 (s_218 + 7)
#define s_268 (s_57 + 7)
#define s_280 (s_234 + 7)
#define s_293 (s_204 + 6)
#define s_278 (s_146 + 7)
#define s_161 (s_326 + 9)
#define s_163 (s_264 + 9)
#define s_99 (s_28 + 8)
#define s_254 (s_175 + 8)
#define s_261 (s_239 + 8)
#define s_187 (s_282 + 10)
#define s_199 (s_31 + 8)
#define s_306 (s_83 + 10)
#define s_101 (s_214 + 10)
#define s_183 (s_219 + 11)
#define s_322 (s_132 + 12)
#define s_287 (s_140 + 6)
#define s_192 (s_66 + 10)
#define s_165 (s_235 + 13)
#define s_264 (s_213 + 8)
#define s_282 (s_227 + 8)
#define s_198 (s_179 + 11)
static const symbol s_0[] = {
    'e', 'f', 'i', 'k', 'a', 's', 'i', 't',
    'e', 't'
};
static const symbol s_172[] = {
    'm', 'e', 'n', 'd', 's', 'h', 't', 'e',
    'p', 'i'
};
static const symbol s_2[] = {
    'a', 'd', 'r', 'e', 's', 't', 'o', 'r',
    'a', 'n', 't'
};
static const symbol s_3[] = {
    'a', 'f', 'a', 't', 'k', 'e', 'q', 'e',
    's', 'i'
};
static const symbol s_214[] = {
    'p', 'e', 'r', 'm', 'e', 't', 'r', 'u',
    'r', 'd', 'h', 'e', 'r', 'c', 'e', 'g',
    'o', 'v', 'i', 'n'
};
static const symbol s_5[] = { 'a', 'f', 't', 'e', 's', 'i' };
static const symbol s_6[] = { 'a', 'g', 'j', 'e', 'n', 'c', 'i' };
static const symbol s_236[] = {
    'p', 'r', 'o', 'g', 'r', 'e', 's', 'h',
    'q', 'i', 'p', 'e', 'r', 'i'
};
static const symbol s_8[] = { 'a', 'k', 's', 'i', 'd', 'e', 'n', 't' };
static const symbol s_9[] = {
    'a', 'k', 't', 'i', 'v', 'i', 't', 'e',
    't'
};
static const symbol s_226[] = {
    'p', 'r', 'e', 's', 'h', 'e', 'v', 'u',
    'r', 'a', 'd', 'i', 'o'
};
static const symbol s_11[] = {
    'a', 'l', 'e', 'k', 's', 'a', 'n', 'd',
    'r', 'e', 'j', 't', 'e', 's', 'i'
};
static const symbol s_218[] = {
    'p', 'e', 'r', 'v', 'o', 'n', 'e', 's',
    'h', 'o', 'h', 'i', 'm', 'a', 's', 'q'
};
static const symbol s_13[] = { 'a', 'n', 'g', 'l', 'i', 'r', 'i' };
static const symbol s_14[] = { 'a', 'n', 'k', 'e', 's', 'e', 'r', 'i' };
static const symbol s_15[] = { 'a', 'p', 'l', 'i', 'k', 'a', 'c', 'i' };
static const symbol s_16[] = { 'a', 'r', 'g', 'u', 'm', 'e', 'n', 't' };
static const symbol s_17[] = {
    'a', 'r', 'k', 'e', 'o', 'l', 'o', 'g',
    'j', 'i'
};
static const symbol s_18[] = {
    'a', 'r', 'r', 'i', 's', 'h', 'e', 's',
    'k', 'e', 'n', 'a', 'q', 'e', 's', 'i'
};
static const symbol s_174[] = {
    'm', 'e', 'r', 'r', 'u', 'm', 'a', 'n',
    'i'
};
static const symbol s_181[] = {
    'm', 'o', 'm', 'e', 'n', 't', 'e', 'k',
    'n', 'o', 'l', 'o', 'g', 'j', 'i'
};
static const symbol s_225[] = {
    'p', 'o', 'z', 'i', 'c', 'i', 'l', 'e',
    's', 'i'
};
static const symbol s_22[] = { 'a', 'u', 's', 't', 'r', 'a', 'l', 'i' };
static const symbol s_23[] = { 'a', 'u', 's', 't', 'r', 'i' };
static const symbol s_24[] = { 'a', 'u', 't', 'o', 'm', 'j', 'e', 't' };
static const symbol s_25[] = {
    'a', 'u', 't', 'o', 'r', 'i', 't', 'e',
    't'
};
static const symbol s_235[] = {
    'p', 'r', 'o', 'f', 'e', 's', 'i', 'o',
    'n', 'a', 'l', 'i', 'z', 'm', 'a', 'r',
    't', 'i', 'k', 'u', 'l', 'l'
};
static const symbol s_27[] = { 'b', 'a', 'l', 'l', 'q' };
static const symbol s_28[] = {
    'b', 'a', 'n', 'e', 's', 'a', 'l', 'i',
    'h', 'a', 'x', 'h', 'i', 's', 't', 'o',
    'r', 'i'
};
static const symbol s_29[] = {
    'b', 'a', 'n', 'q', 'e', 'v', 'e', 'r',
    'i'
};
static const symbol s_30[] = { 'b', 'a', 'r', 'a', 'z', 'i' };
static const symbol s_31[] = {
    'b', 'a', 's', 'h', 'k', 'e', 'p', 'u',
    'n', 'x', 'i', 'r', 'r', 'e', 'n', 'd',
    'e', 's', 'i'
};
static const symbol s_160[] = {
    'm', 'a', 'g', 'a', 'z', 'i', 'n', 't',
    'e', 'g', 'r', 'i', 't', 'e', 't'
};
static const symbol s_33[] = { 'b', 'e', 'j', 'a', 'p', 'o', 'n', 'i' };
static const symbol s_34[] = {
    'b', 'e', 'r', 'a', 't', 'h', 'i', 'n',
    'g', 'a', 'r', 'k', 'e', 's'
};
static const symbol s_35[] = {
    'b', 'e', 'r', 'l', 'i', 'c', 'e', 'n',
    'c', 'e', 'r', 'e', 'm', 'o', 'n', 'i'
};
static const symbol s_36[] = { 'b', 'e', 't', 'e', 'r', 'm', 'e', 't' };
static const symbol s_184[] = {
    'm', 'u', 'a', 'k', 's', 'e', 's', 'a',
    's', 'i', 'g', 'u', 'r', 'i'
};
static const symbol s_39[] = { 'b', 'r', 'i', 't', 'a', 'n', 'i' };
static const symbol s_40[] = { 'b', 'u', 'j', 'q', 'e', 's', 'i' };
static const symbol s_41[] = {
    'b', 'u', 'x', 'h', 'e', 't', 'r', 'u',
    'a', 'l', 'l'
};
static const symbol s_215[] = {
    'p', 'e', 'r', 'p', 'a', 'r', 'e', 's',
    'i'
};
static const symbol s_315[] = {
    'v', 'a', 'z', 'h', 'd', 'i', 'm', 'e',
    's', 'i'
};
static const symbol s_44[] = {
    'c', 'u', 'd', 'i', 'h', 'a', 'p', 'e',
    's', 'i', 'r'
};
static const symbol s_45[] = { 'd', 'e', 'b', 'a', 't', 'h', 'o', 't' };
static const symbol s_46[] = {
    'd', 'e', 'm', 'o', 'k', 'r', 'a', 'c',
    'i'
};
static const symbol s_47[] = {
    'd', 'e', 'p', 'u', 't', 'e', 't', 'o',
    'v', 'j', 'e', 'n', 'd', 'r', 'r'
};
static const symbol s_48[] = { 'd', 'e', 's', 'h', 'i', 'q' };
static const symbol s_49[] = { 'd', 'e', 's', 'h', 'm', 'i', 'q' };
static const symbol s_50[] = {
    'd', 'e', 't', 'y', 'l', 'l', 'o', 'g',
    'a', 'r', 'i'
};
static const symbol s_207[] = {
    'p', 'a', 'm', 'u', 'n', 'd', 'e', 's',
    'i'
};
static const symbol s_229[] = {
    'p', 'r', 'i', 's', 'h', 't', 'i', 'n',
    'd', 'e', 'r', 't', 'e', 's'
};
static const symbol s_221[] = {
    'p', 'o', 'l', 'i', 't', 'i', 'k', 'a',
    'n', 'a', 'b', 'i', 's'
};
static const symbol s_238[] = { 'p', 'r', 'o', 'v', 'd', 'i', 'q' };
static const symbol s_164[] = {
    'm', 'a', 'r', 't', 'e', 's', 't', 'r',
    'e', 's', 'o', 'l', 'l'
};
static const symbol s_56[] = { 'd', 'j', 'a', 'l', 'b', 'i' };
static const symbol s_57[] = {
    'd', 'o', 'b', 'i', 'z', 'n', 'e', 's',
    'h', 'p', 'e', 'j', 't', 'e', 's', 'i'
};
static const symbol s_58[] = { 'd', 'o', 'k', 'u', 'm', 'e', 'n', 't' };
static const symbol s_59[] = {
    'd', 'o', 'l', 'u', 'h', 'e', 'd', 'h',
    'i', 'm', 'e', 'n', 'y'
};
static const symbol s_328[] = {
    'v', 'r', 'i', 't', 'm', 'u', 'z', 'e',
    'd', 'h', 'e', 'n', 'e', 's'
};
static const symbol s_62[] = {
    'd', 'r', 'e', 'j', 't', 'o', 'r', 'e',
    's', 'h', 'k', 'r', 'e', 's'
};
static const symbol s_63[] = { 'd', 'r', 'e', 'j', 't', 'o', 'r', 'i' };
static const symbol s_64[] = {
    'd', 'u', 'a', 'm', 'b', 'i', 'e', 'n',
    't'
};
static const symbol s_206[] = {
    'p', 'a', 'g', 'e', 's', 'a', 'n', 'k',
    's', 'i'
};
static const symbol s_66[] = {
    'e', 'k', 'o', 'n', 'o', 'm', 'i', 'l',
    'i', 'o', 'n', 'd', 'j', 'e', 'k', 'i',
    'm', 'a', 'n', 'd', 'a', 't'
};
static const symbol s_219[] = {
    'p', 'e', 't', 'r', 'i', 't', 'r', 'a',
    'j', 'n', 'i', 'm', 'o', 't', 'i', 'v',
    'l', 'e', 'j', 't'
};
static const symbol s_230[] = {
    'p', 'r', 'i', 't', 's', 'h', 'm', 'e',
    'r', 'i'
};
static const symbol s_179[] = {
    'm', 'j', 'e', 'd', 'i', 's', 'k', 'r',
    'i', 'm', 'i', 'n', 'j', 'e', 's', 'i',
    's', 't', 'e', 'm', 'p', 'e', 'r', 'a',
    't', 'u', 'a', 'l', 'e', 't', 'e', 'r',
    's', 'i'
};
static const symbol s_234[] = {
    'p', 'r', 'o', 'd', 'h', 'u', 'e', 's',
    't', 'r', 'a', 't', 'e', 'g', 'j', 'i'
};
static const symbol s_239[] = {
    'p', 'u', 's', 'h', 't', 'e', 't', 'a',
    's', 'h', 'e', 'n', 'd', 'e', 't', 'e',
    's', 'i'
};
static const symbol s_233[] = {
    'p', 'r', 'o', 'c', 'e', 's', 't', 'a',
    't', 'u', 's'
};
static const symbol s_74[] = {
    'e', 'r', 'd', 'h', 'u', 'n', 'g', 'a',
    'r', 'i'
};
static const symbol s_76[] = {
    'e', 'u', 'r', 'o', 'p', 'e', 'r', 'a',
    'c', 'i'
};
static const symbol s_319[] = {
    'v', 'e', 'p', 'r', 'i', 'm', 't', 'a',
    'r', 'i'
};
static const symbol s_78[] = {
    'f', 'e', 'j', 'e', 'p', 'e', 'r', 's',
    'i'
};
static const symbol s_79[] = {
    'f', 'e', 'r', 'i', 'z', 'a', 'f', 'e',
    'r', 's', 'i'
};
static const symbol s_223[] = {
    'p', 'o', 'p', 'u', 'l', 'l', 'a', 'r',
    't', 'e', 's', 'i'
};
static const symbol s_81[] = { 'f', 'j', 'a', 'l', 'i' };
static const symbol s_82[] = { 'f', 'l', 'a', 's', 't', 'r', 'i', 't' };
static const symbol s_83[] = {
    'f', 'o', 't', 'o', 'g', 'r', 'a', 'f',
    'i', 'g', 'u', 'j', 'e', 's', 'j', 'e',
    'l', 'l', 'e', 's'
};
static const symbol s_84[] = {
    'f', 's', 'h', 'a', 't', 'r', 'o', 'p',
    'o', 'l', 'o', 'n', 'i'
};
static const symbol s_85[] = {
    'f', 'u', 'n', 'd', 'j', 'a', 'v', 'u',
    'l', 'l', 'n', 'e', 't'
};
static const symbol s_86[] = { 'f', 'u', 'n', 'k', 's', 'i' };
static const symbol s_87[] = {
    'f', 'u', 'q', 'i', 'n', 'd', 'u', 's',
    't', 'r', 'i'
};
static const symbol s_88[] = { 'g', 'a', 'r', 'a', 'n', 'c', 'i' };
static const symbol s_89[] = {
    'g', 'a', 't', 'i', 's', 'h', 'm', 'e',
    'r', 'i'
};
static const symbol s_90[] = {
    'g', 'j', 'a', 'k', 'o', 'v', 'i', 'd',
    'e', 'o'
};
static const symbol s_91[] = { 'g', 'j', 'a', 't', 'e', 's', 'i' };
static const symbol s_92[] = { 'g', 'j', 'e', 'j' };
static const symbol s_93[] = { 'g', 'j', 'e', 'n', 'e', 'v', 'o' };
static const symbol s_94[] = {
    'g', 'j', 'u', 'h', 'y', 'n', 'g', 'j',
    'y'
};
static const symbol s_95[] = { 'g', 'r', 'e', 'q', 'i' };
static const symbol s_96[] = {
    'g', 'r', 'e', 'v', 'a', 'j', 'r', 'e',
    'z', 'u', 'l', 't', 'a', 't'
};
static const symbol s_97[] = {
    'g', 'r', 'u', 'g', 'o', 'v', 'e', 'c',
    'o', 'r', 'i'
};
static const symbol s_213[] = {
    'p', 'e', 'r', 'd', 'o', 'r', 'u', 'e',
    's', 'h', 'k', 'o', 's', 'h', 'e', 'n',
    'i', 'm', 'a', 'q', 'e', 'd', 'o', 'n',
    'i'
};
static const symbol s_169[] = {
    'm', 'b', 'r', 'o', 's', 'h', 't', 'r',
    'e', 's'
};
static const symbol s_208[] = {
    'p', 'a', 'r', 't', 'i', 't', 'u', 'l',
    'l'
};
static const symbol s_170[] = {
    'm', 'e', 'h', 'm', 'e', 't', 'e', 'o',
    'r', 'i', 'g', 'j', 'i', 'n'
};
static const symbol s_212[] = {
    'p', 'e', 'n', 'g', 'e', 's', 'h', 'o',
    'q', 'e', 'r', 'i'
};
static const symbol s_320[] = {
    'v', 'e', 's', 'h', 't', 'i', 'r', 'e',
    's', 'i'
};
static const symbol s_167[] = {
    'm', 'b', 'a', 's', 'h', 'k', 'i', 's',
    'h', 't', 'e', 's'
};
static const symbol s_228[] = {
    'p', 'r', 'i', 'o', 'r', 'i', 't', 'e',
    't'
};
static const symbol s_323[] = {
    'v', 'i', 't', 'a', 'm', 'i', 'n', 'i',
    's', 't', 'r', 'i'
};
static const symbol s_175[] = {
    'm', 'e', 's', 'h', 'k', 'u', 'f', 'i',
    'r', 'u', 't', 'i', 'n', 'f', 'e', 'k',
    's', 'i'
};
static const symbol s_204[] = {
    'p', 'a', 'c', 'i', 'e', 'n', 't', 'e',
    'p', 'e', 'l', 'e', 'n', 'j', 'e', 'r',
    'i'
};
static const symbol s_205[] = {
    'p', 'a', 'd', 'i', 'a', 's', 'p', 'o',
    'r', 'o', 's', 'i'
};
static const symbol s_186[] = {
    'm', 'u', 'n', 'g', 'e', 's', 'e', 'l',
    'e', 'm', 'e', 'n', 't'
};
static const symbol s_314[] = {
    'v', 'a', 'k', 's', 'i', 'n', 's', 't',
    'i', 't', 'u', 'c', 'i'
};
static const symbol s_232[] = {
    'p', 'r', 'o', 'c', 'e', 'd', 'u', 'r',
    'r', 'e', 's'
};
static const symbol s_217[] = {
    'p', 'e', 'r', 's', 'o', 'n', 'a', 'l',
    'i', 't', 'e', 't'
};
static const symbol s_231[] = {
    'p', 'r', 'o', 'b', 'l', 'e', 'm', 'i',
    'g', 'r', 'a', 'n', 't'
};
static const symbol s_227[] = {
    'p', 'r', 'i', 'n', 'd', 'a', 'l', 'e',
    's', 't', 'r', 'u', 'k', 't', 'u', 'r',
    'i', 'z', 'm', 'u', 's', 'l', 'i', 'm',
    'o', 's', 'q'
};
static const symbol s_326[] = {
    'v', 'l', 'o', 'r', 'g', 'a', 'n', 'i',
    'z', 'm', 'a', 'k', 'i', 'n', 'e', 'r',
    'i'
};
static const symbol s_118[] = {
    'k', 'a', 'm', 'p', 'i', 'o', 'n', 'a',
    't', 'y', 'r'
};
static const symbol s_308[] = {
    'u', 'k', 'r', 'a', 'i', 'n', 't', 'e',
    'r', 'e', 's', 'i'
};
static const symbol s_120[] = { 'k', 'a', 'n', 'd', 'i', 'd', 'a', 't' };
static const symbol s_121[] = {
    'k', 'a', 'p', 'a', 'c', 'i', 't', 'e',
    't'
};
static const symbol s_122[] = {
    'k', 'a', 'r', 'a', 'n', 't', 'i', 'n',
    'g', 'r', 'e', 'm', 'o', 'c', 'i'
};
static const symbol s_237[] = { 'p', 'r', 'o', 'n', 'e', 's', 'i' };
static const symbol s_124[] = {
    'k', 'a', 'v', 'o', 'k', 'a', 't', 'e',
    'g', 'o', 'r', 'i'
};
static const symbol s_171[] = {
    'm', 'e', 'k', 'a', 'n', 'i', 'z', 'm',
    'b', 'l', 'i', 'd', 'h'
};
static const symbol s_126[] = {
    'k', 'e', 'r', 'c', 'e', 'n', 'e', 'r',
    'g', 'j', 'i'
};
static const symbol s_127[] = {
    'k', 'e', 'r', 'k', 'e', 's', 'a', 'k',
    't', 'e', 's', 'i'
};
static const symbol s_216[] = {
    'p', 'e', 'r', 'p', 'u', 'n', 'i', 'v',
    'e', 'r', 's', 'i', 't', 'e', 't'
};
static const symbol s_211[] = { 'p', 'a', 'v', 'a', 'r', 'e', 's', 'i' };
static const symbol s_130[] = {
    'k', 'l', 'i', 'e', 'n', 't', 'e', 'l',
    'e', 'f', 'o', 'n'
};
static const symbol s_131[] = {
    'k', 'o', 'k', 'a', 'i', 'n', 't', 'e',
    'r', 'n', 'e', 't'
};
static const symbol s_132[] = {
    'k', 'o', 'm', 'e', 'n', 't', 'e', 'n',
    't', 'a', 't', 'i', 'v', 'i', 'r', 'u',
    's', 'u', 'e', 'd', 'i'
};
static const symbol s_133[] = { 'k', 'o', 'm', 'i', 's', 'i' };
static const symbol s_134[] = { 'k', 'o', 'm', 'p', 'a', 'n', 'i' };
static const symbol s_135[] = {
    'k', 'o', 'm', 'p', 'r', 'o', 'm', 'i',
    's'
};
static const symbol s_136[] = {
    'k', 'o', 'm', 'u', 'n', 'i', 't', 'e',
    't'
};
static const symbol s_137[] = {
    'k', 'o', 'n', 's', 'e', 'n', 's', 'u',
    's'
};
static const symbol s_138[] = {
    'k', 'o', 'n', 't', 'a', 'b', 'i', 'l',
    'i', 't', 'e', 't'
};
static const symbol s_139[] = {
    'k', 'o', 'n', 't', 'r', 'i', 'b', 'u',
    't'
};
static const symbol s_140[] = {
    'k', 'o', 'n', 'v', 'e', 'n', 't', 'a',
    'v', 'o', 'l', 'i', 'n', 't', 'e', 'n',
    's', 'i', 't', 'e', 't'
};
static const symbol s_141[] = {
    'k', 'o', 'o', 'r', 'd', 'i', 'n', 'j',
    'i', 't', 'e', 't'
};
static const symbol s_142[] = { 'k', 'o', 's', 'o', 'v', 'e', 'l', 'l' };
static const symbol s_143[] = { 'k', 'o', 's', 't', 'o' };
static const symbol s_144[] = { 'k', 'r', 'e', 'd', 'i' };
static const symbol s_145[] = {
    'k', 'r', 'o', 'a', 'c', 'i', 'k', 'l',
    'a', 's'
};
static const symbol s_146[] = {
    'k', 'r', 'r', 'j', 'e', 't', 'e', 's',
    't', 'a', 'b', 'i', 'l', 'i', 't', 'e',
    't'
};
static const symbol s_147[] = {
    'k', 'r', 'y', 'e', 'q', 'y', 't', 'e',
    't'
};
static const symbol s_148[] = {
    'k', 't', 'h', 'e', 's', 'u', 'k', 's',
    'e', 's'
};
static const symbol s_210[] = { 'p', 'a', 's', 'q', 'y' };
static const symbol s_150[] = {
    'k', 'u', 'j', 't', 'e', 's', 't', 'u',
    'd', 'e', 'n', 't'
};
static const symbol s_151[] = { 'k', 'u', 'l', 't', 'u', 'r', 'q', 'i' };
static const symbol s_152[] = {
    'k', 'u', 'z', 'h', 'i', 'n', 'f', 'o',
    'r', 'm', 'a', 'c', 'i'
};
static const symbol s_220[] = {
    'p', 'j', 'e', 's', 'y', 'r', 'e', 'a',
    'l', 'i', 't', 'e', 't'
};
static const symbol s_209[] = {
    'p', 'a', 'r', 't', 'n', 'e', 'r', 'i',
    't', 'e', 't'
};

static const unsigned short a_0[] = {
    0x0000 , 0xC3C3 , 0x0003 , 0x0000 , 0xA7AB , 0xFFFE , 0xFFFF
};

static const unsigned short a_1[] = {
    0x0000 , 0x7A61 , 0x001C , 0x01A4 , 0x02A1 , 0x02D3 , 0x04A6 , 0x0532 ,
    0x061F , 0x06C6 , 0x0806 , 0x08D1 , 0x091C , 0x0AC5 , 0x0B7D , 0x0E0C ,
    0x0F4B , 0x0F8A , 0x1150 , 0x118F , 0x1278 , 0x14D2 , 0x161B , 0x1683 ,
    0x0000 , 0x0000 , 0x17F7 , 0x1807 , 0x0000 , 0x7664 , 0x0031 , 0x0000 ,
    0x0036 , 0x0063 , 0x0000 , 0x0000 , 0x0000 , 0x006D , 0x0097 , 0x00A9 ,
    0x00AF , 0x0000 , 0x00BC , 0x0000 , 0x00D0 , 0x016C , 0x0179 , 0x017E ,
    0x019F , 0x0000 , 0x0004 , 0xFFFF , S(6572), S(6573), 0x0000 , 0x7461 ,
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
    0x0000 , 0x00F3 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x00FA , 0x0000 , 0x015B , 0x0000 , 0x6868 , 0x00E6 , 0x0000 , 0x6575 ,
    0xFFB4 , 0x00EA , 0x0000 , 0x7272 , 0xFFB4 , 0x0000 , 0x0006 , 0xFFF0 ,
    S(6D75), S(6E65), S(6574), 0x0000 , 0x0007 , 0xFFEF , S(6F65), S(6F6C),
    S(6A67), S(0069), 0x0000 , 0x6969 , 0x00FD , 0x0000 , 0x7468 , 0x010C ,
    0x0000 , 0x011C , 0x0000 , 0x0000 , 0x0000 , 0x012F , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0137 , 0x0000 , 0x6565 , 0x010F , 0x0000 ,
    0x746A , 0xFFEE , 0x0000 , 0x0000 , 0x0000 , 0xFFEE , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0xFFEE , 0x0012 , 0x6E61 , 0xFFEE , 0x0000 ,
    0x0000 , 0x0000 , 0xFFEE , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x012C , 0x012C , 0x0000 , 0x6565 , 0xFFEE , 0x0012 ,
    0x6974 , 0x0133 , 0x012C , 0x0012 , 0x6D6E , 0xFFEE , 0xFFEE , 0x0012 ,
    0x7561 , 0xFFEE , 0x0000 , 0x0000 , 0x0000 , 0x014E , 0x0000 , 0x0000 ,
    0x0000 , 0xFFEE , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0158 , 0x0012 , 0x746D ,
    0xFFEE , 0xFFEE , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0xFFEE ,
    0x0000 , 0x7272 , 0xFFEE , 0x0000 , 0x0004 , 0x0160 , S(6B69), S(6A75),
    0x0013 , 0x7673 , 0x0166 , 0xFFED , 0x0000 , 0x0169 , 0x0000 , 0x6868 ,
    0xFFED , 0x0000 , 0x6565 , 0xFFED , 0x0000 , 0x6874 , 0x0170 , 0x0174 ,
    0x0000 , 0x0002 , 0xFF8A , S(6574), 0x0000 , 0x0003 , 0xFFEC , S(6972),
    S(0074), 0x0000 , 0x0004 , 0xFFEB , S(6968), S(656E), 0x0000 , 0x7374 ,
    0x0182 , 0x018E , 0x0000 , 0x0002 , 0x0186 , S(7274), 0x0000 , 0x6169 ,
    0x018A , 0xFFE9 , 0x0000 , 0x0002 , 0xFFEA , S(696C), 0x0000 , 0x6F6F ,
    0x0191 , 0x0000 , 0x6D72 , 0x0195 , 0x019A , 0x0000 , 0x0003 , 0xFFE8 ,
    S(656A), S(0074), 0x0000 , 0x0004 , 0xFFE7 , S(7469), S(7465), 0x0000 ,
    0x0004 , 0xFFE6 , S(6B6F), S(7461), 0x0000 , 0x7561 , 0x01BB , 0x0000 ,
    0x0000 , 0x0000 , 0x01F2 , 0x0000 , 0x0000 , 0x0000 , 0x0272 , 0x0285 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x028D ,
    0x0000 , 0x0000 , 0x0293 , 0x0000 , 0x736C , 0x01C5 , 0x0000 , 0x01CA ,
    0x0000 , 0x0000 , 0x0000 , 0x01D5 , 0x01DA , 0x0000 , 0x0004 , 0xFFE5 ,
    S(6B6C), S(6E61), 0x0000 , 0x656B , 0x01CE , 0x01D2 , 0x0000 , 0x0002 ,
    0xFFE4 , S(6573), 0x0000 , 0x6161 , 0xFFE3 , 0x0000 , 0x0003 , 0xFFE2 ,
    S(7A61), S(0069), 0x0000 , 0x0002 , 0x01DE , S(6B68), 0x0000 , 0x6569 ,
    0x01E2 , 0x01E8 , 0x0000 , 0x0005 , 0xFFE1 , S(7570), S(696E), S(006D),
    0x0020 , 0x7374 , 0x01EC , 0x01EF , 0x0000 , 0x6868 , 0xFFE0 , 0x0000 ,
    0x6565 , 0xFFE0 , 0x0000 , 0x7466 , 0x0203 , 0x0000 , 0x0207 , 0x0000 ,
    0x0229 , 0x0000 , 0x0000 , 0x0000 , 0x0234 , 0x0000 , 0x0000 , 0x0000 ,
    0x0250 , 0x0265 , 0x0268 , 0x0000 , 0x0002 , 0xFFDF , S(6574), 0x0000 ,
    0x6575 , 0x020B , 0x0225 , 0x0000 , 0x746A , 0xFFDF , 0x0000 , 0x0000 ,
    0x0218 , 0x0218 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x021B , 0xFFDF ,
    0x0021 , 0x6969 , 0xFFDF , 0x0000 , 0x6868 , 0x021E , 0x0021 , 0x6169 ,
    0xFFDF , 0x0222 , 0x0000 , 0x6E6E , 0xFFDF , 0x0021 , 0x0002 , 0xFFDF ,
    S(696E), 0x0000 , 0x696D , 0x022D , 0x0231 , 0x0000 , 0x0002 , 0xFFDF ,
    S(696E), 0x0000 , 0x6565 , 0xFFDF , 0x0021 , 0x7465 , 0xFFDF , 0x0000 ,
    0x0000 , 0x0000 , 0x0246 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0231 , 0x0021 , 0x746D ,
    0xFFDF , 0xFFDF , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0xFFDF ,
    0x0000 , 0x6C61 , 0x025E , 0x0000 , 0x0000 , 0x0000 , 0xFFDF , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0261 , 0x0000 , 0x7474 ,
    0xFFDE , 0x0000 , 0x0002 , 0xFFDD , S(6E69), 0x0000 , 0x6868 , 0xFFDF ,
    0x0000 , 0x6565 , 0x026B , 0x0021 , 0x6A6A , 0x026E , 0x0000 , 0x6165 ,
    0xFFDC , 0xFFDC , 0x0000 , 0x657A , 0x0276 , 0x027D , 0x0000 , 0x6D73 ,
    0xFFDB , 0x027A , 0x0000 , 0x6868 , 0xFFDB , 0x0000 , 0x0003 , 0x0282 ,
    S(656E), S(0073), 0x0026 , 0x6565 , 0xFFDA , 0x0000 , 0x0002 , 0x0289 ,
    S(7265), 0x0025 , 0x6569 , 0xFFDB , 0xFFDB , 0x0000 , 0x0005 , 0xFFD9 ,
    S(7469), S(6E61), S(0069), 0x0000 , 0x6A78 , 0x0297 , 0x029C , 0x0000 ,
    0x0004 , 0xFFD8 , S(6571), S(6973), 0x0000 , 0x0003 , 0xFFD7 , S(6568),
    S(0074), 0x0000 , 0x7565 , 0x02B4 , 0x0000 , 0x0000 , 0x0000 , 0x02BE ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x02CF , 0x0000 , 0x0006 , 0x02BA , S(6572),
    S(6F6D), S(696E), 0x002A , 0x0002 , 0xFFD6 , S(6574), 0x0000 , 0x6B6C ,
    0x02C2 , 0x02C6 , 0x0000 , 0x0002 , 0xFFD5 , S(6C65), 0x0000 , 0x0003 ,
    0x02CB , S(7365), S(0069), 0x002C , 0x0002 , 0xFFD4 , S(6574), 0x0000 ,
    0x0002 , 0xFFD3 , S(6964), 0x0000 , 0x7561 , 0x02EA , 0x0000 , 0x0000 ,
    0x0000 , 0x0312 , 0x0000 , 0x0000 , 0x0368 , 0x039E , 0x0411 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0424 , 0x0000 , 0x0000 , 0x0462 , 0x0000 ,
    0x0000 , 0x0482 , 0x0000 , 0x6C73 , 0x02EE , 0x02F5 , 0x003C , 0x6569 ,
    0xFFC4 , 0x02F2 , 0x0000 , 0x6D6D , 0xFFC4 , 0x0000 , 0x6868 , 0x02F8 ,
    0x0000 , 0x756B , 0x0305 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0308 , 0x030F , 0x0000 , 0x6161 , 0xFFBF ,
    0x0000 , 0x6575 , 0xFFBF , 0x030C , 0x0000 , 0x6E6E , 0xFFBF , 0x0000 ,
    0x7272 , 0xFFBF , 0x0000 , 0x7462 , 0x0327 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0xFFC4 , 0x032B ,
    0x0000 , 0x0000 , 0x0335 , 0x0000 , 0x0000 , 0x033A , 0x035F , 0x0000 ,
    0x0002 , 0xFFD2 , S(7461), 0x0000 , 0x0006 , 0x0331 , S(6B6F), S(6172),
    S(6963), 0x002F , 0x0002 , 0xFFD1 , S(6574), 0x0000 , 0x0004 , 0xFFD0 ,
    S(7475), S(7465), 0x0000 , 0x6868 , 0x033D , 0x0000 , 0x6D61 , 0xFFBF ,
    0x0000 , 0x0000 , 0x0000 , 0x034C , 0x0000 , 0x0000 , 0x0000 , 0x0350 ,
    0x0000 , 0x0000 , 0x0000 , 0x0358 , 0x0041 , 0x6D6E , 0xFFBF , 0xFFBF ,
    0x0041 , 0x0002 , 0x0354 , S(6572), 0x0031 , 0x6E73 , 0xFFCF , 0xFFCF ,
    0x0000 , 0x6969 , 0x035B , 0x0032 , 0x0002 , 0xFFCE , S(6574), 0x0000 ,
    0x0003 , 0x0364 , S(7279), S(0065), 0x0033 , 0x6E73 , 0xFFCD , 0xFFCD ,
    0x0000 , 0x7561 , 0x037F , 0x0000 , 0x0000 , 0x0000 , 0x0393 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x039A , 0x0077 ,
    0x746D , 0x0389 , 0x038C , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x038F ,
    0x0389 , 0x0000 , 0x6565 , 0xFF89 , 0x0077 , 0x6565 , 0xFF89 , 0x0000 ,
    0x0002 , 0xFF89 , S(6568), 0x0000 , 0x6E6E , 0x0396 , 0x0000 , 0x6574 ,
    0xFF89 , 0x0389 , 0x0000 , 0x0002 , 0xFFCC , S(656E), 0x0000 , 0x7461 ,
    0x03B4 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x03BA , 0x03DD , 0x03E0 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x03FE , 0x0409 , 0x0000 , 0x0005 , 0xFFCB , S(7073),
    S(726F), S(0061), 0x003C , 0x7465 , 0x03CC , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x03CF , 0x0000 , 0x0000 , 0x0000 , 0x03D3 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x03DA , 0x0000 , 0x7474 , 0xFFC4 , 0x0000 ,
    0x6165 , 0xFFC4 , 0xFFC4 , 0x0000 , 0x6969 , 0x03D6 , 0x003C , 0x6D6E ,
    0xFFC4 , 0xFFC4 , 0x0000 , 0x6565 , 0xFFC4 , 0x0000 , 0x6565 , 0xFFCA ,
    0x0000 , 0x7461 , 0xFFCA , 0x0000 , 0x0000 , 0x0000 , 0xFFCA , 0x0000 ,
    0x0000 , 0x0000 , 0x03F6 , 0x03F9 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x03DD , 0x0000 , 0x6D6D ,
    0xFFCA , 0x0000 , 0x0004 , 0xFFC9 , S(7469), S(7465), 0x0000 , 0x686B ,
    0xFFCA , 0x0402 , 0x0000 , 0x0007 , 0xFFC8 , S(6972), S(696D), S(696E),
    S(006D), 0x0000 , 0x6975 , 0xFFCA , 0x040D , 0x0000 , 0x6E72 , 0xFFCA ,
    0xFFCA , 0x0000 , 0x0002 , 0x0415 , S(6D65), 0x0039 , 0x7673 , 0x041B ,
    0x041E , 0x0000 , 0x0421 , 0x0000 , 0x6868 , 0xFFC7 , 0x0039 , 0x6565 ,
    0xFFC7 , 0x0000 , 0x6565 , 0xFFC7 , 0x0000 , 0x7362 , 0x0438 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x043F , 0x0443 ,
    0x0000 , 0x0000 , 0x0449 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x045A ,
    0x0000 , 0x6969 , 0x043B , 0x003A , 0x0002 , 0xFFC6 , S(6574), 0x0000 ,
    0x6165 , 0xFFBF , 0xFFBF , 0x0000 , 0x0006 , 0xFFC5 , S(6D75), S(6E65),
    S(6574), 0x0041 , 0x6974 , 0x044D , 0x0457 , 0x0041 , 0x746D , 0xFFBF ,
    0xFFBF , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0xFFBF , 0x0000 ,
    0x6565 , 0xFFBF , 0x0000 , 0x0002 , 0x045E , S(6968), 0x0000 , 0x6E74 ,
    0xFFBF , 0xFFBF , 0x0000 , 0x0003 , 0x0467 , S(6A65), S(0074), 0x0000 ,
    0x656F , 0x046B , 0x046F , 0x0000 , 0x0002 , 0xFFC2 , S(6973), 0x0000 ,
    0x7272 , 0x0472 , 0x0000 , 0x6569 , 0x0476 , 0x047E , 0x0000 , 0x0002 ,
    0x047A , S(6873), 0x0000 , 0x6165 , 0xFFC1 , 0xFFC1 , 0x0000 , 0x0002 ,
    0xFFC0 , S(6574), 0x0000 , 0x6172 , 0x0486 , 0x04A1 , 0x0041 , 0x736A ,
    0x043F , 0x0000 , 0xFFC4 , 0x0000 , 0xFFBF , 0x0000 , 0x0000 , 0x0000 ,
    0x0492 , 0x049E , 0x003D , 0x7673 , 0x0498 , 0xFFC3 , 0x0000 , 0x049B ,
    0x0000 , 0x6868 , 0xFFC3 , 0x0000 , 0x6565 , 0xFFC3 , 0x0000 , 0x6868 ,
    0xFFBF , 0x0000 , 0x0003 , 0xFFBE , S(6572), S(0073), 0x0000 , 0x7566 ,
    0x04B8 , 0x0000 , 0x0000 , 0x0000 , 0x04BF , 0x04C6 , 0x04D0 , 0x04D6 ,
    0x04FF , 0x0000 , 0x0514 , 0x0000 , 0x0519 , 0x0522 , 0x0000 , 0x0527 ,
    0x0000 , 0x0008 , 0xFFBD , S(6B69), S(7361), S(7469), S(7465), 0x0000 ,
    0x6161 , 0x04C2 , 0x004C , 0x0002 , 0xFFB4 , S(696E), 0x0000 , 0x0005 ,
    0x04CC , S(6E6F), S(6D6F), S(0069), 0x0044 , 0x0002 , 0xFFBC , S(6574),
    0x0000 , 0x0006 , 0xFFBB , S(6D65), S(6E65), S(6574), 0x0000 , 0x6F61 ,
    0xFFBA , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x04E7 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x04ED , 0x0000 ,
    0x0006 , 0xFFB9 , S(7267), S(6E61), S(6574), 0x0000 , 0x0005 , 0x04F3 ,
    S(6963), S(6E6F), S(0065), 0x0048 , 0x7673 , 0x04F9 , 0xFFB8 , 0x0000 ,
    0x04FC , 0x0000 , 0x6868 , 0xFFB8 , 0x0000 , 0x6565 , 0xFFB8 , 0x0000 ,
    0x6465 , 0x0503 , 0x050B , 0x0000 , 0x0003 , 0x0508 , S(7265), S(0072),
    0x0049 , 0x6161 , 0xFFB7 , 0x0000 , 0x0004 , 0x0510 , S(6772), S(696A),
    0x004A , 0x0002 , 0xFFB6 , S(6574), 0x0000 , 0x0004 , 0xFFB5 , S(7265),
    S(6973), 0x0000 , 0x6164 , 0xFFB3 , 0x051D , 0x0000 , 0x0003 , 0xFFB4 ,
    S(6568), S(006D), 0x0000 , 0x0003 , 0xFF8A , S(7468), S(0065), 0x0000 ,
    0x0002 , 0x052B , S(6F72), 0x0000 , 0x6E73 , 0xFFB2 , 0x052F , 0x0000 ,
    0x6868 , 0xFFB2 , 0x0000 , 0x7561 , 0x0549 , 0x0000 , 0x0000 , 0x0000 ,
    0x055A , 0x0000 , 0x0000 , 0x0000 , 0x056A , 0x0573 , 0x0000 , 0x0578 ,
    0x0000 , 0x0000 , 0x05BB , 0x0000 , 0x0000 , 0x0000 , 0x05ED , 0x0000 ,
    0x05F9 , 0x0000 , 0x0007 , 0x0550 , S(6B74), S(7165), S(7365), S(0069),
    0x004F , 0x7374 , 0x0554 , 0x0557 , 0x0000 , 0x6868 , 0xFFB1 , 0x0000 ,
    0x6565 , 0xFFB1 , 0x0050 , 0x736E , 0x0562 , 0x0000 , 0x0000 , 0x0000 ,
    0x0565 , 0x0562 , 0x0000 , 0x6565 , 0xFFB0 , 0x0000 , 0x0004 , 0xFFAF ,
    S(7A69), S(6A61), 0x0000 , 0x0004 , 0x056F , S(7567), S(6572), 0x0052 ,
    0x6E73 , 0xFFAE , 0xFFAE , 0x0000 , 0x0003 , 0xFFAD , S(6C61), S(0069),
    0x0000 , 0x6961 , 0x0583 , 0x0000 , 0x0000 , 0x0000 , 0x058D , 0x0000 ,
    0x0000 , 0x0000 , 0x0590 , 0x0000 , 0x7373 , 0x0586 , 0x0054 , 0x6569 ,
    0xFFAC , 0x058A , 0x0000 , 0x6D6D , 0xFFAC , 0x0000 , 0x7474 , 0xFFAC ,
    0x0000 , 0x7374 , 0x0594 , 0x05AB , 0x0000 , 0x746A , 0x05A1 , 0x0000 ,
    0x0000 , 0x0000 , 0x05A4 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x05A1 , 0x0000 , 0x6565 , 0xFFAC , 0x0000 , 0x6969 , 0x05A7 , 0x0054 ,
    0x6D6E , 0xFFAC , 0xFFAC , 0x0000 , 0x6565 , 0x05AE , 0x0000 , 0x746A ,
    0xFFAC , 0x0000 , 0x0000 , 0x0000 , 0xFFAC , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0xFFAC , 0x0000 , 0x6C74 , 0x05BF , 0x05DD , 0x0054 ,
    0x7561 , 0xFFAC , 0x0000 , 0x0000 , 0x0000 , 0x05D6 , 0x0000 , 0x0000 ,
    0x0000 , 0xFFAC , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x05DA , 0x0000 , 0x6D6E ,
    0xFFAC , 0xFFAC , 0x0000 , 0x7272 , 0xFFAC , 0x0000 , 0x0006 , 0x05E3 ,
    S(676F), S(6172), S(6966), 0x0000 , 0x7374 , 0x05E7 , 0x05EA , 0x0000 ,
    0x6868 , 0xFFAB , 0x0000 , 0x6565 , 0xFFAB , 0x0000 , 0x0003 , 0x05F2 ,
    S(6168), S(0074), 0x0056 , 0x6969 , 0x05F5 , 0x0056 , 0x6E74 , 0xFFAA ,
    0xFFAA , 0x0000 , 0x6E71 , 0x05FD , 0x0618 , 0x0000 , 0x646B , 0x0601 ,
    0x0606 , 0x0000 , 0x0004 , 0xFFA9 , S(616A), S(6576), 0x0000 , 0x0005 ,
    0x060C , S(6973), S(6E6F), S(0065), 0x0058 , 0x7673 , 0x0612 , 0xFFA8 ,
    0x0000 , 0x0615 , 0x0000 , 0x6868 , 0xFFA8 , 0x0000 , 0x6565 , 0xFFA8 ,
    0x0000 , 0x6969 , 0x061B , 0x0059 , 0x0002 , 0xFFA7 , S(6574), 0x0000 ,
    0x7261 , 0x0633 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0647 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x06AC , 0x0000 , 0x7274 , 0x0637 , 0x0640 , 0x0000 ,
    0x0004 , 0x063C , S(6E61), S(6963), 0x005A , 0x0002 , 0xFFA6 , S(6574),
    0x0000 , 0x0007 , 0xFFA5 , S(7369), S(6D68), S(7265), S(0069), 0x0000 ,
    0x7561 , 0x065E , 0x0000 , 0x0000 , 0x0000 , 0x066C , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x06A4 , 0x0000 , 0x6B74 ,
    0x0662 , 0x0667 , 0x0000 , 0x0003 , 0xFFA4 , S(766F), S(0065), 0x0000 ,
    0x0003 , 0xFFA3 , S(7365), S(0069), 0x0000 , 0x746A , 0x0679 , 0x0000 ,
    0x0000 , 0x0000 , 0x0688 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x06A1 , 0x005E , 0x6E65 , 0xFFA2 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0685 , 0x0685 , 0x0000 , 0x6565 , 0xFFA2 ,
    0x0000 , 0x7465 , 0x069A , 0x0000 , 0x0000 , 0x0000 , 0x069E , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0685 , 0x0000 , 0x0002 , 0xFFA1 , S(6576), 0x0000 , 0x6D6D ,
    0xFFA2 , 0x0000 , 0x6969 , 0xFFA2 , 0x0000 , 0x0002 , 0x06A8 , S(6568),
    0x0000 , 0x6E74 , 0xFFA0 , 0xFFA0 , 0x0000 , 0x6165 , 0x06B0 , 0x06BC ,
    0x0063 , 0x7673 , 0x06B6 , 0x06B9 , 0x0000 , 0x06B9 , 0x0000 , 0x6868 ,
    0xFF9D , 0x0000 , 0x6565 , 0xFF9D , 0x0000 , 0x7176 , 0x06C0 , 0x06C3 ,
    0x0000 , 0x6969 , 0xFF9F , 0x0000 , 0x6565 , 0xFF9E , 0x0000 , 0x7961 ,
    0x06E1 , 0x0000 , 0x0000 , 0x0000 , 0x0700 , 0x0000 , 0x0000 , 0x0000 ,
    0x0756 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x07AA , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x07CF , 0x0000 , 0x0000 , 0x0000 ,
    0x07D5 , 0x0000 , 0x7870 , 0x06EC , 0x0000 , 0x06F9 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x06FC , 0x0000 , 0x0005 , 0x06F2 , S(7365),
    S(7269), S(0061), 0x0064 , 0x7476 , 0xFF9C , 0x06F6 , 0x0000 , 0x6565 ,
    0xFF9C , 0x0000 , 0x6969 , 0xFFEE , 0x0000 , 0x0002 , 0xFF9B , S(6968),
    0x0000 , 0x7264 , 0x0711 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0732 ,
    0x074F , 0x0000 , 0x6868 , 0x0714 , 0x0066 , 0x7565 , 0x0727 , 0x0000 ,
    0x0000 , 0x0000 , 0x072B , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x072E , 0x0066 ,
    0x0002 , 0xFF9A , S(6873), 0x0000 , 0x6E6E , 0xFF9A , 0x0000 , 0x6E72 ,
    0xFF9A , 0xFF9A , 0x0068 , 0x7565 , 0x0745 , 0x0000 , 0x0000 , 0x0000 ,
    0x0749 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x074C , 0x0068 , 0x0002 , 0xFF98 ,
    S(6873), 0x0000 , 0x6E6E , 0xFF98 , 0x0000 , 0x7272 , 0xFF98 , 0x0000 ,
    0x0008 , 0xFF99 , S(6563), S(6F67), S(6976), S(656E), 0x0000 , 0x7364 ,
    0x0768 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0796 , 0x0000 , 0x07A1 ,
    0x0000 , 0x6868 , 0x076B , 0x0066 , 0x6E65 , 0x0777 , 0x0000 , 0x0000 ,
    0x0000 , 0x078C , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0790 , 0x0000 ,
    0x746A , 0xFF9A , 0x0000 , 0x0000 , 0x0000 , 0x0784 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0787 , 0xFF9A , 0x0066 , 0x6969 , 0xFF9A , 0x0000 ,
    0x0003 , 0xFF9A , S(6968), S(006E), 0x0000 , 0x0002 , 0xFF9A , S(696E),
    0x0000 , 0x6969 , 0x0793 , 0x0066 , 0x6E6E , 0xFF9A , 0x0000 , 0x6974 ,
    0x079A , 0x079E , 0x0000 , 0x0002 , 0xFF98 , S(696E), 0x0000 , 0x6565 ,
    0xFF98 , 0x0000 , 0x0004 , 0x07A6 , S(6F74), S(6972), 0x0069 , 0x0002 ,
    0xFF97 , S(6574), 0x0000 , 0x6471 , 0x07AE , 0x07C0 , 0x0000 , 0x6868 ,
    0x07B1 , 0x0066 , 0x6961 , 0xFF9A , 0x0000 , 0x0000 , 0x0000 , 0x07BC ,
    0x0000 , 0x0000 , 0x0000 , 0xFF9A , 0x0000 , 0x6D6E , 0xFF9A , 0xFF9A ,
    0x0068 , 0x6961 , 0xFF98 , 0x0000 , 0x0000 , 0x0000 , 0x07CB , 0x0000 ,
    0x0000 , 0x0000 , 0xFF98 , 0x0000 , 0x6D6E , 0xFF98 , 0xFF98 , 0x0000 ,
    0x0005 , 0xFF96 , S(676E), S(7261), S(0069), 0x006B , 0x7368 , 0x07E3 ,
    0x0000 , 0x07E7 , 0x07F9 , 0x0000 , 0x07F6 , 0x07FC , 0x0000 , 0x0000 ,
    0x0000 , 0x0800 , 0x0803 , 0x0000 , 0x0002 , 0xFF95 , S(7465), 0x0000 ,
    0x6D61 , 0xFF95 , 0x0000 , 0x0000 , 0x0000 , 0xFF95 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x07F6 , 0x0000 , 0x6565 ,
    0xFF95 , 0x0000 , 0x6161 , 0xFF95 , 0x0000 , 0x0002 , 0xFF95 , S(6574),
    0x006B , 0x6565 , 0xFF95 , 0x0000 , 0x6868 , 0xFF95 , 0x0000 , 0x7364 ,
    0x0818 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0825 , 0x0000 , 0x08A7 , 0x0000 , 0x0000 , 0x08AB ,
    0x0000 , 0x6565 , 0x081B , 0x0000 , 0x7374 , 0x081F , 0x0822 , 0x0000 ,
    0x6868 , 0xFF94 , 0x0000 , 0x6565 , 0xFF94 , 0x0000 , 0x7464 , 0x0838 ,
    0x0000 , 0x0842 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x086B , 0x087F ,
    0x0000 , 0x0005 , 0x083E , S(7375), S(7274), S(0069), 0x006D , 0x0002 ,
    0xFF93 , S(6574), 0x0000 , 0x656F , 0x0846 , 0x0858 , 0x0000 , 0x0006 ,
    0x084C , S(736B), S(6F69), S(656E), 0x006E , 0x7673 , 0x0852 , 0xFF92 ,
    0x0000 , 0x0855 , 0x0000 , 0x6868 , 0xFF92 , 0x0000 , 0x6565 , 0xFF92 ,
    0x0000 , 0x0008 , 0x085F , S(6D72), S(6361), S(6F69), S(656E), 0x006F ,
    0x7673 , 0x0865 , 0xFF91 , 0x0000 , 0x0868 , 0x0000 , 0x6868 , 0xFF91 ,
    0x0000 , 0x6565 , 0xFF91 , 0x0000 , 0x0009 , 0x0873 , S(6974), S(7574),
    S(6963), S(6E6F), S(0065), 0x0070 , 0x7673 , 0x0879 , 0xFF90 , 0x0000 ,
    0x087C , 0x0000 , 0x6868 , 0xFF90 , 0x0000 , 0x6565 , 0xFF90 , 0x0000 ,
    0x6565 , 0x0882 , 0x0000 , 0x7267 , 0x0890 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0896 , 0x0000 , 0x0000 , 0x0000 , 0x089C ,
    0x0000 , 0x0005 , 0xFF8F , S(6972), S(6574), S(0074), 0x0000 , 0x0005 ,
    0xFF8E , S(6973), S(6574), S(0074), 0x0000 , 0x656E , 0x08A0 , 0x08A3 ,
    0x0000 , 0x7373 , 0xFF8D , 0x0000 , 0x0002 , 0xFF8C , S(7465), 0x0077 ,
    0x0002 , 0xFF89 , S(7465), 0x0000 , 0x6868 , 0x08AE , 0x0000 , 0x7461 ,
    0xFF8A , 0x0000 , 0x0000 , 0x0000 , 0xFF8A , 0x0000 , 0x0000 , 0x0000 ,
    0x08C4 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x08CE , 0x0000 , 0x746D , 0xFF8A , 0xFF8A ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0xFF8A , 0x0000 , 0x6565 ,
    0xFF8A , 0x0000 , 0x6961 , 0x08DC , 0x0000 , 0x0000 , 0x0000 , 0x08FB ,
    0x0000 , 0x0000 , 0x0000 , 0x0918 , 0x0000 , 0x706D , 0xFF8A , 0x08CE ,
    0x0000 , 0x08E2 , 0x0077 , 0x6F65 , 0x08EF , 0x0000 , 0x0000 , 0x0000 ,
    0x08F3 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x08F7 , 0x0077 ,
    0x0002 , 0xFF89 , S(6873), 0x0000 , 0x6D6E , 0xFF89 , 0xFF89 , 0x0000 ,
    0x0002 , 0xFF8B , S(696E), 0x0000 , 0x746D , 0x0905 , 0x0000 , 0x0000 ,
    0x0908 , 0x0000 , 0x0000 , 0x0910 , 0x0913 , 0x0076 , 0x6969 , 0xFF8A ,
    0x0000 , 0x6974 , 0x090C , 0x0389 , 0x0000 , 0x0002 , 0xFF89 , S(696E),
    0x0000 , 0x6868 , 0xFF8A , 0x0000 , 0x0003 , 0xFF88 , S(7365), S(0065),
    0x0076 , 0x0002 , 0xFF8A , S(696E), 0x0000 , 0x7561 , 0x0933 , 0x0000 ,
    0x0000 , 0x0000 , 0x096E , 0x0000 , 0x0000 , 0x0000 , 0x099B , 0x0000 ,
    0x0000 , 0x09AA , 0x0000 , 0x0000 , 0x09B7 , 0x0000 , 0x0000 , 0x0A48 ,
    0x0000 , 0x0A79 , 0x0A7E , 0x0000 , 0x766D , 0x093F , 0x0945 , 0x0000 ,
    0x0953 , 0x0000 , 0x0959 , 0x0000 , 0x095F , 0x0000 , 0x0969 , 0x0083 ,
    0x0006 , 0xFF87 , S(6970), S(6E6F), S(7461), 0x0000 , 0x6164 , 0x0949 ,
    0x094E , 0x0000 , 0x0003 , 0xFF86 , S(6962), S(0073), 0x0000 , 0x0004 ,
    0xFF85 , S(6469), S(7461), 0x0000 , 0x0006 , 0xFF84 , S(6361), S(7469),
    S(7465), 0x0000 , 0x0006 , 0xFF83 , S(6E61), S(6974), S(656E), 0x0000 ,
    0x0005 , 0x0965 , S(6765), S(726F), S(0069), 0x007E , 0x0002 , 0xFF82 ,
    S(6574), 0x0000 , 0x0004 , 0xFF81 , S(6A61), S(7365), 0x0000 , 0x726D ,
    0x0976 , 0x0979 , 0x0000 , 0x0000 , 0x0000 , 0x098D , 0x0083 , 0x6969 ,
    0xFF7D , 0x0000 , 0x6961 , 0x0984 , 0x0000 , 0x0000 , 0x0000 , 0xFF7D ,
    0x0000 , 0x0000 , 0x0000 , 0xFF7D , 0x0000 , 0x0004 , 0x0989 , S(6571),
    S(6973), 0x0080 , 0x0002 , 0xFF80 , S(6574), 0x0000 , 0x636B , 0x0991 ,
    0x0996 , 0x0000 , 0x0004 , 0xFF7F , S(6E65), S(6D69), 0x0000 , 0x0003 ,
    0xFF7E , S(7365), S(0065), 0x0000 , 0x0003 , 0x09A0 , S(6873), S(0069),
    0x0000 , 0x746D , 0xFF7D , 0xFF7D , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0xFF7D , 0x0000 , 0x6169 , 0x09AE , 0x09B2 , 0x0000 , 0x0002 ,
    0xFF7C , S(6573), 0x0000 , 0x0004 , 0xFF7B , S(6E65), S(6574), 0x0000 ,
    0x736B , 0x09C2 , 0x0000 , 0x09C7 , 0x0A12 , 0x0A33 , 0x0000 , 0x0000 ,
    0x0000 , 0x0A39 , 0x0000 , 0x0004 , 0xFF7A , S(6961), S(656E), 0x0000 ,
    0x7565 , 0x09DA , 0x0000 , 0x0000 , 0x0000 , 0x09DF , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x09EC , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0A06 , 0x0000 , 0x0003 , 0xFF79 , S(746E), S(0065), 0x0000 ,
    0x0005 , 0x09E5 , S(6973), S(6E6F), S(0065), 0x0088 , 0x7476 , 0xFF78 ,
    0x09E9 , 0x0000 , 0x6565 , 0xFF78 , 0x0000 , 0x6172 , 0x09F0 , 0x09FE ,
    0x0000 , 0x0002 , 0x09F4 , S(696E), 0x0089 , 0x7374 , 0x09F8 , 0x09FB ,
    0x0000 , 0x6868 , 0xFF77 , 0x0000 , 0x6565 , 0xFF77 , 0x0000 , 0x0004 ,
    0x0A03 , S(6D6F), S(7369), 0x008A , 0x6565 , 0xFF76 , 0x0000 , 0x6E6E ,
    0x0A09 , 0x0000 , 0x6569 , 0xFF75 , 0x0A0D , 0x0000 , 0x0003 , 0xFF74 ,
    S(6574), S(0074), 0x0000 , 0x7673 , 0x0A18 , 0x0A1E , 0x0000 , 0x0A2E ,
    0x0000 , 0x0005 , 0xFF73 , S(6E65), S(7573), S(0073), 0x0000 , 0x6172 ,
    0x0A22 , 0x0A29 , 0x0000 , 0x0007 , 0xFF72 , S(6962), S(696C), S(6574),
    S(0074), 0x0000 , 0x0004 , 0xFF71 , S(6269), S(7475), 0x0000 , 0x0004 ,
    0xFF70 , S(6E65), S(6574), 0x0000 , 0x0006 , 0xFF6F , S(6472), S(6E69),
    S(6D69), 0x0000 , 0x6F74 , 0x0A3D , 0x0A44 , 0x0000 , 0x7676 , 0x0A40 ,
    0x0000 , 0x6165 , 0xFF6E , 0xFF6E , 0x0000 , 0x0002 , 0xFF6D , S(6E6F),
    0x0000 , 0x7965 , 0x0A5F , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0A6E , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0A73 , 0x0000 ,
    0x6475 , 0x0A63 , 0x0A6A , 0x0000 , 0x6969 , 0x0A66 , 0x0094 , 0x0002 ,
    0xFF6C , S(6574), 0x0000 , 0x6E74 , 0xFF6A , 0xFF6A , 0x0000 , 0x0003 ,
    0xFF6B , S(6361), S(0069), 0x0000 , 0x0006 , 0xFF69 , S(7165), S(7479),
    S(7465), 0x0000 , 0x0004 , 0xFF68 , S(6568), S(6573), 0x0000 , 0x7A66 ,
    0x0A95 , 0x0000 , 0x0000 , 0x0000 , 0x0AB2 , 0x0000 , 0x0AB7 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0AC0 , 0x0000 , 0x6969 , 0x0A98 ,
    0x0099 , 0x6A6E , 0x0A9C , 0x0AAB , 0x0099 , 0x7673 , 0x0AA2 , 0x0AA5 ,
    0x0000 , 0x0AA8 , 0x0000 , 0x6868 , 0xFF67 , 0x0099 , 0x6565 , 0xFF67 ,
    0x0000 , 0x6565 , 0xFF67 , 0x0000 , 0x6A6A , 0x0AAE , 0x0099 , 0x7476 ,
    0x0AA8 , 0x0AA8 , 0x0000 , 0x0004 , 0xFF66 , S(6574), S(6573), 0x0000 ,
    0x0004 , 0x0ABC , S(7574), S(6572), 0x009B , 0x6E73 , 0xFF65 , 0xFF65 ,
    0x0000 , 0x0004 , 0xFF64 , S(6968), S(656E), 0x0000 , 0x7561 , 0x0ADC ,
    0x0000 , 0x0000 , 0x0000 , 0x0AED , 0x0000 , 0x0000 , 0x0000 , 0x0B02 ,
    0x0000 , 0x0000 , 0x0B2C , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0B32 , 0x0000 , 0x7273 , 0x0AE0 , 0x0AE9 ,
    0x0000 , 0x0004 , 0x0AE5 , S(6574), S(6973), 0x009D , 0x0002 , 0xFF63 ,
    S(6574), 0x0000 , 0x0002 , 0xFF60 , S(6568), 0x0000 , 0x746E , 0x0AF6 ,
    0x0000 , 0x0000 , 0x0000 , 0x0AF9 , 0x0000 , 0x0AFD , 0x0000 , 0x6565 ,
    0xFF60 , 0x0000 , 0x6569 , 0xFF60 , 0xFF60 , 0x0000 , 0x0004 , 0xFF62 ,
    S(7265), S(6973), 0x0000 , 0x7263 , 0x0B14 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0B19 ,
    0x0000 , 0x0000 , 0x0000 , 0x0B27 , 0x0000 , 0x0004 , 0xFF61 , S(6E65),
    S(6173), 0x0000 , 0x6974 , 0x0B1D , 0x0AF6 , 0x00A0 , 0x746D , 0xFF60 ,
    0xFF60 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0xFF60 , 0x0000 ,
    0x0003 , 0xFF5F , S(7469), S(0065), 0x0000 , 0x0005 , 0xFF5E , S(676F),
    S(7261), S(0069), 0x0000 , 0x6161 , 0x0B35 , 0x0000 , 0x736A , 0x0B41 ,
    0x0000 , 0x0000 , 0x0000 , 0x0B61 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0B7A , 0x00A3 , 0x7461 , 0xFF5D , 0x0000 , 0x0000 , 0x0000 , 0xFF5D ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0B57 ,
    0x0B57 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0B5A , 0x0000 ,
    0x6565 , 0xFF5D , 0x00A3 , 0x6975 , 0xFF5D , 0x0B5E , 0x0000 , 0x7272 ,
    0xFF5D , 0x0000 , 0x7461 , 0xFF5D , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0B77 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0B57 , 0x0000 ,
    0x6D6D , 0xFF5D , 0x0000 , 0x6868 , 0xFF5D , 0x0000 , 0x7561 , 0x0B94 ,
    0x0BF1 , 0x0000 , 0x0000 , 0x0D11 , 0x0000 , 0x0000 , 0x0000 , 0x0D64 ,
    0x0D92 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0DA0 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0DBF , 0x0000 , 0x7367 , 0x0BA3 , 0x0000 ,
    0x0000 , 0x0000 , 0x0BA9 , 0x0000 , 0x0000 , 0x0BB6 , 0x0000 , 0x0000 ,
    0x0BBB , 0x0BC1 , 0x0BE1 , 0x0000 , 0x0005 , 0xFF5C , S(7A61), S(6E69),
    S(0065), 0x0000 , 0x0003 , 0x0BAE , S(6E69), S(0065), 0x00A5 , 0x0002 ,
    0x0BB2 , S(6972), 0x00A6 , 0x0002 , 0xFF5A , S(6574), 0x0000 , 0x0003 ,
    0xFF59 , S(6164), S(0074), 0x0000 , 0x0005 , 0xFF58 , S(6465), S(6E6F),
    S(0069), 0x0000 , 0x7469 , 0x0BCF , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0BD3 , 0x0000 , 0x0BD6 , 0x0000 ,
    0x6D6E , 0xFF4D , 0xFF4D , 0x00B3 , 0x6565 , 0xFF4D , 0x0000 , 0x6569 ,
    0x0BDA , 0x0BDE , 0x0000 , 0x0002 , 0xFF57 , S(6573), 0x0000 , 0x6E6E ,
    0xFF56 , 0x0000 , 0x686B , 0x0BE5 , 0x0BEE , 0x0000 , 0x0004 , 0x0BEA ,
    S(756B), S(6C6C), 0x00B4 , 0x0002 , 0xFF4C , S(6E69), 0x0000 , 0x6161 ,
    0xFF55 , 0x0000 , 0x7261 , 0x0C05 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0C69 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0CB4 , 0x0000 , 0x6E68 , 0x0C0E ,
    0x0000 , 0x0C26 , 0x0000 , 0x0000 , 0x0000 , 0x0C65 , 0x0000 , 0x6565 ,
    0x0C11 , 0x0000 , 0x746A , 0xFF54 , 0x0000 , 0x0000 , 0x0C1E , 0xFF54 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0C21 , 0xFF54 , 0x0000 , 0x6969 ,
    0xFF54 , 0x0000 , 0x0003 , 0xFF54 , S(6968), S(006E), 0x00AC , 0x7461 ,
    0xFF54 , 0x0000 , 0x0000 , 0x0000 , 0x0C3C , 0x0000 , 0x0000 , 0x0000 ,
    0x0C40 , 0x0000 , 0x0000 , 0x0000 , 0x0C44 , 0x0C44 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0C47 , 0x00AC , 0x0002 , 0xFF54 , S(696E),
    0x0000 , 0x0002 , 0xFF54 , S(696E), 0x0000 , 0x6565 , 0xFF54 , 0x00AC ,
    0x7561 , 0xFF54 , 0x0000 , 0x0000 , 0x0000 , 0x0C5E , 0x0000 , 0x0000 ,
    0x0000 , 0xFF54 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0C62 , 0x00AC , 0x6D6E ,
    0xFF54 , 0xFF54 , 0x0000 , 0x7272 , 0xFF54 , 0x00AC , 0x6974 , 0x0C5E ,
    0x0C44 , 0x0000 , 0x6F65 , 0x0C76 , 0x0000 , 0x0000 , 0x0000 , 0x0C98 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0CAC , 0x0000 , 0x0002 ,
    0x0C7A , S(6864), 0x00AD , 0x7565 , 0x0C8D , 0x0000 , 0x0000 , 0x0000 ,
    0x0C91 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0C95 , 0x00AD , 0x0002 , 0xFF53 ,
    S(6873), 0x0000 , 0x6D6E , 0xFF53 , 0xFF53 , 0x0000 , 0x7272 , 0xFF53 ,
    0x0000 , 0x0002 , 0x0C9C , S(6864), 0x0000 , 0x6574 , 0x0CA0 , 0x0CA9 ,
    0x0000 , 0x6A73 , 0xFF53 , 0x0CA4 , 0x0000 , 0x0003 , 0xFF53 , S(6968),
    S(006E), 0x0000 , 0x6565 , 0xFF53 , 0x0000 , 0x0002 , 0x0CB0 , S(6864),
    0x00AD , 0x6569 , 0x0C91 , 0xFF53 , 0x0000 , 0x6F6F , 0x0CB7 , 0x0000 ,
    0x6E68 , 0x0CC0 , 0x0000 , 0x0CDB , 0x0000 , 0x0000 , 0x0000 , 0x0D0D ,
    0x0000 , 0x6565 , 0x0CC3 , 0x0000 , 0x746A , 0xFF52 , 0x0000 , 0x0000 ,
    0x0CD0 , 0x0CD3 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0CD6 , 0xFF52 ,
    0x0000 , 0x6969 , 0xFF52 , 0x00AE , 0x6969 , 0xFF52 , 0x0000 , 0x0003 ,
    0xFF52 , S(6968), S(006E), 0x00AE , 0x7465 , 0xFF52 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0CED , 0x0CED , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0CF0 , 0x0000 , 0x6565 , 0xFF52 ,
    0x00AE , 0x7561 , 0xFF52 , 0x0000 , 0x0000 , 0x0000 , 0x0D07 , 0x0000 ,
    0x0000 , 0x0000 , 0xFF52 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0D0A , 0x00AE ,
    0x6E6E , 0xFF52 , 0x0000 , 0x7272 , 0xFF52 , 0x00AE , 0x6974 , 0x0D07 ,
    0x0CED , 0x0000 , 0x7368 , 0x0D1F , 0x0000 , 0x0000 , 0x0D24 , 0x0000 ,
    0x0000 , 0x0D2A , 0x0000 , 0x0000 , 0x0000 , 0x0D3A , 0x0D5E , 0x0000 ,
    0x0003 , 0xFF51 , S(656D), S(0074), 0x0000 , 0x0006 , 0xFF50 , S(6E61),
    S(7A69), S(6D65), 0x0000 , 0x6479 , 0x0D2E , 0x0D32 , 0x00B1 , 0x0002 ,
    0xFF4F , S(6574), 0x0000 , 0x0002 , 0x0D36 , S(6572), 0x00B2 , 0x6E73 ,
    0xFF4E , 0xFF4E , 0x0000 , 0x7465 , 0x0D4C , 0x0000 , 0x0000 , 0x0000 ,
    0xFF4D , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0D50 , 0x0000 , 0x0000 ,
    0x0000 , 0x0D53 , 0x0000 , 0x0D57 , 0x0000 , 0x6E74 , 0xFF4D , 0xFF4D ,
    0x0000 , 0x6969 , 0xFF4D , 0x0000 , 0x7475 , 0x0D57 , 0x0D5A , 0x0000 ,
    0x6565 , 0xFF4D , 0x0000 , 0x0002 , 0xFF4D , S(696E), 0x0000 , 0x0005 ,
    0xFF4C , S(6B68), S(6A75), S(0074), 0x0000 , 0x726C , 0x0D6D , 0x0000 ,
    0x0D7D , 0x0000 , 0x0000 , 0x0D84 , 0x0D8E , 0x0000 , 0x696A , 0x0D71 ,
    0x0D79 , 0x0000 , 0x0002 , 0x0D75 , S(6E6F), 0x00B5 , 0x6569 , 0xFF4B ,
    0xFF4B , 0x0000 , 0x0002 , 0xFF4B , S(6E6F), 0x0000 , 0x0007 , 0xFF4A ,
    S(7369), S(7274), S(7469), S(0065), 0x0000 , 0x7374 , 0x0D88 , 0x0D8B ,
    0x0000 , 0x6868 , 0xFF49 , 0x00B7 , 0x6565 , 0xFF49 , 0x0000 , 0x0002 ,
    0x0D4C , S(6572), 0x0000 , 0x6565 , 0x0D95 , 0x0000 , 0x6474 , 0x0D99 ,
    0xFF47 , 0x0000 , 0x0002 , 0x0D9D , S(7369), 0x00B8 , 0x6565 , 0xFF48 ,
    0x0000 , 0x746D , 0x0DAA , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0DAF ,
    0x0DB6 , 0x0DBA , 0x0000 , 0x0004 , 0xFF46 , S(6E65), S(6574), 0x0000 ,
    0x6565 , 0x0DB2 , 0x0000 , 0x6D74 , 0xFF4D , 0xFF4D , 0x0000 , 0x0002 ,
    0xFF45 , S(616B), 0x0000 , 0x0003 , 0xFF44 , S(7669), S(0065), 0x0000 ,
    0x7A61 , 0x0DDB , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0DE2 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0DFA , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0E07 , 0x0000 , 0x6A72 , 0x0DDF , 0xFF4D , 0x0000 ,
    0x7474 , 0xFF43 , 0x0000 , 0x6467 , 0x0DE6 , 0x0DF5 , 0x0000 , 0x0003 ,
    0x0DEB , S(7365), S(0069), 0x00BE , 0x7374 , 0x0DEF , 0x0DF2 , 0x0000 ,
    0x6868 , 0xFF42 , 0x00BE , 0x6565 , 0xFF42 , 0x0000 , 0x0003 , 0xFF41 ,
    S(7365), S(0065), 0x0000 , 0x0006 , 0x0E00 , S(696C), S(616D), S(656E),
    0x0000 , 0x7476 , 0xFF40 , 0x0E04 , 0x0000 , 0x6565 , 0xFF40 , 0x0000 ,
    0x0003 , 0xFF3F , S(7465), S(0065), 0x0000 , 0x7861 , 0x0E26 , 0x0000 ,
    0x0000 , 0x0E2F , 0x0EB0 , 0x0000 , 0x0EC3 , 0x0000 , 0x0000 , 0x0F01 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0F13 , 0x0000 , 0x0004 ,
    0x0E2B , S(7974), S(6172), 0x00C3 , 0x0002 , 0xFF3D , S(6576), 0x0000 ,
    0x6F61 , 0x0E40 , 0x0000 , 0x0000 , 0x0000 , 0x0E45 , 0x0000 , 0x0000 ,
    0x0000 , 0x0E4B , 0x0E81 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0E9E ,
    0x0000 , 0x0004 , 0xFF3C , S(656C), S(6573), 0x0000 , 0x0005 , 0xFF3B ,
    S(7472), S(7365), S(0065), 0x0000 , 0x7171 , 0x0E4E , 0x00C6 , 0x7465 ,
    0x0E60 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0E75 , 0x0000 , 0x0000 ,
    0x0000 , 0x0E78 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0E7E ,
    0x00C6 , 0x746A , 0xFF3A , 0x0000 , 0x0000 , 0x0000 , 0x0E6D , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0E70 , 0xFF3A , 0x00C6 , 0x6969 , 0xFF3A ,
    0x0000 , 0x0003 , 0xFF3A , S(6968), S(006E), 0x0000 , 0x6161 , 0xFF3A ,
    0x0000 , 0x6969 , 0x0E7B , 0x00C6 , 0x6E6E , 0xFF3A , 0x0000 , 0x6565 ,
    0xFF3A , 0x0000 , 0x0002 , 0x0E85 , S(6B65), 0x00C6 , 0x7565 , 0xFF3A ,
    0x0000 , 0x0000 , 0x0000 , 0x0E98 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0E9B ,
    0x0000 , 0x6E6E , 0xFF3A , 0x0000 , 0x7272 , 0xFF3A , 0x0000 , 0x7171 ,
    0x0EA1 , 0x00C6 , 0x6961 , 0xFF3A , 0x0000 , 0x0000 , 0x0000 , 0x0EAC ,
    0x0000 , 0x0000 , 0x0000 , 0xFF3A , 0x0000 , 0x6D6E , 0xFF3A , 0xFF3A ,
    0x0000 , 0x7476 , 0x0EB4 , 0x0EBE , 0x00C2 , 0x6565 , 0x0EB7 , 0x0000 ,
    0x7476 , 0xFF3E , 0x0EBB , 0x0000 , 0x6565 , 0xFF3E , 0x0000 , 0x0003 ,
    0xFF39 , S(6A6F), S(0065), 0x0000 , 0x7261 , 0x0ED7 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0EDD , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0EE6 , 0x0000 ,
    0x0005 , 0xFF38 , S(6B72), S(7365), S(0065), 0x0000 , 0x0003 , 0x0EE2 ,
    S(7279), S(0065), 0x00C9 , 0x6E73 , 0xFF37 , 0xFF37 , 0x0000 , 0x6569 ,
    0x0EEA , 0x0EF4 , 0x00CA , 0x6A73 , 0x0EEE , 0x0EF1 , 0x0000 , 0x6565 ,
    0xFF36 , 0x0000 , 0x6868 , 0xFF36 , 0x0000 , 0x7474 , 0x0EF7 , 0x0000 ,
    0x6575 , 0x0EFB , 0x0EFE , 0x0000 , 0x6D6D , 0xFF36 , 0x0000 , 0x7272 ,
    0xFF36 , 0x0000 , 0x6565 , 0x0F04 , 0x0000 , 0x7273 , 0x0F08 , 0x0F10 ,
    0x0000 , 0x0002 , 0x0F0C , S(7A65), 0x00CB , 0x0002 , 0xFF35 , S(6576),
    0x0000 , 0x6969 , 0xFF34 , 0x0000 , 0x6F69 , 0x0F1C , 0x0F21 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0F2D , 0x0000 , 0x0004 , 0xFF33 , S(7272),
    S(6574), 0x0000 , 0x0003 , 0x0F26 , S(7265), S(0072), 0x00CD , 0x6569 ,
    0xFF33 , 0x0F2A , 0x0000 , 0x6D6D , 0xFF33 , 0x0000 , 0x7272 , 0x0F30 ,
    0x00CD , 0x7261 , 0xFF33 , 0x0000 , 0x0000 , 0x0000 , 0x0F44 , 0x0000 ,
    0x0000 , 0x0000 , 0xFF33 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0F47 , 0x0000 , 0x6E6E , 0xFF33 , 0x0000 ,
    0x6569 , 0x0F44 , 0xFF33 , 0x0000 , 0x7072 , 0x0F4F , 0x0F62 , 0x0000 ,
    0x0008 , 0x0F56 , S(7265), S(6361), S(6F69), S(656E), 0x00CE , 0x7673 ,
    0x0F5C , 0xFF32 , 0x0000 , 0x0F5F , 0x0000 , 0x6868 , 0xFF32 , 0x0000 ,
    0x6565 , 0xFF32 , 0x0000 , 0x6961 , 0xFF31 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0F6D , 0x0000 , 0x0F84 , 0x0000 , 0x0002 , 0x0F71 ,
    S(6E61), 0x0000 , 0x6569 , 0x0F75 , 0x0F7F , 0x0000 , 0x7376 , 0x0F79 ,
    0x0F7C , 0x0000 , 0x6868 , 0xFF30 , 0x0000 , 0x6565 , 0xFF30 , 0x0000 ,
    0x0003 , 0xFF2F , S(657A), S(006D), 0x0000 , 0x0005 , 0xFF2E , S(6A67),
    S(6E69), S(0065), 0x0000 , 0x7561 , 0x0FA1 , 0x0000 , 0x0000 , 0x0000 ,
    0x1021 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1071 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x1076 , 0x0000 , 0x0000 , 0x10BA , 0x0000 , 0x0000 ,
    0x114A , 0x0000 , 0x7663 , 0x0FB7 , 0x0FBD , 0x0000 , 0x0000 , 0x0FC0 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0FC5 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0FCB , 0x0FE2 , 0x1013 , 0x0000 , 0x101B , 0x0000 ,
    0x0005 , 0xFF2D , S(6569), S(746E), S(0065), 0x0000 , 0x6969 , 0xFF2C ,
    0x0000 , 0x0003 , 0xFF2B , S(7365), S(0065), 0x0000 , 0x0006 , 0xFF2A ,
    S(6E75), S(6564), S(6973), 0x0000 , 0x7474 , 0x0FCE , 0x0000 , 0x696E ,
    0x0FD2 , 0x0FDC , 0x00D7 , 0x7374 , 0x0FD6 , 0x0FD9 , 0x0000 , 0x6868 ,
    0xFF29 , 0x0000 , 0x6565 , 0xFF29 , 0x0000 , 0x0006 , 0xFF28 , S(7265),
    S(7469), S(7465), 0x0000 , 0x7565 , 0xFF7D , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0FF5 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x1007 , 0x0000 , 0x0000 , 0x0000 , 0x1010 , 0x0000 , 0x6165 , 0x0FF9 ,
    0x0FFD , 0x0083 , 0x6D6E , 0xFF7D , 0xFF7D , 0x0083 , 0x6D73 , 0x1001 ,
    0x1004 , 0x0000 , 0x6969 , 0xFF7D , 0x0000 , 0x6868 , 0xFF7D , 0x0000 ,
    0x0003 , 0x100C , S(7279), S(0065), 0x00D9 , 0x6E73 , 0xFF27 , 0xFF27 ,
    0x0000 , 0x7272 , 0xFF7D , 0x0000 , 0x6575 , 0x1017 , 0x1010 , 0x0000 ,
    0x6D74 , 0xFF7D , 0xFF7D , 0x0000 , 0x0005 , 0xFF26 , S(7261), S(7365),
    S(0069), 0x0000 , 0x746E , 0x102A , 0x0000 , 0x0000 , 0x0000 , 0x102F ,
    0x0000 , 0x106C , 0x0000 , 0x0004 , 0xFF25 , S(6567), S(6573), 0x0000 ,
    0x7664 , 0x1044 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x104A , 0x0000 , 0x0000 , 0x104E , 0x0000 , 0x0000 ,
    0x1060 , 0x0000 , 0x0000 , 0x1067 , 0x0000 , 0x0005 , 0xFF24 , S(726F),
    S(6575), S(0073), 0x0000 , 0x0002 , 0xFF23 , S(7465), 0x0000 , 0x6175 ,
    0x1052 , 0x105B , 0x0000 , 0x0004 , 0x1057 , S(6572), S(6973), 0x00DE ,
    0x0002 , 0xFF22 , S(6574), 0x0000 , 0x0003 , 0xFF21 , S(696E), S(006D),
    0x0000 , 0x0008 , 0xFF20 , S(6E6F), S(6C61), S(7469), S(7465), 0x0000 ,
    0x0003 , 0xFF1F , S(6A6F), S(0065), 0x0000 , 0x0003 , 0xFF1E , S(6972),
    S(0074), 0x0000 , 0x0003 , 0xFF1D , S(7365), S(0065), 0x0000 , 0x7A6C ,
    0x1087 , 0x0000 , 0x0000 , 0x0000 , 0x109D , 0x0000 , 0x10A8 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x10AD , 0x0000 ,
    0x696F , 0x108B , 0x1099 , 0x0000 , 0x0005 , 0x1091 , S(6974), S(616B),
    S(006E), 0x00E4 , 0x6569 , 0xFF1C , 0x1095 , 0x00E4 , 0x6E74 , 0xFF1C ,
    0xFF1C , 0x0000 , 0x0002 , 0xFF1B , S(696E), 0x0000 , 0x0002 , 0x10A1 ,
    S(6A75), 0x00E6 , 0x7476 , 0xFF1A , 0x10A5 , 0x0000 , 0x6565 , 0xFF1A ,
    0x0000 , 0x0003 , 0xFF19 , S(736F), S(0069), 0x0000 , 0x0006 , 0x10B3 ,
    S(6369), S(6F69), S(656E), 0x00E8 , 0x7476 , 0xFF18 , 0x10B7 , 0x0000 ,
    0x6565 , 0xFF18 , 0x0000 , 0x6F65 , 0x10C7 , 0x0000 , 0x0000 , 0x0000 ,
    0x10CD , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x10FB , 0x0000 ,
    0x0005 , 0xFF17 , S(6873), S(7665), S(0065), 0x0000 , 0x746E , 0x10D6 ,
    0x10E5 , 0x0000 , 0x0000 , 0x0000 , 0x10EB , 0x10F1 , 0x0000 , 0x0003 ,
    0x10DB , S(6564), S(0072), 0x00EA , 0x6976 , 0x10DF , 0x10E2 , 0x0000 ,
    0x7474 , 0xFF16 , 0x0000 , 0x6565 , 0xFF16 , 0x0000 , 0x0005 , 0xFF15 ,
    S(6972), S(6574), S(0074), 0x0000 , 0x0005 , 0xFF14 , S(7468), S(6E69),
    S(0065), 0x0000 , 0x0006 , 0x10F7 , S(6873), S(656D), S(6972), 0x00ED ,
    0x0002 , 0xFF13 , S(6574), 0x0000 , 0x7662 , 0x1112 , 0x111A , 0x112D ,
    0x0000 , 0x1132 , 0x113B , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x1140 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x1147 , 0x0000 , 0x0003 , 0x1117 , S(656C), S(006D), 0x00EE ,
    0x6969 , 0xFF12 , 0x0000 , 0x6565 , 0x111D , 0x0000 , 0x6473 , 0x1121 ,
    0x112A , 0x0000 , 0x0003 , 0x1126 , S(7275), S(0065), 0x0000 , 0x6E73 ,
    0xFF11 , 0xFF11 , 0x00F0 , 0x6565 , 0xFF10 , 0x0000 , 0x0004 , 0xFF0F ,
    S(7568), S(7365), 0x0000 , 0x000B , 0xFF0E , S(7365), S(6F69), S(616E),
    S(696C), S(657A), S(006D), 0x0000 , 0x0003 , 0xFF0D , S(6572), S(0073),
    0x0000 , 0x6565 , 0x1143 , 0x00F4 , 0x0002 , 0xFF0B , S(6973), 0x0000 ,
    0x6565 , 0xFF0A , 0x0000 , 0x0005 , 0xFF09 , S(6873), S(6574), S(0074),
    0x0000 , 0x7965 , 0x1167 , 0x0000 , 0x0000 , 0x0000 , 0x1185 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x118A , 0x0000 ,
    0x6E76 , 0x116B , 0x1176 , 0x0000 , 0x656B , 0xFF8A , 0x116F , 0x0000 ,
    0x6165 , 0x1173 , 0xFF8A , 0x0076 , 0x6E6E , 0xFF8A , 0x0000 , 0x0003 ,
    0x117B , S(7265), S(0069), 0x00F8 , 0x7374 , 0x117F , 0x1182 , 0x0000 ,
    0x6868 , 0xFF08 , 0x0000 , 0x6565 , 0xFF08 , 0x0000 , 0x0004 , 0xFF07 ,
    S(646E), S(6172), 0x0000 , 0x0003 , 0xFF06 , S(6574), S(0074), 0x0000 ,
    0x7561 , 0x11A6 , 0x0000 , 0x0000 , 0x0000 , 0x11D6 , 0x0000 , 0x0000 ,
    0x0000 , 0x120E , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x1213 , 0x0000 , 0x0000 , 0x1218 , 0x0000 , 0x7364 ,
    0x11B8 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x11C3 , 0x0000 ,
    0x0000 , 0x0000 , 0x11CF , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x11D2 ,
    0x0000 , 0x0002 , 0x11BC , S(6F69), 0x0000 , 0x6A6E , 0x11C0 , 0xFF05 ,
    0x0000 , 0x6161 , 0xFF05 , 0x0000 , 0x0003 , 0x11C8 , S(6E6F), S(0065),
    0x00FC , 0x7476 , 0xFF04 , 0x11CC , 0x0000 , 0x6565 , 0xFF04 , 0x0000 ,
    0x6565 , 0xFFDB , 0x0000 , 0x0002 , 0xFFDB , S(6568), 0x0000 , 0x7A61 ,
    0x11F2 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x11F8 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x1201 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x1208 , 0x0000 , 0x0005 , 0xFF03 , S(696C), S(6574), S(0074),
    0x0000 , 0x6465 , 0x11FC , 0xFFDB , 0x0000 , 0x0003 , 0xFF02 , S(7365),
    S(0069), 0x0000 , 0x0007 , 0xFF01 , S(6F74), S(6172), S(746E), S(0065),
    0x0000 , 0x0005 , 0xFF00 , S(6C75), S(6174), S(0074), 0x0000 , 0x0003 ,
    0xFEFF , S(6574), S(006D), 0x0000 , 0x0003 , 0xFEFE , S(656A), S(0074),
    0x0000 , 0x7461 , 0x122E , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x1251 , 0x1256 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x126E , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1273 , 0x0000 , 0x6A73 ,
    0x1232 , 0x124E , 0x0000 , 0x7474 , 0x1235 , 0x0103 , 0x7565 , 0x1248 ,
    0x0000 , 0x0000 , 0x0000 , 0xFEFD , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x124B ,
    0x0103 , 0x6E6E , 0xFEFD , 0x0000 , 0x7272 , 0xFEFD , 0x0000 , 0x6868 ,
    0xFEFD , 0x0000 , 0x0003 , 0xFEFC , S(766F), S(0061), 0x0000 , 0x6565 ,
    0x1259 , 0x0000 , 0x746A , 0xFEFD , 0x0000 , 0x0000 , 0x1266 , 0xFEFD ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1269 , 0xFEFD , 0x0000 , 0x6969 ,
    0xFEFD , 0x0000 , 0x0003 , 0xFEFD , S(6968), S(006E), 0x0000 , 0x0003 ,
    0xFEFB , S(6E61), S(0069), 0x0000 , 0x0003 , 0xFEFA , S(6E69), S(0065),
    0x0000 , 0x7961 , 0x1293 , 0x0000 , 0x0000 , 0x0000 , 0x12BF , 0x0000 ,
    0x0000 , 0x12CE , 0x13ED , 0x1444 , 0x1450 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1455 , 0x14B1 , 0x0000 ,
    0x0000 , 0x0000 , 0x14C1 , 0x0000 , 0x736B , 0x129E , 0x12A3 , 0x0000 ,
    0x12A6 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x12B8 , 0x0000 , 0x0004 ,
    0xFEF9 , S(6574), S(6973), 0x0000 , 0x6969 , 0xFEF8 , 0x0000 , 0x0006 ,
    0x12AC , S(736B), S(6F69), S(656E), 0x0109 , 0x7673 , 0x12B2 , 0xFEF7 ,
    0x0000 , 0x12B5 , 0x0000 , 0x6868 , 0xFEF7 , 0x0000 , 0x6565 , 0xFEF7 ,
    0x0000 , 0x6969 , 0x12BB , 0x010A , 0x0002 , 0xFEF6 , S(6574), 0x0000 ,
    0x6C72 , 0x12C3 , 0x12C7 , 0x0000 , 0x0002 , 0xFEF5 , S(6169), 0x0000 ,
    0x6969 , 0x12CA , 0x010C , 0x0002 , 0xFEF4 , S(6574), 0x0000 , 0x7465 ,
    0x12E0 , 0x0000 , 0x0000 , 0x0000 , 0x1300 , 0x0000 , 0x1359 , 0x0000 ,
    0x0000 , 0x0000 , 0x139D , 0x13B5 , 0x13C6 , 0x0000 , 0x0000 , 0x13CC ,
    0x0000 , 0x746E , 0x12E9 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x12F9 ,
    0xFEF0 , 0x0000 , 0x6469 , 0x12ED , 0x12F6 , 0x0000 , 0x0002 , 0x12F1 ,
    S(7465), 0x010D , 0x0003 , 0xFEF2 , S(7365), S(0069), 0x0000 , 0x6D6D ,
    0xFEF1 , 0x0110 , 0x6569 , 0xFEF0 , 0x12FD , 0x0000 , 0x6D6D , 0xFEF0 ,
    0x0000 , 0x7468 , 0x130F , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x132A , 0x1331 , 0x0113 ,
    0x746A , 0x131C , 0x0000 , 0x0000 , 0x0000 , 0x1320 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x1327 , 0x0000 , 0x6165 , 0xFEED , 0xFEED ,
    0x0000 , 0x6969 , 0x1323 , 0x0113 , 0x6D6E , 0xFEED , 0xFEED , 0x0000 ,
    0x6565 , 0xFEED , 0x0000 , 0x0002 , 0x132E , S(696E), 0x0110 , 0x6E6E ,
    0xFEF0 , 0x0000 , 0x7565 , 0x1344 , 0x0000 , 0x0000 , 0x0000 , 0xFEF0 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x1356 , 0x0000 , 0x746A , 0xFEF0 , 0x0000 ,
    0x0000 , 0x0000 , 0xFEF0 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1351 ,
    0xFEF0 , 0x0000 , 0x0003 , 0xFEF0 , S(6968), S(006E), 0x0000 , 0x7272 ,
    0xFEF0 , 0x0000 , 0x756F , 0x1362 , 0x0000 , 0x0000 , 0x138C , 0x0000 ,
    0x0000 , 0x1391 , 0x0111 , 0x7668 , 0x1373 , 0xFEEF , 0x137A , 0x0000 ,
    0x0000 , 0x0000 , 0x1381 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x1389 , 0x0000 , 0x6565 , 0x1376 , 0x0000 , 0x6A74 ,
    0xFEEF , 0xFEEF , 0x0111 , 0x6D6E , 0x137E , 0x137E , 0x0000 , 0x6565 ,
    0xFEEF , 0x0111 , 0x6974 , 0x1385 , 0x137E , 0x0111 , 0x6D6E , 0xFEEF ,
    0xFEEF , 0x0000 , 0x6161 , 0xFEEF , 0x0000 , 0x0003 , 0xFEEE , S(7365),
    S(0065), 0x0111 , 0x6165 , 0x1395 , 0xFEEF , 0x0111 , 0x726D , 0xFEEF ,
    0xFEEF , 0x0000 , 0x0000 , 0x0000 , 0xFEEF , 0x0000 , 0x6871 , 0x13A1 ,
    0x13AC , 0x0113 , 0x6569 , 0x13A5 , 0x13A9 , 0x0113 , 0x0002 , 0xFEED ,
    S(6873), 0x0000 , 0x6E6E , 0xFEED , 0x0000 , 0x0003 , 0x13B1 , S(7265),
    S(0069), 0x0114 , 0x0002 , 0xFEEC , S(6574), 0x0000 , 0x6569 , 0x13B9 ,
    0x13BF , 0x0000 , 0x0005 , 0xFEEB , S(746A), S(7365), S(0069), 0x0000 ,
    0x6173 , 0xFEE9 , 0x13C3 , 0x0000 , 0x6565 , 0xFEE9 , 0x0000 , 0x0005 ,
    0xFEEA , S(7069), S(7265), S(0069), 0x0000 , 0x6572 , 0x13D0 , 0x13E8 ,
    0x0000 , 0x7470 , 0x13D7 , 0x0000 , 0x0000 , 0x13E1 , 0x13E4 , 0x0000 ,
    0x6969 , 0x13DA , 0x0117 , 0x7374 , 0x13DE , 0x13C3 , 0x0000 , 0x6868 ,
    0xFEE9 , 0x0000 , 0x6565 , 0xFEE8 , 0x0119 , 0x0002 , 0xFEE6 , S(7361),
    0x0000 , 0x0003 , 0xFEE5 , S(7365), S(0065), 0x0000 , 0x7367 , 0x13FC ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1401 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x143C , 0x0000 , 0x0003 , 0xFEE4 , S(7275),
    S(0069), 0x0000 , 0x6C6C , 0x1404 , 0x0000 , 0x7465 , 0x1416 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x1430 , 0x0000 , 0x0000 , 0x0000 , 0x1433 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1439 , 0x0000 , 0x746A ,
    0xFEE1 , 0x0000 , 0x0000 , 0x1423 , 0x1426 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x1429 , 0xFEE1 , 0x0000 , 0x6969 , 0xFEE1 , 0x011F , 0x6969 ,
    0xFEE1 , 0x0000 , 0x6868 , 0x142C , 0x011F , 0x0002 , 0xFEE1 , S(6E69),
    0x0000 , 0x6161 , 0xFEE1 , 0x0000 , 0x6969 , 0x1436 , 0x011F , 0x6E6E ,
    0xFEE1 , 0x0000 , 0x6565 , 0xFEE1 , 0x0000 , 0x0003 , 0x1441 , S(6574),
    S(006D), 0x011D , 0x6969 , 0xFEE3 , 0x0000 , 0x0003 , 0x1449 , S(6C65),
    S(006C), 0x011F , 0x6569 , 0xFEE1 , 0x144D , 0x0000 , 0x6D6D , 0xFEE1 ,
    0x0000 , 0x0003 , 0xFEE2 , S(6E65), S(0065), 0x0000 , 0x7561 , 0x146C ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x147D , 0x0000 , 0x0000 , 0x14AB , 0x0000 , 0x6274 , 0x1470 , 0x1476 ,
    0x0000 , 0x0006 , 0xFEE0 , S(6C69), S(7469), S(7465), 0x0000 , 0x0002 ,
    0x147A , S(7375), 0x0121 , 0x6565 , 0xFEDF , 0x0000 , 0x7561 , 0x1494 ,
    0x0000 , 0x0000 , 0x0000 , 0x149E , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x14A1 , 0x0000 , 0x0005 , 0x149A , S(6574),
    S(6A67), S(0069), 0x0122 , 0x0002 , 0xFEDE , S(6574), 0x0000 , 0x7373 ,
    0xFEDD , 0x0000 , 0x0005 , 0x14A7 , S(746B), S(7275), S(0065), 0x0124 ,
    0x6E73 , 0xFEDC , 0xFEDC , 0x0000 , 0x0005 , 0xFEDB , S(6564), S(746E),
    S(0065), 0x0000 , 0x656B , 0x14B5 , 0x14B9 , 0x0000 , 0x0002 , 0xFEDA ,
    S(6964), 0x0000 , 0x0003 , 0x14BE , S(6573), S(0073), 0x0127 , 0x6565 ,
    0xFED9 , 0x0128 , 0x7673 , 0x14C7 , 0x14CF , 0x0000 , 0x14CF , 0x0000 ,
    0x6874 , 0xFED8 , 0x14CB , 0x0000 , 0x0002 , 0xFEE3 , S(6D65), 0x0000 ,
    0x6565 , 0xFED8 , 0x0000 , 0x7561 , 0x14E9 , 0x0000 , 0x0000 , 0x0000 ,
    0x14EF , 0x0000 , 0x0000 , 0x1546 , 0x15C7 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x15D3 , 0x0000 , 0x0000 ,
    0x1606 , 0x0000 , 0x0006 , 0xFED7 , S(6F76), S(696C), S(656E), 0x0000 ,
    0x746B , 0x14FB , 0x1506 , 0x1513 , 0x151E , 0x1524 , 0x152C , 0x0000 ,
    0x1532 , 0x0000 , 0x153E , 0x0000 , 0x0007 , 0x1502 , S(6F6E), S(6F6C),
    S(6A67), S(0069), 0x012A , 0x0002 , 0xFED6 , S(6574), 0x0000 , 0x0004 ,
    0x150B , S(6665), S(6E6F), 0x012B , 0x6569 , 0xFED5 , 0x150F , 0x012B ,
    0x6E74 , 0xFED5 , 0xFED5 , 0x0000 , 0x0008 , 0x151A , S(6570), S(6172),
    S(7574), S(6572), 0x012C , 0x6E73 , 0xFED4 , 0xFED4 , 0x0000 , 0x0006 ,
    0xFED3 , S(6174), S(6974), S(6576), 0x0000 , 0x0002 , 0x1528 , S(6972),
    0x012E , 0x0002 , 0xFED2 , S(6574), 0x0000 , 0x0005 , 0xFED1 , S(6C65),
    S(6E65), S(0065), 0x0000 , 0x656D , 0x1536 , 0x153A , 0x0000 , 0x0002 ,
    0xFED0 , S(6973), 0x0000 , 0x0002 , 0xFECF , S(7465), 0x0000 , 0x0002 ,
    0x1542 , S(766F), 0x0000 , 0x6165 , 0xFECE , 0xFECE , 0x0000 , 0x7561 ,
    0x155D , 0x0000 , 0x0000 , 0x0000 , 0x1562 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x156C , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x15A1 , 0x0000 , 0x0003 , 0xFECD ,
    S(6873), S(0065), 0x0133 , 0x6D6E , 0x1566 , 0x1569 , 0x0133 , 0x6969 ,
    0xFECD , 0x0000 , 0x6565 , 0xFECD , 0x0000 , 0x746A , 0x1579 , 0x0000 ,
    0x0000 , 0xFECD , 0x157C , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1584 ,
    0xFECD , 0x0000 , 0x6161 , 0xFECD , 0x0000 , 0x6569 , 0xFECD , 0x1580 ,
    0x0133 , 0x6D6E , 0xFECD , 0xFECD , 0x0000 , 0x6868 , 0x1587 , 0x0000 ,
    0x7461 , 0xFECD , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x159D , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1569 , 0x0000 , 0x6D6E , 0xFECD ,
    0xFECD , 0x0000 , 0x6168 , 0x15A5 , 0x15B7 , 0x0000 , 0x6A73 , 0x15A9 ,
    0x15B4 , 0x0133 , 0x6961 , 0xFECD , 0x0000 , 0x0000 , 0x0000 , 0xFECD ,
    0x0000 , 0x0000 , 0x0000 , 0xFECD , 0x0000 , 0x6868 , 0xFECD , 0x0000 ,
    0x6565 , 0x15BA , 0x0000 , 0x746A , 0xFECD , 0x0000 , 0x0000 , 0x0000 ,
    0xFECD , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0xFECD , 0x0000 ,
    0x0003 , 0x15CC , S(7574), S(006A), 0x0134 , 0x7476 , 0xFECC , 0x15D0 ,
    0x0000 , 0x6565 , 0xFECC , 0x0000 , 0x7561 , 0x15EA , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x15EF , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x1602 , 0x0000 , 0x0004 , 0xFECB , S(6E6A), S(6D69), 0x0000 ,
    0x6A70 , 0x15F3 , 0x15FD , 0x0000 , 0x6565 , 0x15F6 , 0x0137 , 0x7476 ,
    0xFEC9 , 0x15FA , 0x0000 , 0x6565 , 0xFEC9 , 0x0000 , 0x0003 , 0xFECA ,
    S(6A6F), S(0065), 0x0138 , 0x0002 , 0xFEC8 , S(6574), 0x0000 , 0x6172 ,
    0x160A , 0x160F , 0x0000 , 0x0003 , 0xFEC7 , S(656C), S(0074), 0x0000 ,
    0x6971 , 0x1613 , 0x1618 , 0x0000 , 0x0003 , 0xFEC6 , S(657A), S(006D),
    0x0000 , 0x6969 , 0xFEC5 , 0x0000 , 0x726A , 0x1626 , 0x164F , 0x0000 ,
    0x0000 , 0x1655 , 0x0000 , 0x0000 , 0x0000 , 0x1667 , 0x0000 , 0x7265 ,
    0x1636 , 0x0000 , 0x0000 , 0x0000 , 0x163D , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1640 , 0x1645 , 0x0000 , 0x0007 ,
    0xFEC3 , S(6A73), S(6C65), S(656C), S(0073), 0x013C , 0x6E6E , 0xFEC4 ,
    0x0000 , 0x0004 , 0xFEC2 , S(7265), S(6576), 0x0000 , 0x6161 , 0x1648 ,
    0x013C , 0x7476 , 0xFEC4 , 0x164C , 0x0000 , 0x6565 , 0xFEC4 , 0x013E ,
    0x0005 , 0xFEC1 , S(6172), S(6E69), S(0065), 0x0000 , 0x6969 , 0x1658 ,
    0x0000 , 0x7476 , 0x165C , 0x1660 , 0x0000 , 0x0002 , 0xFEC0 , S(7465),
    0x0000 , 0x0007 , 0xFEBF , S(7265), S(6973), S(6574), S(0074), 0x0000 ,
    0x6465 , 0x166B , 0x1680 , 0x0000 , 0x6868 , 0x166E , 0x0000 , 0x6572 ,
    0x1672 , 0x1675 , 0x0000 , 0x7272 , 0xFEBD , 0x0000 , 0x6169 , 0x1679 ,
    0xFEBD , 0x0143 , 0x7476 , 0xFEBD , 0x167D , 0x0000 , 0x6565 , 0xFEBD ,
    0x0142 , 0x6E6E , 0xFEBE , 0x0000 , 0x7561 , 0x169A , 0x0000 , 0x0000 ,
    0x16C0 , 0x16E8 , 0x0000 , 0x0000 , 0x0000 , 0x1736 , 0x1774 , 0x0000 ,
    0x177B , 0x0000 , 0x0000 , 0x17AF , 0x0000 , 0x0000 , 0x17B4 , 0x0000 ,
    0x0000 , 0x17ED , 0x0000 , 0x7A6A , 0x16AD , 0x16B4 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x16B9 , 0x0000 , 0x6969 , 0x16B0 ,
    0x0144 , 0x6E74 , 0xFEBC , 0xFEBC , 0x0000 , 0x0004 , 0xFEBB , S(6973),
    S(656E), 0x0000 , 0x0007 , 0xFEBA , S(6468), S(6D69), S(7365), S(0069),
    0x0000 , 0x6569 , 0x16C4 , 0x16D8 , 0x0000 , 0x6B73 , 0x16C8 , 0x16CC ,
    0x0000 , 0x0002 , 0xFEB9 , S(7275), 0x0147 , 0x6569 , 0x16D0 , 0x16D4 ,
    0x0147 , 0x0002 , 0xFEB9 , S(6873), 0x0000 , 0x6D6E , 0xFEB9 , 0xFEB9 ,
    0x0000 , 0x7373 , 0x16DB , 0x0000 , 0x6E74 , 0x16DF , 0x16E5 , 0x0000 ,
    0x6969 , 0x16E2 , 0x0147 , 0x6E6E , 0xFEB9 , 0x0000 , 0x6565 , 0xFEB9 ,
    0x0000 , 0x7363 , 0x16FB , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x1701 , 0x1711 , 0x1711 , 0x0000 , 0x1714 ,
    0x0000 , 0x0000 , 0x1725 , 0x0000 , 0x0005 , 0xFEB8 , S(726F), S(7469),
    S(0065), 0x0000 , 0x0005 , 0x1707 , S(656C), S(657A), S(0072), 0x0149 ,
    0x6976 , 0x170B , 0x170E , 0x0000 , 0x7474 , 0xFEB7 , 0x0000 , 0x6565 ,
    0xFEB7 , 0x0000 , 0x6565 , 0xFEAA , 0x0000 , 0x0007 , 0x171B , S(6972),
    S(746D), S(7261), S(0069), 0x0000 , 0x7374 , 0x171F , 0x1722 , 0x0000 ,
    0x6868 , 0xFEB6 , 0x0000 , 0x6565 , 0xFEB6 , 0x0000 , 0x0007 , 0x172C ,
    S(7468), S(7269), S(7365), S(0069), 0x014B , 0x7374 , 0x1730 , 0x1733 ,
    0x0000 , 0x6868 , 0xFEB5 , 0x0000 , 0x6565 , 0xFEB5 , 0x0000 , 0x7464 ,
    0x1749 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1760 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x1767 , 0x0000 ,
    0x176E , 0x0000 , 0x0002 , 0x174D , S(6F65), 0x0000 , 0x736A , 0x1759 ,
    0x0000 , 0x0000 , 0x0000 , 0xFEB4 , 0x0000 , 0x0000 , 0x0000 , 0x0000 ,
    0x175D , 0x0000 , 0x6165 , 0xFEB4 , 0xFEB4 , 0x0000 , 0x6868 , 0xFEB4 ,
    0x004C , 0x6D6E , 0x1764 , 0x1764 , 0x0000 , 0x6565 , 0xFFB4 , 0x0000 ,
    0x0002 , 0x176B , S(7375), 0x014D , 0x6565 , 0xFEB3 , 0x0000 , 0x0005 ,
    0xFEB2 , S(6D61), S(6E69), S(0065), 0x0000 , 0x0002 , 0x1778 , S(6E65),
    0x004C , 0x6565 , 0xFEB1 , 0x0000 , 0x6F65 , 0x1788 , 0x0000 , 0x0000 ,
    0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x17A8 , 0x0000 , 0x0000 , 0x17AB ,
    0x0000 , 0x726A , 0x1793 , 0x0000 , 0x0000 , 0x0000 , 0x179A , 0x0000 ,
    0x0000 , 0x0000 , 0x17A1 , 0x0000 , 0x656E , 0xFEAF , 0x1797 , 0x0000 ,
    0x6565 , 0xFEAF , 0x0151 , 0x6974 , 0x179E , 0x1797 , 0x0000 , 0x6E6E ,
    0xFEAF , 0x0000 , 0x6565 , 0x17A4 , 0x0150 , 0x6E73 , 0xFEB0 , 0xFEB0 ,
    0x0000 , 0x6161 , 0xFEB7 , 0x0000 , 0x0002 , 0xFEAE , S(6172), 0x0000 ,
    0x0004 , 0xFEAD , S(656E), S(6573), 0x0000 , 0x6961 , 0x17BF , 0x0000 ,
    0x0000 , 0x0000 , 0x17DD , 0x0000 , 0x0000 , 0x0000 , 0x17E0 , 0x0154 ,
    0x766D , 0x17CB , 0x17CB , 0x0000 , 0x0000 , 0x0000 , 0x17CB , 0x17CE ,
    0x0000 , 0xFEAC , 0x17DA , 0x0000 , 0x6565 , 0xFEAC , 0x0154 , 0x6569 ,
    0x17D2 , 0x17D6 , 0x0000 , 0x0002 , 0xFEAC , S(6873), 0x0000 , 0x6D6E ,
    0xFEAC , 0xFEAC , 0x0000 , 0x6161 , 0xFEAC , 0x0000 , 0x7474 , 0xFEAC ,
    0x0000 , 0x7373 , 0x17E3 , 0x0000 , 0x6E74 , 0x17E7 , 0x17CB , 0x0000 ,
    0x6969 , 0x17EA , 0x0154 , 0x6E6E , 0xFEAC , 0x0000 , 0x6E6C , 0x17F2 ,
    0x1711 , 0x1711 , 0x0000 , 0x0004 , 0xFEAB , S(6E6C), S(7465), 0x0000 ,
    0x0002 , 0x17FB , S(656A), 0x0157 , 0x7673 , 0x1801 , 0xFEA9 , 0x0000 ,
    0x1804 , 0x0000 , 0x6868 , 0xFEA9 , 0x0000 , 0x6565 , 0xFEA9 , 0x0000 ,
    0x0007 , 0xFEA8 , S(6465), S(6568), S(656E), S(0073)
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
                    int ret = slice_from_s(z, 6, s_18);
                    if (ret < 0) return ret;
                }
                break;
            case 19:
                {
                    int ret = slice_from_s(z, 8, s_19);
                    if (ret < 0) return ret;
                }
                break;
            case 20:
                {
                    int ret = slice_from_s(z, 6, s_20);
                    if (ret < 0) return ret;
                }
                break;
            case 21:
                {
                    int ret = slice_from_s(z, 5, s_21);
                    if (ret < 0) return ret;
                }
                break;
            case 22:
                {
                    int ret = slice_from_s(z, 8, s_22);
                    if (ret < 0) return ret;
                }
                break;
            case 23:
                {
                    int ret = slice_from_s(z, 6, s_23);
                    if (ret < 0) return ret;
                }
                break;
            case 24:
                {
                    int ret = slice_from_s(z, 8, s_24);
                    if (ret < 0) return ret;
                }
                break;
            case 25:
                {
                    int ret = slice_from_s(z, 9, s_25);
                    if (ret < 0) return ret;
                }
                break;
            case 26:
                {
                    int ret = slice_from_s(z, 6, s_26);
                    if (ret < 0) return ret;
                }
                break;
            case 27:
                {
                    int ret = slice_from_s(z, 5, s_27);
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
                    int ret = slice_from_s(z, 4, s_29);
                    if (ret < 0) return ret;
                }
                break;
            case 30:
                {
                    int ret = slice_from_s(z, 6, s_30);
                    if (ret < 0) return ret;
                }
                break;
            case 31:
                {
                    int ret = slice_from_s(z, 9, s_31);
                    if (ret < 0) return ret;
                }
                break;
            case 32:
                {
                    int ret = slice_from_s(z, 6, s_32);
                    if (ret < 0) return ret;
                }
                break;
            case 33:
                {
                    int ret = slice_from_s(z, 3, s_33);
                    if (ret < 0) return ret;
                }
                break;
            case 34:
                {
                    int ret = slice_from_s(z, 5, s_34);
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
                    int ret = slice_from_s(z, 4, s_36);
                    if (ret < 0) return ret;
                }
                break;
            case 37:
                {
                    int ret = slice_from_s(z, 3, s_37);
                    if (ret < 0) return ret;
                }
                break;
            case 38:
                {
                    int ret = slice_from_s(z, 6, s_38);
                    if (ret < 0) return ret;
                }
                break;
            case 39:
                {
                    int ret = slice_from_s(z, 7, s_39);
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
                    int ret = slice_from_s(z, 6, s_41);
                    if (ret < 0) return ret;
                }
                break;
            case 42:
                {
                    int ret = slice_from_s(z, 8, s_1);
                    if (ret < 0) return ret;
                }
                break;
            case 43:
                {
                    int ret = slice_from_s(z, 4, s_42);
                    if (ret < 0) return ret;
                }
                break;
            case 44:
                {
                    int ret = slice_from_s(z, 6, s_43);
                    if (ret < 0) return ret;
                }
                break;
            case 45:
                {
                    int ret = slice_from_s(z, 4, s_44);
                    if (ret < 0) return ret;
                }
                break;
            case 46:
                {
                    int ret = slice_from_s(z, 5, s_45);
                    if (ret < 0) return ret;
                }
                break;
            case 47:
                {
                    int ret = slice_from_s(z, 9, s_46);
                    if (ret < 0) return ret;
                }
                break;
            case 48:
                {
                    int ret = slice_from_s(z, 7, s_47);
                    if (ret < 0) return ret;
                }
                break;
            case 49:
                {
                    int ret = slice_from_s(z, 5, s_48);
                    if (ret < 0) return ret;
                }
                break;
            case 50:
                {
                    int ret = slice_from_s(z, 6, s_49);
                    if (ret < 0) return ret;
                }
                break;
            case 51:
                {
                    int ret = slice_from_s(z, 4, s_50);
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
                    int ret = slice_from_s(z, 7, s_52);
                    if (ret < 0) return ret;
                }
                break;
            case 54:
                {
                    int ret = slice_from_s(z, 3, s_53);
                    if (ret < 0) return ret;
                }
                break;
            case 55:
                {
                    int ret = slice_from_s(z, 8, s_54);
                    if (ret < 0) return ret;
                }
                break;
            case 56:
                {
                    int ret = slice_from_s(z, 9, s_55);
                    if (ret < 0) return ret;
                }
                break;
            case 57:
                {
                    int ret = slice_from_s(z, 4, s_56);
                    if (ret < 0) return ret;
                }
                break;
            case 58:
                {
                    int ret = slice_from_s(z, 4, s_57);
                    if (ret < 0) return ret;
                }
                break;
            case 59:
                {
                    int ret = slice_from_s(z, 8, s_58);
                    if (ret < 0) return ret;
                }
                break;
            case 60:
                {
                    int ret = slice_from_s(z, 3, s_59);
                    if (ret < 0) return ret;
                }
                break;
            case 61:
                {
                    int ret = slice_from_s(z, 3, s_60);
                    if (ret < 0) return ret;
                }
                break;
            case 62:
                {
                    int ret = slice_from_s(z, 8, s_61);
                    if (ret < 0) return ret;
                }
                break;
            case 63:
                {
                    int ret = slice_from_s(z, 10, s_62);
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
                    int ret = slice_from_s(z, 4, s_64);
                    if (ret < 0) return ret;
                }
                break;
            case 66:
                {
                    int ret = slice_from_s(z, 6, s_65);
                    if (ret < 0) return ret;
                }
                break;
            case 67:
                {
                    int ret = slice_from_s(z, 10, s_0);
                    if (ret < 0) return ret;
                }
                break;
            case 68:
                {
                    int ret = slice_from_s(z, 7, s_66);
                    if (ret < 0) return ret;
                }
                break;
            case 69:
                {
                    int ret = slice_from_s(z, 7, s_67);
                    if (ret < 0) return ret;
                }
                break;
            case 70:
                {
                    int ret = slice_from_s(z, 3, s_68);
                    if (ret < 0) return ret;
                }
                break;
            case 71:
                {
                    int ret = slice_from_s(z, 8, s_69);
                    if (ret < 0) return ret;
                }
                break;
            case 72:
                {
                    int ret = slice_from_s(z, 5, s_70);
                    if (ret < 0) return ret;
                }
                break;
            case 73:
                {
                    int ret = slice_from_s(z, 5, s_71);
                    if (ret < 0) return ret;
                }
                break;
            case 74:
                {
                    int ret = slice_from_s(z, 7, s_72);
                    if (ret < 0) return ret;
                }
                break;
            case 75:
                {
                    int ret = slice_from_s(z, 6, s_73);
                    if (ret < 0) return ret;
                }
                break;
            case 76:
                {
                    int ret = slice_from_s(z, 4, s_74);
                    if (ret < 0) return ret;
                }
                break;
            case 77:
                {
                    int ret = slice_from_s(z, 3, s_75);
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
                    int ret = slice_from_s(z, 9, s_77);
                    if (ret < 0) return ret;
                }
                break;
            case 80:
                {
                    int ret = slice_from_s(z, 3, s_78);
                    if (ret < 0) return ret;
                }
                break;
            case 81:
                {
                    int ret = slice_from_s(z, 6, s_79);
                    if (ret < 0) return ret;
                }
                break;
            case 82:
                {
                    int ret = slice_from_s(z, 4, s_80);
                    if (ret < 0) return ret;
                }
                break;
            case 83:
                {
                    int ret = slice_from_s(z, 5, s_81);
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
                    int ret = slice_from_s(z, 9, s_83);
                    if (ret < 0) return ret;
                }
                break;
            case 86:
                {
                    int ret = slice_from_s(z, 6, s_84);
                    if (ret < 0) return ret;
                }
                break;
            case 87:
                {
                    int ret = slice_from_s(z, 7, s_85);
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
                    int ret = slice_from_s(z, 4, s_87);
                    if (ret < 0) return ret;
                }
                break;
            case 90:
                {
                    int ret = slice_from_s(z, 7, s_88);
                    if (ret < 0) return ret;
                }
                break;
            case 91:
                {
                    int ret = slice_from_s(z, 10, s_89);
                    if (ret < 0) return ret;
                }
                break;
            case 92:
                {
                    int ret = slice_from_s(z, 6, s_90);
                    if (ret < 0) return ret;
                }
                break;
            case 93:
                {
                    int ret = slice_from_s(z, 7, s_91);
                    if (ret < 0) return ret;
                }
                break;
            case 94:
                {
                    int ret = slice_from_s(z, 4, s_92);
                    if (ret < 0) return ret;
                }
                break;
            case 95:
                {
                    int ret = slice_from_s(z, 6, s_93);
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
                    int ret = slice_from_s(z, 5, s_95);
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
                    int ret = slice_from_s(z, 3, s_97);
                    if (ret < 0) return ret;
                }
                break;
            case 100:
                {
                    int ret = slice_from_s(z, 7, s_98);
                    if (ret < 0) return ret;
                }
                break;
            case 101:
                {
                    int ret = slice_from_s(z, 5, s_99);
                    if (ret < 0) return ret;
                }
                break;
            case 102:
                {
                    int ret = slice_from_s(z, 6, s_100);
                    if (ret < 0) return ret;
                }
                break;
            case 103:
                {
                    int ret = slice_from_s(z, 10, s_101);
                    if (ret < 0) return ret;
                }
                break;
            case 104:
                {
                    int ret = slice_from_s(z, 3, s_102);
                    if (ret < 0) return ret;
                }
                break;
            case 105:
                {
                    int ret = slice_from_s(z, 7, s_103);
                    if (ret < 0) return ret;
                }
                break;
            case 106:
                {
                    int ret = slice_from_s(z, 7, s_104);
                    if (ret < 0) return ret;
                }
                break;
            case 107:
                {
                    int ret = slice_from_s(z, 3, s_105);
                    if (ret < 0) return ret;
                }
                break;
            case 108:
                {
                    int ret = slice_from_s(z, 3, s_106);
                    if (ret < 0) return ret;
                }
                break;
            case 109:
                {
                    int ret = slice_from_s(z, 8, s_107);
                    if (ret < 0) return ret;
                }
                break;
            case 110:
                {
                    int ret = slice_from_s(z, 7, s_108);
                    if (ret < 0) return ret;
                }
                break;
            case 111:
                {
                    int ret = slice_from_s(z, 9, s_109);
                    if (ret < 0) return ret;
                }
                break;
            case 112:
                {
                    int ret = slice_from_s(z, 9, s_110);
                    if (ret < 0) return ret;
                }
                break;
            case 113:
                {
                    int ret = slice_from_s(z, 10, s_111);
                    if (ret < 0) return ret;
                }
                break;
            case 114:
                {
                    int ret = slice_from_s(z, 10, s_112);
                    if (ret < 0) return ret;
                }
                break;
            case 115:
                {
                    int ret = slice_from_s(z, 7, s_113);
                    if (ret < 0) return ret;
                }
                break;
            case 116:
                {
                    int ret = slice_from_s(z, 8, s_114);
                    if (ret < 0) return ret;
                }
                break;
            case 117:
                {
                    int ret = slice_from_s(z, 6, s_115);
                    if (ret < 0) return ret;
                }
                break;
            case 118:
                {
                    int ret = slice_from_s(z, 2, s_116);
                    if (ret < 0) return ret;
                }
                break;
            case 119:
                {
                    int ret = slice_from_s(z, 3, s_116);
                    if (ret < 0) return ret;
                }
                break;
            case 120:
                {
                    int ret = slice_from_s(z, 5, s_117);
                    if (ret < 0) return ret;
                }
                break;
            case 121:
                {
                    int ret = slice_from_s(z, 9, s_118);
                    if (ret < 0) return ret;
                }
                break;
            case 122:
                {
                    int ret = slice_from_s(z, 7, s_119);
                    if (ret < 0) return ret;
                }
                break;
            case 123:
                {
                    int ret = slice_from_s(z, 8, s_120);
                    if (ret < 0) return ret;
                }
                break;
            case 124:
                {
                    int ret = slice_from_s(z, 9, s_121);
                    if (ret < 0) return ret;
                }
                break;
            case 125:
                {
                    int ret = slice_from_s(z, 8, s_122);
                    if (ret < 0) return ret;
                }
                break;
            case 126:
                {
                    int ret = slice_from_s(z, 8, s_123);
                    if (ret < 0) return ret;
                }
                break;
            case 127:
                {
                    int ret = slice_from_s(z, 3, s_124);
                    if (ret < 0) return ret;
                }
                break;
            case 128:
                {
                    int ret = slice_from_s(z, 8, s_125);
                    if (ret < 0) return ret;
                }
                break;
            case 129:
                {
                    int ret = slice_from_s(z, 6, s_126);
                    if (ret < 0) return ret;
                }
                break;
            case 130:
                {
                    int ret = slice_from_s(z, 6, s_127);
                    if (ret < 0) return ret;
                }
                break;
            case 131:
                {
                    int ret = slice_from_s(z, 5, s_128);
                    if (ret < 0) return ret;
                }
                break;
            case 132:
                {
                    int ret = slice_from_s(z, 4, s_129);
                    if (ret < 0) return ret;
                }
                break;
            case 133:
                {
                    int ret = slice_from_s(z, 6, s_130);
                    if (ret < 0) return ret;
                }
                break;
            case 134:
                {
                    int ret = slice_from_s(z, 6, s_131);
                    if (ret < 0) return ret;
                }
                break;
            case 135:
                {
                    int ret = slice_from_s(z, 6, s_132);
                    if (ret < 0) return ret;
                }
                break;
            case 136:
                {
                    int ret = slice_from_s(z, 6, s_133);
                    if (ret < 0) return ret;
                }
                break;
            case 137:
                {
                    int ret = slice_from_s(z, 7, s_134);
                    if (ret < 0) return ret;
                }
                break;
            case 138:
                {
                    int ret = slice_from_s(z, 9, s_135);
                    if (ret < 0) return ret;
                }
                break;
            case 139:
                {
                    int ret = slice_from_s(z, 5, s_136);
                    if (ret < 0) return ret;
                }
                break;
            case 140:
                {
                    int ret = slice_from_s(z, 9, s_136);
                    if (ret < 0) return ret;
                }
                break;
            case 141:
                {
                    int ret = slice_from_s(z, 9, s_137);
                    if (ret < 0) return ret;
                }
                break;
            case 142:
                {
                    int ret = slice_from_s(z, 12, s_138);
                    if (ret < 0) return ret;
                }
                break;
            case 143:
                {
                    int ret = slice_from_s(z, 9, s_139);
                    if (ret < 0) return ret;
                }
                break;
            case 144:
                {
                    int ret = slice_from_s(z, 7, s_140);
                    if (ret < 0) return ret;
                }
                break;
            case 145:
                {
                    int ret = slice_from_s(z, 7, s_141);
                    if (ret < 0) return ret;
                }
                break;
            case 146:
                {
                    int ret = slice_from_s(z, 5, s_142);
                    if (ret < 0) return ret;
                }
                break;
            case 147:
                {
                    int ret = slice_from_s(z, 5, s_143);
                    if (ret < 0) return ret;
                }
                break;
            case 148:
                {
                    int ret = slice_from_s(z, 5, s_144);
                    if (ret < 0) return ret;
                }
                break;
            case 149:
                {
                    int ret = slice_from_s(z, 6, s_145);
                    if (ret < 0) return ret;
                }
                break;
            case 150:
                {
                    int ret = slice_from_s(z, 3, s_146);
                    if (ret < 0) return ret;
                }
                break;
            case 151:
                {
                    int ret = slice_from_s(z, 9, s_147);
                    if (ret < 0) return ret;
                }
                break;
            case 152:
                {
                    int ret = slice_from_s(z, 5, s_148);
                    if (ret < 0) return ret;
                }
                break;
            case 153:
                {
                    int ret = slice_from_s(z, 5, s_149);
                    if (ret < 0) return ret;
                }
                break;
            case 154:
                {
                    int ret = slice_from_s(z, 6, s_150);
                    if (ret < 0) return ret;
                }
                break;
            case 155:
                {
                    int ret = slice_from_s(z, 5, s_151);
                    if (ret < 0) return ret;
                }
                break;
            case 156:
                {
                    int ret = slice_from_s(z, 6, s_152);
                    if (ret < 0) return ret;
                }
                break;
            case 157:
                {
                    int ret = slice_from_s(z, 7, s_153);
                    if (ret < 0) return ret;
                }
                break;
            case 158:
                {
                    int ret = slice_from_s(z, 7, s_154);
                    if (ret < 0) return ret;
                }
                break;
            case 159:
                {
                    int ret = slice_from_s(z, 6, s_155);
                    if (ret < 0) return ret;
                }
                break;
            case 160:
                {
                    int ret = slice_from_s(z, 3, s_156);
                    if (ret < 0) return ret;
                }
                break;
            case 161:
                {
                    int ret = slice_from_s(z, 4, s_157);
                    if (ret < 0) return ret;
                }
                break;
            case 162:
                {
                    int ret = slice_from_s(z, 7, s_158);
                    if (ret < 0) return ret;
                }
                break;
            case 163:
                {
                    int ret = slice_from_s(z, 3, s_159);
                    if (ret < 0) return ret;
                }
                break;
            case 164:
                {
                    int ret = slice_from_s(z, 7, s_160);
                    if (ret < 0) return ret;
                }
                break;
            case 165:
                {
                    int ret = slice_from_s(z, 5, s_161);
                    if (ret < 0) return ret;
                }
                break;
            case 166:
                {
                    int ret = slice_from_s(z, 8, s_161);
                    if (ret < 0) return ret;
                }
                break;
            case 167:
                {
                    int ret = slice_from_s(z, 6, s_162);
                    if (ret < 0) return ret;
                }
                break;
            case 168:
                {
                    int ret = slice_from_s(z, 8, s_163);
                    if (ret < 0) return ret;
                }
                break;
            case 169:
                {
                    int ret = slice_from_s(z, 6, s_164);
                    if (ret < 0) return ret;
                }
                break;
            case 170:
                {
                    int ret = slice_from_s(z, 5, s_165);
                    if (ret < 0) return ret;
                }
                break;
            case 171:
                {
                    int ret = slice_from_s(z, 4, s_166);
                    if (ret < 0) return ret;
                }
                break;
            case 172:
                {
                    int ret = slice_from_s(z, 5, s_167);
                    if (ret < 0) return ret;
                }
                break;
            case 173:
                {
                    int ret = slice_from_s(z, 6, s_168);
                    if (ret < 0) return ret;
                }
                break;
            case 174:
                {
                    int ret = slice_from_s(z, 6, s_169);
                    if (ret < 0) return ret;
                }
                break;
            case 175:
                {
                    int ret = slice_from_s(z, 6, s_170);
                    if (ret < 0) return ret;
                }
                break;
            case 176:
                {
                    int ret = slice_from_s(z, 8, s_171);
                    if (ret < 0) return ret;
                }
                break;
            case 177:
                {
                    int ret = slice_from_s(z, 6, s_172);
                    if (ret < 0) return ret;
                }
                break;
            case 178:
                {
                    int ret = slice_from_s(z, 4, s_173);
                    if (ret < 0) return ret;
                }
                break;
            case 179:
                {
                    int ret = slice_from_s(z, 4, s_174);
                    if (ret < 0) return ret;
                }
                break;
            case 180:
                {
                    int ret = slice_from_s(z, 6, s_175);
                    if (ret < 0) return ret;
                }
                break;
            case 181:
                {
                    int ret = slice_from_s(z, 6, s_176);
                    if (ret < 0) return ret;
                }
                break;
            case 182:
                {
                    int ret = slice_from_s(z, 8, s_177);
                    if (ret < 0) return ret;
                }
                break;
            case 183:
                {
                    int ret = slice_from_s(z, 3, s_178);
                    if (ret < 0) return ret;
                }
                break;
            case 184:
                {
                    int ret = slice_from_s(z, 6, s_179);
                    if (ret < 0) return ret;
                }
                break;
            case 185:
                {
                    int ret = slice_from_s(z, 4, s_180);
                    if (ret < 0) return ret;
                }
                break;
            case 186:
                {
                    int ret = slice_from_s(z, 6, s_181);
                    if (ret < 0) return ret;
                }
                break;
            case 187:
                {
                    int ret = slice_from_s(z, 4, s_182);
                    if (ret < 0) return ret;
                }
                break;
            case 188:
                {
                    int ret = slice_from_s(z, 5, s_183);
                    if (ret < 0) return ret;
                }
                break;
            case 189:
                {
                    int ret = slice_from_s(z, 3, s_184);
                    if (ret < 0) return ret;
                }
                break;
            case 190:
                {
                    int ret = slice_from_s(z, 7, s_185);
                    if (ret < 0) return ret;
                }
                break;
            case 191:
                {
                    int ret = slice_from_s(z, 6, s_186);
                    if (ret < 0) return ret;
                }
                break;
            case 192:
                {
                    int ret = slice_from_s(z, 6, s_187);
                    if (ret < 0) return ret;
                }
                break;
            case 193:
                {
                    int ret = slice_from_s(z, 3, s_188);
                    if (ret < 0) return ret;
                }
                break;
            case 194:
                {
                    int ret = slice_from_s(z, 3, s_189);
                    if (ret < 0) return ret;
                }
                break;
            case 195:
                {
                    int ret = slice_from_s(z, 5, s_189);
                    if (ret < 0) return ret;
                }
                break;
            case 196:
                {
                    int ret = slice_from_s(z, 6, s_190);
                    if (ret < 0) return ret;
                }
                break;
            case 197:
                {
                    int ret = slice_from_s(z, 7, s_191);
                    if (ret < 0) return ret;
                }
                break;
            case 198:
                {
                    int ret = slice_from_s(z, 7, s_192);
                    if (ret < 0) return ret;
                }
                break;
            case 199:
                {
                    int ret = slice_from_s(z, 4, s_193);
                    if (ret < 0) return ret;
                }
                break;
            case 200:
                {
                    int ret = slice_from_s(z, 7, s_194);
                    if (ret < 0) return ret;
                }
                break;
            case 201:
                {
                    int ret = slice_from_s(z, 4, s_195);
                    if (ret < 0) return ret;
                }
                break;
            case 202:
                {
                    int ret = slice_from_s(z, 5, s_196);
                    if (ret < 0) return ret;
                }
                break;
            case 203:
                {
                    int ret = slice_from_s(z, 5, s_197);
                    if (ret < 0) return ret;
                }
                break;
            case 204:
                {
                    int ret = slice_from_s(z, 5, s_198);
                    if (ret < 0) return ret;
                }
                break;
            case 205:
                {
                    int ret = slice_from_s(z, 5, s_199);
                    if (ret < 0) return ret;
                }
                break;
            case 206:
                {
                    int ret = slice_from_s(z, 7, s_200);
                    if (ret < 0) return ret;
                }
                break;
            case 207:
                {
                    int ret = slice_from_s(z, 3, s_201);
                    if (ret < 0) return ret;
                }
                break;
            case 208:
                {
                    int ret = slice_from_s(z, 3, s_202);
                    if (ret < 0) return ret;
                }
                break;
            case 209:
                {
                    int ret = slice_from_s(z, 8, s_202);
                    if (ret < 0) return ret;
                }
                break;
            case 210:
                {
                    int ret = slice_from_s(z, 7, s_203);
                    if (ret < 0) return ret;
                }
                break;
            case 211:
                {
                    int ret = slice_from_s(z, 7, s_204);
                    if (ret < 0) return ret;
                }
                break;
            case 212:
                {
                    int ret = slice_from_s(z, 4, s_205);
                    if (ret < 0) return ret;
                }
                break;
            case 213:
                {
                    int ret = slice_from_s(z, 5, s_206);
                    if (ret < 0) return ret;
                }
                break;
            case 214:
                {
                    int ret = slice_from_s(z, 9, s_207);
                    if (ret < 0) return ret;
                }
                break;
            case 215:
                {
                    int ret = slice_from_s(z, 5, s_208);
                    if (ret < 0) return ret;
                }
                break;
            case 216:
                {
                    int ret = slice_from_s(z, 11, s_209);
                    if (ret < 0) return ret;
                }
                break;
            case 217:
                {
                    int ret = slice_from_s(z, 5, s_210);
                    if (ret < 0) return ret;
                }
                break;
            case 218:
                {
                    int ret = slice_from_s(z, 8, s_211);
                    if (ret < 0) return ret;
                }
                break;
            case 219:
                {
                    int ret = slice_from_s(z, 6, s_212);
                    if (ret < 0) return ret;
                }
                break;
            case 220:
                {
                    int ret = slice_from_s(z, 9, s_213);
                    if (ret < 0) return ret;
                }
                break;
            case 221:
                {
                    int ret = slice_from_s(z, 6, s_214);
                    if (ret < 0) return ret;
                }
                break;
            case 222:
                {
                    int ret = slice_from_s(z, 9, s_215);
                    if (ret < 0) return ret;
                }
                break;
            case 223:
                {
                    int ret = slice_from_s(z, 6, s_216);
                    if (ret < 0) return ret;
                }
                break;
            case 224:
                {
                    int ret = slice_from_s(z, 12, s_217);
                    if (ret < 0) return ret;
                }
                break;
            case 225:
                {
                    int ret = slice_from_s(z, 5, s_218);
                    if (ret < 0) return ret;
                }
                break;
            case 226:
                {
                    int ret = slice_from_s(z, 6, s_219);
                    if (ret < 0) return ret;
                }
                break;
            case 227:
                {
                    int ret = slice_from_s(z, 4, s_220);
                    if (ret < 0) return ret;
                }
                break;
            case 228:
                {
                    int ret = slice_from_s(z, 9, s_221);
                    if (ret < 0) return ret;
                }
                break;
            case 229:
                {
                    int ret = slice_from_s(z, 6, s_222);
                    if (ret < 0) return ret;
                }
                break;
            case 230:
                {
                    int ret = slice_from_s(z, 6, s_223);
                    if (ret < 0) return ret;
                }
                break;
            case 231:
                {
                    int ret = slice_from_s(z, 6, s_224);
                    if (ret < 0) return ret;
                }
                break;
            case 232:
                {
                    int ret = slice_from_s(z, 6, s_225);
                    if (ret < 0) return ret;
                }
                break;
            case 233:
                {
                    int ret = slice_from_s(z, 7, s_226);
                    if (ret < 0) return ret;
                }
                break;
            case 234:
                {
                    int ret = slice_from_s(z, 5, s_227);
                    if (ret < 0) return ret;
                }
                break;
            case 235:
                {
                    int ret = slice_from_s(z, 9, s_228);
                    if (ret < 0) return ret;
                }
                break;
            case 236:
                {
                    int ret = slice_from_s(z, 8, s_229);
                    if (ret < 0) return ret;
                }
                break;
            case 237:
                {
                    int ret = slice_from_s(z, 10, s_230);
                    if (ret < 0) return ret;
                }
                break;
            case 238:
                {
                    int ret = slice_from_s(z, 7, s_231);
                    if (ret < 0) return ret;
                }
                break;
            case 239:
                {
                    int ret = slice_from_s(z, 7, s_232);
                    if (ret < 0) return ret;
                }
                break;
            case 240:
                {
                    int ret = slice_from_s(z, 6, s_233);
                    if (ret < 0) return ret;
                }
                break;
            case 241:
                {
                    int ret = slice_from_s(z, 8, s_234);
                    if (ret < 0) return ret;
                }
                break;
            case 242:
                {
                    int ret = slice_from_s(z, 14, s_235);
                    if (ret < 0) return ret;
                }
                break;
            case 243:
                {
                    int ret = slice_from_s(z, 7, s_236);
                    if (ret < 0) return ret;
                }
                break;
            case 244:
                {
                    int ret = slice_from_s(z, 4, s_237);
                    if (ret < 0) return ret;
                }
                break;
            case 245:
                {
                    int ret = slice_from_s(z, 7, s_237);
                    if (ret < 0) return ret;
                }
                break;
            case 246:
                {
                    int ret = slice_from_s(z, 4, s_238);
                    if (ret < 0) return ret;
                }
                break;
            case 247:
                {
                    int ret = slice_from_s(z, 7, s_239);
                    if (ret < 0) return ret;
                }
                break;
            case 248:
                {
                    int ret = slice_from_s(z, 6, s_240);
                    if (ret < 0) return ret;
                }
                break;
            case 249:
                {
                    int ret = slice_from_s(z, 4, s_241);
                    if (ret < 0) return ret;
                }
                break;
            case 250:
                {
                    int ret = slice_from_s(z, 5, s_242);
                    if (ret < 0) return ret;
                }
                break;
            case 251:
                {
                    int ret = slice_from_s(z, 5, s_243);
                    if (ret < 0) return ret;
                }
                break;
            case 252:
                {
                    int ret = slice_from_s(z, 3, s_244);
                    if (ret < 0) return ret;
                }
                break;
            case 253:
                {
                    int ret = slice_from_s(z, 8, s_245);
                    if (ret < 0) return ret;
                }
                break;
            case 254:
                {
                    int ret = slice_from_s(z, 7, s_246);
                    if (ret < 0) return ret;
                }
                break;
            case 255:
                {
                    int ret = slice_from_s(z, 9, s_247);
                    if (ret < 0) return ret;
                }
                break;
            case 256:
                {
                    int ret = slice_from_s(z, 8, s_248);
                    if (ret < 0) return ret;
                }
                break;
            case 257:
                {
                    int ret = slice_from_s(z, 4, s_249);
                    if (ret < 0) return ret;
                }
                break;
            case 258:
                {
                    int ret = slice_from_s(z, 5, s_250);
                    if (ret < 0) return ret;
                }
                break;
            case 259:
                {
                    int ret = slice_from_s(z, 3, s_251);
                    if (ret < 0) return ret;
                }
                break;
            case 260:
                {
                    int ret = slice_from_s(z, 5, s_252);
                    if (ret < 0) return ret;
                }
                break;
            case 261:
                {
                    int ret = slice_from_s(z, 6, s_253);
                    if (ret < 0) return ret;
                }
                break;
            case 262:
                {
                    int ret = slice_from_s(z, 5, s_254);
                    if (ret < 0) return ret;
                }
                break;
            case 263:
                {
                    int ret = slice_from_s(z, 7, s_255);
                    if (ret < 0) return ret;
                }
                break;
            case 264:
                {
                    int ret = slice_from_s(z, 4, s_256);
                    if (ret < 0) return ret;
                }
                break;
            case 265:
                {
                    int ret = slice_from_s(z, 6, s_257);
                    if (ret < 0) return ret;
                }
                break;
            case 266:
                {
                    int ret = slice_from_s(z, 4, s_258);
                    if (ret < 0) return ret;
                }
                break;
            case 267:
                {
                    int ret = slice_from_s(z, 3, s_259);
                    if (ret < 0) return ret;
                }
                break;
            case 268:
                {
                    int ret = slice_from_s(z, 4, s_260);
                    if (ret < 0) return ret;
                }
                break;
            case 269:
                {
                    int ret = slice_from_s(z, 7, s_261);
                    if (ret < 0) return ret;
                }
                break;
            case 270:
                {
                    int ret = slice_from_s(z, 10, s_261);
                    if (ret < 0) return ret;
                }
                break;
            case 271:
                {
                    int ret = slice_from_s(z, 6, s_262);
                    if (ret < 0) return ret;
                }
                break;
            case 272:
                {
                    int ret = slice_from_s(z, 4, s_263);
                    if (ret < 0) return ret;
                }
                break;
            case 273:
                {
                    int ret = slice_from_s(z, 6, s_264);
                    if (ret < 0) return ret;
                }
                break;
            case 274:
                {
                    int ret = slice_from_s(z, 6, s_265);
                    if (ret < 0) return ret;
                }
                break;
            case 275:
                {
                    int ret = slice_from_s(z, 6, s_266);
                    if (ret < 0) return ret;
                }
                break;
            case 276:
                {
                    int ret = slice_from_s(z, 7, s_267);
                    if (ret < 0) return ret;
                }
                break;
            case 277:
                {
                    int ret = slice_from_s(z, 9, s_268);
                    if (ret < 0) return ret;
                }
                break;
            case 278:
                {
                    int ret = slice_from_s(z, 8, s_269);
                    if (ret < 0) return ret;
                }
                break;
            case 279:
                {
                    int ret = slice_from_s(z, 6, s_270);
                    if (ret < 0) return ret;
                }
                break;
            case 280:
                {
                    int ret = slice_from_s(z, 5, s_271);
                    if (ret < 0) return ret;
                }
                break;
            case 281:
                {
                    int ret = slice_from_s(z, 5, s_272);
                    if (ret < 0) return ret;
                }
                break;
            case 282:
                {
                    int ret = slice_from_s(z, 7, s_272);
                    if (ret < 0) return ret;
                }
                break;
            case 283:
                {
                    int ret = slice_from_s(z, 6, s_273);
                    if (ret < 0) return ret;
                }
                break;
            case 284:
                {
                    int ret = slice_from_s(z, 6, s_274);
                    if (ret < 0) return ret;
                }
                break;
            case 285:
                {
                    int ret = slice_from_s(z, 6, s_275);
                    if (ret < 0) return ret;
                }
                break;
            case 286:
                {
                    int ret = slice_from_s(z, 4, s_276);
                    if (ret < 0) return ret;
                }
                break;
            case 287:
                {
                    int ret = slice_from_s(z, 4, s_277);
                    if (ret < 0) return ret;
                }
                break;
            case 288:
                {
                    int ret = slice_from_s(z, 10, s_278);
                    if (ret < 0) return ret;
                }
                break;
            case 289:
                {
                    int ret = slice_from_s(z, 6, s_279);
                    if (ret < 0) return ret;
                }
                break;
            case 290:
                {
                    int ret = slice_from_s(z, 9, s_280);
                    if (ret < 0) return ret;
                }
                break;
            case 291:
                {
                    int ret = slice_from_s(z, 5, s_281);
                    if (ret < 0) return ret;
                }
                break;
            case 292:
                {
                    int ret = slice_from_s(z, 7, s_282);
                    if (ret < 0) return ret;
                }
                break;
            case 293:
                {
                    int ret = slice_from_s(z, 7, s_283);
                    if (ret < 0) return ret;
                }
                break;
            case 294:
                {
                    int ret = slice_from_s(z, 5, s_284);
                    if (ret < 0) return ret;
                }
                break;
            case 295:
                {
                    int ret = slice_from_s(z, 6, s_285);
                    if (ret < 0) return ret;
                }
                break;
            case 296:
                {
                    int ret = slice_from_s(z, 3, s_286);
                    if (ret < 0) return ret;
                }
                break;
            case 297:
                {
                    int ret = slice_from_s(z, 7, s_287);
                    if (ret < 0) return ret;
                }
                break;
            case 298:
                {
                    int ret = slice_from_s(z, 10, s_288);
                    if (ret < 0) return ret;
                }
                break;
            case 299:
                {
                    int ret = slice_from_s(z, 7, s_289);
                    if (ret < 0) return ret;
                }
                break;
            case 300:
                {
                    int ret = slice_from_s(z, 9, s_290);
                    if (ret < 0) return ret;
                }
                break;
            case 301:
                {
                    int ret = slice_from_s(z, 8, s_291);
                    if (ret < 0) return ret;
                }
                break;
            case 302:
                {
                    int ret = slice_from_s(z, 5, s_292);
                    if (ret < 0) return ret;
                }
                break;
            case 303:
                {
                    int ret = slice_from_s(z, 7, s_293);
                    if (ret < 0) return ret;
                }
                break;
            case 304:
                {
                    int ret = slice_from_s(z, 6, s_294);
                    if (ret < 0) return ret;
                }
                break;
            case 305:
                {
                    int ret = slice_from_s(z, 6, s_295);
                    if (ret < 0) return ret;
                }
                break;
            case 306:
                {
                    int ret = slice_from_s(z, 5, s_296);
                    if (ret < 0) return ret;
                }
                break;
            case 307:
                {
                    int ret = slice_from_s(z, 4, s_297);
                    if (ret < 0) return ret;
                }
                break;
            case 308:
                {
                    int ret = slice_from_s(z, 6, s_298);
                    if (ret < 0) return ret;
                }
                break;
            case 309:
                {
                    int ret = slice_from_s(z, 7, s_299);
                    if (ret < 0) return ret;
                }
                break;
            case 310:
                {
                    int ret = slice_from_s(z, 5, s_300);
                    if (ret < 0) return ret;
                }
                break;
            case 311:
                {
                    int ret = slice_from_s(z, 6, s_301);
                    if (ret < 0) return ret;
                }
                break;
            case 312:
                {
                    int ret = slice_from_s(z, 4, s_302);
                    if (ret < 0) return ret;
                }
                break;
            case 313:
                {
                    int ret = slice_from_s(z, 6, s_303);
                    if (ret < 0) return ret;
                }
                break;
            case 314:
                {
                    int ret = slice_from_s(z, 6, s_304);
                    if (ret < 0) return ret;
                }
                break;
            case 315:
                {
                    int ret = slice_from_s(z, 5, s_305);
                    if (ret < 0) return ret;
                }
                break;
            case 316:
                {
                    int ret = slice_from_s(z, 3, s_306);
                    if (ret < 0) return ret;
                }
                break;
            case 317:
                {
                    int ret = slice_from_s(z, 10, s_306);
                    if (ret < 0) return ret;
                }
                break;
            case 318:
                {
                    int ret = slice_from_s(z, 3, s_307);
                    if (ret < 0) return ret;
                }
                break;
            case 319:
                {
                    int ret = slice_from_s(z, 6, s_308);
                    if (ret < 0) return ret;
                }
                break;
            case 320:
                {
                    int ret = slice_from_s(z, 6, s_309);
                    if (ret < 0) return ret;
                }
                break;
            case 321:
                {
                    int ret = slice_from_s(z, 11, s_310);
                    if (ret < 0) return ret;
                }
                break;
            case 322:
                {
                    int ret = slice_from_s(z, 3, s_311);
                    if (ret < 0) return ret;
                }
                break;
            case 323:
                {
                    int ret = slice_from_s(z, 4, s_312);
                    if (ret < 0) return ret;
                }
                break;
            case 324:
                {
                    int ret = slice_from_s(z, 4, s_313);
                    if (ret < 0) return ret;
                }
                break;
            case 325:
                {
                    int ret = slice_from_s(z, 6, s_314);
                    if (ret < 0) return ret;
                }
                break;
            case 326:
                {
                    int ret = slice_from_s(z, 10, s_315);
                    if (ret < 0) return ret;
                }
                break;
            case 327:
                {
                    int ret = slice_from_s(z, 4, s_316);
                    if (ret < 0) return ret;
                }
                break;
            case 328:
                {
                    int ret = slice_from_s(z, 6, s_317);
                    if (ret < 0) return ret;
                }
                break;
            case 329:
                {
                    int ret = slice_from_s(z, 4, s_318);
                    if (ret < 0) return ret;
                }
                break;
            case 330:
                {
                    int ret = slice_from_s(z, 10, s_319);
                    if (ret < 0) return ret;
                }
                break;
            case 331:
                {
                    int ret = slice_from_s(z, 10, s_320);
                    if (ret < 0) return ret;
                }
                break;
            case 332:
                {
                    int ret = slice_from_s(z, 5, s_321);
                    if (ret < 0) return ret;
                }
                break;
            case 333:
                {
                    int ret = slice_from_s(z, 5, s_322);
                    if (ret < 0) return ret;
                }
                break;
            case 334:
                {
                    int ret = slice_from_s(z, 7, s_323);
                    if (ret < 0) return ret;
                }
                break;
            case 335:
                {
                    int ret = slice_from_s(z, 4, s_324);
                    if (ret < 0) return ret;
                }
                break;
            case 336:
                {
                    int ret = slice_from_s(z, 3, s_325);
                    if (ret < 0) return ret;
                }
                break;
            case 337:
                {
                    int ret = slice_from_s(z, 5, s_325);
                    if (ret < 0) return ret;
                }
                break;
            case 338:
                {
                    int ret = slice_from_s(z, 4, s_326);
                    if (ret < 0) return ret;
                }
                break;
            case 339:
                {
                    int ret = slice_from_s(z, 5, s_327);
                    if (ret < 0) return ret;
                }
                break;
            case 340:
                {
                    int ret = slice_from_s(z, 4, s_328);
                    if (ret < 0) return ret;
                }
                break;
            case 341:
                {
                    int ret = slice_from_s(z, 7, s_329);
                    if (ret < 0) return ret;
                }
                break;
            case 342:
                {
                    int ret = slice_from_s(z, 3, s_330);
                    if (ret < 0) return ret;
                }
                break;
            case 343:
                {
                    int ret = slice_from_s(z, 3, s_331);
                    if (ret < 0) return ret;
                }
                break;
            case 344:
                {
                    int ret = slice_from_s(z, 8, s_332);
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
                if (!(eq_s_b(z, 2, s_333))) { z->lb = v_12; goto lab11; }
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
                        int ret = slice_from_s(z, 1, s_240);
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
                        int ret = slice_from_s(z, 1, s_243);
                        if (ret < 0) return ret;
                    }
                    break;
                case 4:
                    {
                        int ret = slice_from_s(z, 3, s_334);
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
