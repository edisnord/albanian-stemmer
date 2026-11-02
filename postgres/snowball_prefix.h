/*
 * Renames the Snowball runtime's external symbols. Postgres's own dict_snowball
 * module links a Snowball runtime with the same names (find_among,
 * SN_set_current, ...), and a backend that has loaded both would otherwise
 * call one with the other's data. Passed to every compile with -include.
 */
#ifndef ALBANIAN_SNOWBALL_PREFIX_H
#define ALBANIAN_SNOWBALL_PREFIX_H
#define assign_to              albanian_sb_assign_to
#define create_s               albanian_sb_create_s
#define eq_s                   albanian_sb_eq_s
#define eq_s_b                 albanian_sb_eq_s_b
#define eq_v                   albanian_sb_eq_v
#define eq_v_b                 albanian_sb_eq_v_b
#define find_among             albanian_sb_find_among
#define find_among_b           albanian_sb_find_among_b
#define in_grouping            albanian_sb_in_grouping
#define in_grouping_b          albanian_sb_in_grouping_b
#define in_grouping_b_U        albanian_sb_in_grouping_b_U
#define in_grouping_U          albanian_sb_in_grouping_U
#define insert_s               albanian_sb_insert_s
#define insert_v               albanian_sb_insert_v
#define len_utf8               albanian_sb_len_utf8
#define lose_s                 albanian_sb_lose_s
#define out_grouping           albanian_sb_out_grouping
#define out_grouping_b         albanian_sb_out_grouping_b
#define out_grouping_b_U       albanian_sb_out_grouping_b_U
#define out_grouping_U         albanian_sb_out_grouping_U
#define replace_s              albanian_sb_replace_s
#define skip_b_utf8            albanian_sb_skip_b_utf8
#define skip_utf8              albanian_sb_skip_utf8
#define slice_del              albanian_sb_slice_del
#define slice_from_s           albanian_sb_slice_from_s
#define slice_from_v           albanian_sb_slice_from_v
#define slice_to               albanian_sb_slice_to
#define SN_delete_env          albanian_sb_SN_delete_env
#define SN_new_env             albanian_sb_SN_new_env
#define SN_new_env_no_vars     albanian_sb_SN_new_env_no_vars
#define SN_set_current         albanian_sb_SN_set_current
#endif
