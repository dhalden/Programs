/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/students/home/dhalden/Programs/assignments/cs318/lab_2/DataRAM.v";
static const char *ng1 = "dataram_init.list";
static int ng2[] = {1, 0};
static unsigned int ng3[] = {0U, 0U};
static const char *ng4 = "Memory read M[%d] = %d";
static unsigned int ng5[] = {0U, 65535U};
static const char *ng6 = "Memory write M[%d] = %d";



static void Initial_35_0(char *t0)
{
    char *t1;

LAB0:    xsi_set_current_line(35, ng0);

LAB2:    xsi_set_current_line(36, ng0);
    t1 = (t0 + 2728);
    xsi_vlogfile_readmemh(ng1, 0, t1, 0, 0, 0, 0);

LAB1:    return;
}

static void NetDecl_38_1(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;

LAB0:    t1 = (t0 + 4048U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(38, ng0);
    t2 = (t0 + 1208U);
    t4 = *((char **)t2);
    memset(t3, 0, 8);
    t2 = (t3 + 4);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (t6 >> 0);
    *((unsigned int *)t3) = t7;
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 0);
    *((unsigned int *)t2) = t9;
    t10 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t10 & 1U);
    t11 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t11 & 1U);
    t12 = (t0 + 4976);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memset(t16, 0, 8);
    t17 = 1U;
    t18 = t17;
    t19 = (t3 + 4);
    t20 = *((unsigned int *)t3);
    t17 = (t17 & t20);
    t21 = *((unsigned int *)t19);
    t18 = (t18 & t21);
    t22 = (t16 + 4);
    t23 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t23 | t17);
    t24 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t24 | t18);
    xsi_driver_vfirst_trans(t12, 0, 0U);
    t25 = (t0 + 4864);
    *((int *)t25) = 1;

LAB1:    return;
}

static void Always_40_2(char *t0)
{
    char t6[8];
    char t19[8];
    char t26[8];
    char t64[8];
    char t75[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    int t50;
    int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    char *t65;
    char *t66;
    char *t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    char *t74;
    char *t76;

LAB0:    t1 = (t0 + 4296U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(40, ng0);
    t2 = (t0 + 4880);
    *((int *)t2) = 1;
    t3 = (t0 + 4328);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(41, ng0);
    t4 = (t0 + 2008U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t5 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB5;

LAB6:    if (*((unsigned int *)t4) != 0)
        goto LAB7;

LAB8:    t13 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t13);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB9;

LAB10:    memcpy(t26, t6, 8);

LAB11:    t58 = (t26 + 4);
    t59 = *((unsigned int *)t58);
    t60 = (~(t59));
    t61 = *((unsigned int *)t26);
    t62 = (t61 & t60);
    t63 = (t62 != 0);
    if (t63 > 0)
        goto LAB19;

LAB20:    xsi_set_current_line(51, ng0);

LAB28:    xsi_set_current_line(52, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB29;

LAB30:    xsi_set_current_line(56, ng0);

LAB33:    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 2568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);

LAB31:
LAB21:    goto LAB2;

LAB5:    *((unsigned int *)t6) = 1;
    goto LAB8;

LAB7:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB8;

LAB9:    t17 = (t0 + 1528U);
    t18 = *((char **)t17);
    memset(t19, 0, 8);
    t17 = (t18 + 4);
    t20 = *((unsigned int *)t17);
    t21 = (~(t20));
    t22 = *((unsigned int *)t18);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t17) != 0)
        goto LAB14;

LAB15:    t27 = *((unsigned int *)t6);
    t28 = *((unsigned int *)t19);
    t29 = (t27 & t28);
    *((unsigned int *)t26) = t29;
    t30 = (t6 + 4);
    t31 = (t19 + 4);
    t32 = (t26 + 4);
    t33 = *((unsigned int *)t30);
    t34 = *((unsigned int *)t31);
    t35 = (t33 | t34);
    *((unsigned int *)t32) = t35;
    t36 = *((unsigned int *)t32);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB16;

LAB17:
LAB18:    goto LAB11;

LAB12:    *((unsigned int *)t19) = 1;
    goto LAB15;

LAB14:    t25 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB15;

LAB16:    t38 = *((unsigned int *)t26);
    t39 = *((unsigned int *)t32);
    *((unsigned int *)t26) = (t38 | t39);
    t40 = (t6 + 4);
    t41 = (t19 + 4);
    t42 = *((unsigned int *)t6);
    t43 = (~(t42));
    t44 = *((unsigned int *)t40);
    t45 = (~(t44));
    t46 = *((unsigned int *)t19);
    t47 = (~(t46));
    t48 = *((unsigned int *)t41);
    t49 = (~(t48));
    t50 = (t43 & t45);
    t51 = (t47 & t49);
    t52 = (~(t50));
    t53 = (~(t51));
    t54 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t54 & t52);
    t55 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t55 & t53);
    t56 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t56 & t52);
    t57 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t57 & t53);
    goto LAB18;

LAB19:    xsi_set_current_line(41, ng0);

LAB22:    xsi_set_current_line(42, ng0);
    t65 = (t0 + 1208U);
    t66 = *((char **)t65);
    memset(t64, 0, 8);
    t65 = (t64 + 4);
    t67 = (t66 + 4);
    t68 = *((unsigned int *)t66);
    t69 = (t68 >> 0);
    *((unsigned int *)t64) = t69;
    t70 = *((unsigned int *)t67);
    t71 = (t70 >> 0);
    *((unsigned int *)t65) = t71;
    t72 = *((unsigned int *)t64);
    *((unsigned int *)t64) = (t72 & 65535U);
    t73 = *((unsigned int *)t65);
    *((unsigned int *)t65) = (t73 & 65535U);
    t74 = ((char*)((ng2)));
    memset(t75, 0, 8);
    xsi_vlog_unsigned_rshift(t75, 16, t64, 16, t74, 32);
    t76 = (t0 + 2888);
    xsi_vlogvar_assign_value(t76, t75, 0, 0, 16);
    xsi_set_current_line(44, ng0);
    t2 = (t0 + 2168U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB23;

LAB24:    xsi_set_current_line(46, ng0);

LAB27:    xsi_set_current_line(47, ng0);
    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2728);
    t12 = (t5 + 72U);
    t13 = *((char **)t12);
    t17 = (t0 + 2728);
    t18 = (t17 + 64U);
    t25 = *((char **)t18);
    t30 = (t0 + 2888);
    t31 = (t30 + 56U);
    t32 = *((char **)t31);
    xsi_vlog_generic_get_array_select_value(t19, 16, t4, t13, t25, 2, 1, t32, 16, 2);
    memset(t26, 0, 8);
    t40 = (t26 + 4);
    t41 = (t19 + 4);
    t7 = *((unsigned int *)t19);
    t8 = (t7 >> 8);
    *((unsigned int *)t26) = t8;
    t9 = *((unsigned int *)t41);
    t10 = (t9 >> 8);
    *((unsigned int *)t40) = t10;
    t11 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t11 & 255U);
    t14 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t14 & 255U);
    t58 = ((char*)((ng3)));
    xsi_vlogtype_concat(t6, 16, 16, 2U, t58, 8, t26, 8);
    t65 = (t0 + 2568);
    xsi_vlogvar_assign_value(t65, t6, 0, 0, 16);

LAB25:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 2888);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2568);
    t12 = (t5 + 56U);
    t13 = *((char **)t12);
    xsi_vlogfile_write(1, 0, 0, ng4, 3, t0, (char)118, t4, 16, (char)118, t13, 16);
    goto LAB21;

LAB23:    xsi_set_current_line(44, ng0);

LAB26:    xsi_set_current_line(45, ng0);
    t4 = (t0 + 2728);
    t5 = (t4 + 56U);
    t12 = *((char **)t5);
    t13 = (t0 + 2728);
    t17 = (t13 + 72U);
    t18 = *((char **)t17);
    t25 = (t0 + 2728);
    t30 = (t25 + 64U);
    t31 = *((char **)t30);
    t32 = (t0 + 2888);
    t40 = (t32 + 56U);
    t41 = *((char **)t40);
    xsi_vlog_generic_get_array_select_value(t19, 16, t12, t18, t31, 2, 1, t41, 16, 2);
    memset(t26, 0, 8);
    t58 = (t26 + 4);
    t65 = (t19 + 4);
    t14 = *((unsigned int *)t19);
    t15 = (t14 >> 0);
    *((unsigned int *)t26) = t15;
    t16 = *((unsigned int *)t65);
    t20 = (t16 >> 0);
    *((unsigned int *)t58) = t20;
    t21 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t21 & 255U);
    t22 = *((unsigned int *)t58);
    *((unsigned int *)t58) = (t22 & 255U);
    t66 = ((char*)((ng3)));
    xsi_vlogtype_concat(t6, 16, 16, 2U, t66, 8, t26, 8);
    t67 = (t0 + 2568);
    xsi_vlogvar_assign_value(t67, t6, 0, 0, 16);
    goto LAB25;

LAB29:    xsi_set_current_line(52, ng0);

LAB32:    xsi_set_current_line(53, ng0);
    t4 = (t0 + 2728);
    t5 = (t4 + 56U);
    t12 = *((char **)t5);
    t13 = (t0 + 2728);
    t17 = (t13 + 72U);
    t18 = *((char **)t17);
    t25 = (t0 + 2728);
    t30 = (t25 + 64U);
    t31 = *((char **)t30);
    t32 = (t0 + 1208U);
    t40 = *((char **)t32);
    memset(t19, 0, 8);
    t32 = (t19 + 4);
    t41 = (t40 + 4);
    t14 = *((unsigned int *)t40);
    t15 = (t14 >> 0);
    *((unsigned int *)t19) = t15;
    t16 = *((unsigned int *)t41);
    t20 = (t16 >> 0);
    *((unsigned int *)t32) = t20;
    t21 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t21 & 65535U);
    t22 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t22 & 65535U);
    xsi_vlog_generic_get_array_select_value(t6, 16, t12, t18, t31, 2, 1, t19, 16, 2);
    t58 = (t0 + 2568);
    xsi_vlogvar_assign_value(t58, t6, 0, 0, 16);
    xsi_set_current_line(54, ng0);
    t2 = (t0 + 1208U);
    t3 = *((char **)t2);
    t2 = (t0 + 2568);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    xsi_vlogfile_write(1, 0, 0, ng4, 3, t0, (char)118, t3, 16, (char)118, t5, 16);
    goto LAB31;

}

static void Always_61_3(char *t0)
{
    char t13[8];
    char t14[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    unsigned int t23;
    int t24;
    char *t25;
    unsigned int t26;
    int t27;
    int t28;
    unsigned int t29;
    unsigned int t30;
    int t31;
    int t32;

LAB0:    t1 = (t0 + 4544U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 4896);
    *((int *)t2) = 1;
    t3 = (t0 + 4576);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(62, ng0);
    t4 = (t0 + 1688U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB5;

LAB6:
LAB7:    goto LAB2;

LAB5:    xsi_set_current_line(62, ng0);

LAB8:    xsi_set_current_line(63, ng0);
    t11 = (t0 + 1848U);
    t12 = *((char **)t11);
    t11 = (t0 + 2728);
    t15 = (t0 + 2728);
    t16 = (t15 + 72U);
    t17 = *((char **)t16);
    t18 = (t0 + 2728);
    t19 = (t18 + 64U);
    t20 = *((char **)t19);
    t21 = (t0 + 1368U);
    t22 = *((char **)t21);
    xsi_vlog_generic_convert_array_indices(t13, t14, t17, t20, 2, 1, t22, 16, 2);
    t21 = (t13 + 4);
    t23 = *((unsigned int *)t21);
    t24 = (!(t23));
    t25 = (t14 + 4);
    t26 = *((unsigned int *)t25);
    t27 = (!(t26));
    t28 = (t24 && t27);
    if (t28 == 1)
        goto LAB9;

LAB10:    xsi_set_current_line(64, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    t2 = (t0 + 1848U);
    t4 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng6, 3, t0, (char)118, t3, 16, (char)118, t4, 16);
    goto LAB7;

LAB9:    t29 = *((unsigned int *)t13);
    t30 = *((unsigned int *)t14);
    t31 = (t29 - t30);
    t32 = (t31 + 1);
    xsi_vlogvar_assign_value(t11, t12, 0, *((unsigned int *)t14), t32);
    goto LAB10;

}


extern void work_m_12120086073075627185_3082083525_init()
{
	static char *pe[] = {(void *)Initial_35_0,(void *)NetDecl_38_1,(void *)Always_40_2,(void *)Always_61_3};
	xsi_register_didat("work_m_12120086073075627185_3082083525", "isim/TopLevel_tb_isim_beh.exe.sim/work/m_12120086073075627185_3082083525.didat");
	xsi_register_executes(pe);
}
