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
static const char *ng0 = "/home/jebediah/My_Stuff/Programs/assignments/cs318/lab_2/ALU.v";
static int ng1[] = {1, 0};
static int ng2[] = {0, 0};
static int ng3[] = {2, 0};
static int ng4[] = {64, 0};
static int ng5[] = {3, 0};
static int ng6[] = {4, 0};
static int ng7[] = {5, 0};
static int ng8[] = {6, 0};
static int ng9[] = {7, 0};
static int ng10[] = {8, 0};
static int ng11[] = {9, 0};
static int ng12[] = {289, 0};
static int ng13[] = {96, 0};
static int ng14[] = {10, 0};
static unsigned int ng15[] = {0U, 0U};
static unsigned int ng16[] = {1U, 0U};



static void Cont_33_0(char *t0)
{
    char t3[8];
    char t4[8];
    char t7[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;
    char *t43;
    unsigned int t44;
    unsigned int t45;
    char *t46;
    unsigned int t47;
    unsigned int t48;
    char *t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;

LAB0:    t1 = (t0 + 3480U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(33, ng0);
    t2 = (t0 + 1368U);
    t5 = *((char **)t2);
    t2 = (t0 + 1528U);
    t6 = *((char **)t2);
    memset(t7, 0, 8);
    t2 = (t5 + 4);
    t8 = (t6 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t6);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t2);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t2);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB7;

LAB4:    if (t18 != 0)
        goto LAB6;

LAB5:    *((unsigned int *)t7) = 1;

LAB7:    memset(t4, 0, 8);
    t22 = (t7 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t7);
    t26 = (t25 & t24);
    t27 = (t26 & 1U);
    if (t27 != 0)
        goto LAB8;

LAB9:    if (*((unsigned int *)t22) != 0)
        goto LAB10;

LAB11:    t29 = (t4 + 4);
    t30 = *((unsigned int *)t4);
    t31 = *((unsigned int *)t29);
    t32 = (t30 || t31);
    if (t32 > 0)
        goto LAB12;

LAB13:    t34 = *((unsigned int *)t4);
    t35 = (~(t34));
    t36 = *((unsigned int *)t29);
    t37 = (t35 || t36);
    if (t37 > 0)
        goto LAB14;

LAB15:    if (*((unsigned int *)t29) > 0)
        goto LAB16;

LAB17:    if (*((unsigned int *)t4) > 0)
        goto LAB18;

LAB19:    memcpy(t3, t38, 8);

LAB20:    t39 = (t0 + 4144);
    t40 = (t39 + 56U);
    t41 = *((char **)t40);
    t42 = (t41 + 56U);
    t43 = *((char **)t42);
    memset(t43, 0, 8);
    t44 = 1U;
    t45 = t44;
    t46 = (t3 + 4);
    t47 = *((unsigned int *)t3);
    t44 = (t44 & t47);
    t48 = *((unsigned int *)t46);
    t45 = (t45 & t48);
    t49 = (t43 + 4);
    t50 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t50 | t44);
    t51 = *((unsigned int *)t49);
    *((unsigned int *)t49) = (t51 | t45);
    xsi_driver_vfirst_trans(t39, 0, 0);
    t52 = (t0 + 4048);
    *((int *)t52) = 1;

LAB1:    return;
LAB6:    t21 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB7;

LAB8:    *((unsigned int *)t4) = 1;
    goto LAB11;

LAB10:    t28 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB11;

LAB12:    t33 = ((char*)((ng1)));
    goto LAB13;

LAB14:    t38 = ((char*)((ng2)));
    goto LAB15;

LAB16:    xsi_vlog_unsigned_bit_combine(t3, 32, t33, 32, t38, 32);
    goto LAB20;

LAB18:    memcpy(t3, t33, 8);
    goto LAB20;

}

static void Always_35_1(char *t0)
{
    char t9[8];
    char t10[8];
    char t11[8];
    char t24[8];
    char t40[8];
    char t55[8];
    char t69[8];
    char t85[8];
    char t93[8];
    char t143[8];
    char t144[8];
    char t145[8];
    char t148[8];
    char t157[8];
    char t171[8];
    char t185[8];
    char t195[8];
    char t205[8];
    char t219[8];
    char t229[8];
    char t239[8];
    char t253[8];
    char t267[8];
    char t277[8];
    char t287[8];
    char t301[8];
    char t311[8];
    char t321[8];
    char t335[8];
    char t349[8];
    char t363[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    char *t8;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    char *t39;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    char *t47;
    char *t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;
    char *t53;
    char *t54;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    char *t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    char *t68;
    char *t70;
    char *t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    char *t84;
    char *t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    char *t92;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    char *t97;
    char *t98;
    char *t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    char *t107;
    char *t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    int t117;
    int t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    char *t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    char *t131;
    char *t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    char *t136;
    unsigned int t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    char *t141;
    char *t142;
    char *t146;
    char *t147;
    char *t149;
    char *t150;
    char *t151;
    unsigned int t152;
    unsigned int t153;
    unsigned int t154;
    unsigned int t155;
    unsigned int t156;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    char *t161;
    char *t162;
    char *t163;
    unsigned int t164;
    unsigned int t165;
    unsigned int t166;
    unsigned int t167;
    unsigned int t168;
    unsigned int t169;
    unsigned int t170;
    unsigned int t172;
    unsigned int t173;
    unsigned int t174;
    char *t175;
    char *t176;
    char *t177;
    unsigned int t178;
    unsigned int t179;
    unsigned int t180;
    unsigned int t181;
    unsigned int t182;
    unsigned int t183;
    unsigned int t184;
    char *t186;
    char *t187;
    char *t188;
    unsigned int t189;
    unsigned int t190;
    unsigned int t191;
    unsigned int t192;
    unsigned int t193;
    unsigned int t194;
    char *t196;
    char *t197;
    char *t198;
    unsigned int t199;
    unsigned int t200;
    unsigned int t201;
    unsigned int t202;
    unsigned int t203;
    unsigned int t204;
    unsigned int t206;
    unsigned int t207;
    unsigned int t208;
    char *t209;
    char *t210;
    char *t211;
    unsigned int t212;
    unsigned int t213;
    unsigned int t214;
    unsigned int t215;
    unsigned int t216;
    unsigned int t217;
    unsigned int t218;
    char *t220;
    char *t221;
    char *t222;
    unsigned int t223;
    unsigned int t224;
    unsigned int t225;
    unsigned int t226;
    unsigned int t227;
    unsigned int t228;
    char *t230;
    char *t231;
    char *t232;
    unsigned int t233;
    unsigned int t234;
    unsigned int t235;
    unsigned int t236;
    unsigned int t237;
    unsigned int t238;
    unsigned int t240;
    unsigned int t241;
    unsigned int t242;
    char *t243;
    char *t244;
    char *t245;
    unsigned int t246;
    unsigned int t247;
    unsigned int t248;
    unsigned int t249;
    unsigned int t250;
    unsigned int t251;
    unsigned int t252;
    unsigned int t254;
    unsigned int t255;
    unsigned int t256;
    char *t257;
    char *t258;
    char *t259;
    unsigned int t260;
    unsigned int t261;
    unsigned int t262;
    unsigned int t263;
    unsigned int t264;
    unsigned int t265;
    unsigned int t266;
    char *t268;
    char *t269;
    char *t270;
    unsigned int t271;
    unsigned int t272;
    unsigned int t273;
    unsigned int t274;
    unsigned int t275;
    unsigned int t276;
    char *t278;
    char *t279;
    char *t280;
    unsigned int t281;
    unsigned int t282;
    unsigned int t283;
    unsigned int t284;
    unsigned int t285;
    unsigned int t286;
    unsigned int t288;
    unsigned int t289;
    unsigned int t290;
    char *t291;
    char *t292;
    char *t293;
    unsigned int t294;
    unsigned int t295;
    unsigned int t296;
    unsigned int t297;
    unsigned int t298;
    unsigned int t299;
    unsigned int t300;
    char *t302;
    char *t303;
    char *t304;
    unsigned int t305;
    unsigned int t306;
    unsigned int t307;
    unsigned int t308;
    unsigned int t309;
    unsigned int t310;
    char *t312;
    char *t313;
    char *t314;
    unsigned int t315;
    unsigned int t316;
    unsigned int t317;
    unsigned int t318;
    unsigned int t319;
    unsigned int t320;
    unsigned int t322;
    unsigned int t323;
    unsigned int t324;
    char *t325;
    char *t326;
    char *t327;
    unsigned int t328;
    unsigned int t329;
    unsigned int t330;
    unsigned int t331;
    unsigned int t332;
    unsigned int t333;
    unsigned int t334;
    unsigned int t336;
    unsigned int t337;
    unsigned int t338;
    char *t339;
    char *t340;
    char *t341;
    unsigned int t342;
    unsigned int t343;
    unsigned int t344;
    unsigned int t345;
    unsigned int t346;
    unsigned int t347;
    unsigned int t348;
    unsigned int t350;
    unsigned int t351;
    unsigned int t352;
    char *t353;
    char *t354;
    char *t355;
    unsigned int t356;
    unsigned int t357;
    unsigned int t358;
    unsigned int t359;
    unsigned int t360;
    unsigned int t361;
    unsigned int t362;
    unsigned int t364;
    unsigned int t365;
    unsigned int t366;
    char *t367;
    char *t368;
    char *t369;
    unsigned int t370;
    unsigned int t371;
    unsigned int t372;
    unsigned int t373;
    unsigned int t374;
    unsigned int t375;
    unsigned int t376;
    char *t377;

LAB0:    t1 = (t0 + 3728U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(35, ng0);
    t2 = (t0 + 4064);
    *((int *)t2) = 1;
    t3 = (t0 + 3760);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(36, ng0);

LAB5:    xsi_set_current_line(39, ng0);
    t4 = (t0 + 1208U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t4, 32);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 32);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 32);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 32);
    if (t6 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng6)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 32);
    if (t6 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng7)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 32);
    if (t6 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng8)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 32);
    if (t6 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng9)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 32);
    if (t6 == 1)
        goto LAB21;

LAB22:    t2 = ((char*)((ng10)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 32);
    if (t6 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng11)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 32);
    if (t6 == 1)
        goto LAB25;

LAB26:    t2 = ((char*)((ng14)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 32);
    if (t6 == 1)
        goto LAB27;

LAB28:
LAB30:
LAB29:    xsi_set_current_line(52, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);

LAB31:    xsi_set_current_line(55, ng0);
    t2 = (t0 + 2408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);

LAB169:    t7 = ((char*)((ng15)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 16, t7, 16);
    if (t6 == 1)
        goto LAB170;

LAB171:
LAB173:
LAB172:    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng15)));
    t3 = (t0 + 2568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB174:    goto LAB2;

LAB7:    xsi_set_current_line(40, ng0);
    t7 = ((char*)((ng2)));
    t8 = (t0 + 2408);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 16);
    goto LAB31;

LAB9:    xsi_set_current_line(41, ng0);
    t3 = ((char*)((ng1)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 16);
    goto LAB31;

LAB11:    xsi_set_current_line(42, ng0);
    t3 = ((char*)((ng4)));
    t4 = (t0 + 1368U);
    t7 = *((char **)t4);
    memset(t9, 0, 8);
    xsi_vlog_unsigned_minus(t9, 32, t3, 32, t7, 16);
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t9, 0, 0, 16);
    goto LAB31;

LAB13:    xsi_set_current_line(43, ng0);
    t3 = (t0 + 1368U);
    t4 = *((char **)t3);
    t3 = (t0 + 2408);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 16);
    goto LAB31;

LAB15:    xsi_set_current_line(44, ng0);
    t3 = (t0 + 1848U);
    t4 = *((char **)t3);
    t3 = (t0 + 1368U);
    t7 = *((char **)t3);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t7);
    t14 = (t12 ^ t13);
    *((unsigned int *)t11) = t14;
    t3 = (t4 + 4);
    t8 = (t7 + 4);
    t15 = (t11 + 4);
    t16 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    *((unsigned int *)t15) = t18;
    t19 = *((unsigned int *)t15);
    t20 = (t19 != 0);
    if (t20 == 1)
        goto LAB32;

LAB33:
LAB34:    t23 = ((char*)((ng2)));
    memset(t24, 0, 8);
    t25 = (t11 + 4);
    t26 = (t23 + 4);
    t27 = *((unsigned int *)t11);
    t28 = *((unsigned int *)t23);
    t29 = (t27 ^ t28);
    t30 = *((unsigned int *)t25);
    t31 = *((unsigned int *)t26);
    t32 = (t30 ^ t31);
    t33 = (t29 | t32);
    t34 = *((unsigned int *)t25);
    t35 = *((unsigned int *)t26);
    t36 = (t34 | t35);
    t37 = (~(t36));
    t38 = (t33 & t37);
    if (t38 != 0)
        goto LAB38;

LAB35:    if (t36 != 0)
        goto LAB37;

LAB36:    *((unsigned int *)t24) = 1;

LAB38:    memset(t40, 0, 8);
    t41 = (t24 + 4);
    t42 = *((unsigned int *)t41);
    t43 = (~(t42));
    t44 = *((unsigned int *)t24);
    t45 = (t44 & t43);
    t46 = (t45 & 1U);
    if (t46 != 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t41) != 0)
        goto LAB41;

LAB42:    t48 = (t40 + 4);
    t49 = *((unsigned int *)t40);
    t50 = *((unsigned int *)t48);
    t51 = (t49 || t50);
    if (t51 > 0)
        goto LAB43;

LAB44:    memcpy(t93, t40, 8);

LAB45:    memset(t10, 0, 8);
    t125 = (t93 + 4);
    t126 = *((unsigned int *)t125);
    t127 = (~(t126));
    t128 = *((unsigned int *)t93);
    t129 = (t128 & t127);
    t130 = (t129 & 1U);
    if (t130 != 0)
        goto LAB60;

LAB61:    if (*((unsigned int *)t125) != 0)
        goto LAB62;

LAB63:    t132 = (t10 + 4);
    t133 = *((unsigned int *)t10);
    t134 = *((unsigned int *)t132);
    t135 = (t133 || t134);
    if (t135 > 0)
        goto LAB64;

LAB65:    t137 = *((unsigned int *)t10);
    t138 = (~(t137));
    t139 = *((unsigned int *)t132);
    t140 = (t138 || t139);
    if (t140 > 0)
        goto LAB66;

LAB67:    if (*((unsigned int *)t132) > 0)
        goto LAB68;

LAB69:    if (*((unsigned int *)t10) > 0)
        goto LAB70;

LAB71:    memcpy(t9, t143, 8);

LAB72:    t141 = (t0 + 2408);
    xsi_vlogvar_assign_value(t141, t9, 0, 0, 16);
    goto LAB31;

LAB17:    xsi_set_current_line(45, ng0);
    t3 = (t0 + 1528U);
    t4 = *((char **)t3);
    t3 = ((char*)((ng1)));
    memset(t11, 0, 8);
    xsi_vlog_unsigned_add(t11, 32, t4, 16, t3, 32);
    t7 = (t0 + 1368U);
    t8 = *((char **)t7);
    t7 = ((char*)((ng3)));
    memset(t24, 0, 8);
    xsi_vlog_unsigned_lshift(t24, 32, t8, 16, t7, 32);
    memset(t40, 0, 8);
    t15 = (t11 + 4);
    t23 = (t24 + 4);
    t12 = *((unsigned int *)t11);
    t13 = *((unsigned int *)t24);
    t14 = (t12 ^ t13);
    t16 = *((unsigned int *)t15);
    t17 = *((unsigned int *)t23);
    t18 = (t16 ^ t17);
    t19 = (t14 | t18);
    t20 = *((unsigned int *)t15);
    t21 = *((unsigned int *)t23);
    t22 = (t20 | t21);
    t27 = (~(t22));
    t28 = (t19 & t27);
    if (t28 != 0)
        goto LAB76;

LAB73:    if (t22 != 0)
        goto LAB75;

LAB74:    *((unsigned int *)t40) = 1;

LAB76:    memset(t10, 0, 8);
    t26 = (t40 + 4);
    t29 = *((unsigned int *)t26);
    t30 = (~(t29));
    t31 = *((unsigned int *)t40);
    t32 = (t31 & t30);
    t33 = (t32 & 1U);
    if (t33 != 0)
        goto LAB77;

LAB78:    if (*((unsigned int *)t26) != 0)
        goto LAB79;

LAB80:    t41 = (t10 + 4);
    t34 = *((unsigned int *)t10);
    t35 = *((unsigned int *)t41);
    t36 = (t34 || t35);
    if (t36 > 0)
        goto LAB81;

LAB82:    t37 = *((unsigned int *)t10);
    t38 = (~(t37));
    t42 = *((unsigned int *)t41);
    t43 = (t38 || t42);
    if (t43 > 0)
        goto LAB83;

LAB84:    if (*((unsigned int *)t41) > 0)
        goto LAB85;

LAB86:    if (*((unsigned int *)t10) > 0)
        goto LAB87;

LAB88:    memcpy(t9, t55, 8);

LAB89:    t53 = (t0 + 2408);
    xsi_vlogvar_assign_value(t53, t9, 0, 0, 16);
    goto LAB31;

LAB19:    xsi_set_current_line(46, ng0);
    t3 = ((char*)((ng1)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 16);
    goto LAB31;

LAB21:    xsi_set_current_line(47, ng0);
    t3 = (t0 + 1368U);
    t4 = *((char **)t3);
    t3 = ((char*)((ng3)));
    memset(t9, 0, 8);
    xsi_vlog_unsigned_lshift(t9, 16, t4, 16, t3, 32);
    t7 = (t0 + 2408);
    xsi_vlogvar_assign_value(t7, t9, 0, 0, 16);
    goto LAB31;

LAB23:    xsi_set_current_line(48, ng0);
    t3 = (t0 + 1848U);
    t4 = *((char **)t3);
    memset(t9, 0, 8);
    t3 = (t9 + 4);
    t7 = (t4 + 4);
    t12 = *((unsigned int *)t4);
    t13 = (t12 >> 0);
    *((unsigned int *)t9) = t13;
    t14 = *((unsigned int *)t7);
    t16 = (t14 >> 0);
    *((unsigned int *)t3) = t16;
    t17 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t17 & 1U);
    t18 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t18 & 1U);
    t8 = (t0 + 1848U);
    t15 = *((char **)t8);
    memset(t10, 0, 8);
    t8 = (t10 + 4);
    t23 = (t15 + 4);
    t19 = *((unsigned int *)t15);
    t20 = (t19 >> 1);
    *((unsigned int *)t10) = t20;
    t21 = *((unsigned int *)t23);
    t22 = (t21 >> 1);
    *((unsigned int *)t8) = t22;
    t27 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t27 & 1U);
    t28 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t28 & 1U);
    t29 = *((unsigned int *)t9);
    t30 = *((unsigned int *)t10);
    t31 = (t29 ^ t30);
    *((unsigned int *)t11) = t31;
    t25 = (t9 + 4);
    t26 = (t10 + 4);
    t39 = (t11 + 4);
    t32 = *((unsigned int *)t25);
    t33 = *((unsigned int *)t26);
    t34 = (t32 | t33);
    *((unsigned int *)t39) = t34;
    t35 = *((unsigned int *)t39);
    t36 = (t35 != 0);
    if (t36 == 1)
        goto LAB90;

LAB91:
LAB92:    t41 = (t0 + 1848U);
    t47 = *((char **)t41);
    memset(t24, 0, 8);
    t41 = (t24 + 4);
    t48 = (t47 + 4);
    t42 = *((unsigned int *)t47);
    t43 = (t42 >> 2);
    *((unsigned int *)t24) = t43;
    t44 = *((unsigned int *)t48);
    t45 = (t44 >> 2);
    *((unsigned int *)t41) = t45;
    t46 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t46 & 1U);
    t49 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t49 & 1U);
    t52 = (t0 + 1848U);
    t53 = *((char **)t52);
    memset(t40, 0, 8);
    t52 = (t40 + 4);
    t54 = (t53 + 4);
    t50 = *((unsigned int *)t53);
    t51 = (t50 >> 3);
    *((unsigned int *)t40) = t51;
    t56 = *((unsigned int *)t54);
    t57 = (t56 >> 3);
    *((unsigned int *)t52) = t57;
    t58 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t58 & 1U);
    t61 = *((unsigned int *)t52);
    *((unsigned int *)t52) = (t61 & 1U);
    t62 = *((unsigned int *)t24);
    t63 = *((unsigned int *)t40);
    t64 = (t62 ^ t63);
    *((unsigned int *)t55) = t64;
    t59 = (t24 + 4);
    t60 = (t40 + 4);
    t68 = (t55 + 4);
    t65 = *((unsigned int *)t59);
    t66 = *((unsigned int *)t60);
    t67 = (t65 | t66);
    *((unsigned int *)t68) = t67;
    t72 = *((unsigned int *)t68);
    t73 = (t72 != 0);
    if (t73 == 1)
        goto LAB93;

LAB94:
LAB95:    t76 = *((unsigned int *)t11);
    t77 = *((unsigned int *)t55);
    t78 = (t76 ^ t77);
    *((unsigned int *)t69) = t78;
    t70 = (t11 + 4);
    t71 = (t55 + 4);
    t84 = (t69 + 4);
    t79 = *((unsigned int *)t70);
    t80 = *((unsigned int *)t71);
    t81 = (t79 | t80);
    *((unsigned int *)t84) = t81;
    t82 = *((unsigned int *)t84);
    t83 = (t82 != 0);
    if (t83 == 1)
        goto LAB96;

LAB97:
LAB98:    t86 = (t0 + 1848U);
    t92 = *((char **)t86);
    memset(t85, 0, 8);
    t86 = (t85 + 4);
    t97 = (t92 + 4);
    t89 = *((unsigned int *)t92);
    t90 = (t89 >> 4);
    *((unsigned int *)t85) = t90;
    t91 = *((unsigned int *)t97);
    t94 = (t91 >> 4);
    *((unsigned int *)t86) = t94;
    t95 = *((unsigned int *)t85);
    *((unsigned int *)t85) = (t95 & 1U);
    t96 = *((unsigned int *)t86);
    *((unsigned int *)t86) = (t96 & 1U);
    t98 = (t0 + 1848U);
    t99 = *((char **)t98);
    memset(t93, 0, 8);
    t98 = (t93 + 4);
    t107 = (t99 + 4);
    t100 = *((unsigned int *)t99);
    t101 = (t100 >> 5);
    *((unsigned int *)t93) = t101;
    t102 = *((unsigned int *)t107);
    t103 = (t102 >> 5);
    *((unsigned int *)t98) = t103;
    t104 = *((unsigned int *)t93);
    *((unsigned int *)t93) = (t104 & 1U);
    t105 = *((unsigned int *)t98);
    *((unsigned int *)t98) = (t105 & 1U);
    t106 = *((unsigned int *)t85);
    t109 = *((unsigned int *)t93);
    t110 = (t106 ^ t109);
    *((unsigned int *)t143) = t110;
    t108 = (t85 + 4);
    t125 = (t93 + 4);
    t131 = (t143 + 4);
    t111 = *((unsigned int *)t108);
    t112 = *((unsigned int *)t125);
    t113 = (t111 | t112);
    *((unsigned int *)t131) = t113;
    t114 = *((unsigned int *)t131);
    t115 = (t114 != 0);
    if (t115 == 1)
        goto LAB99;

LAB100:
LAB101:    t132 = (t0 + 1848U);
    t136 = *((char **)t132);
    memset(t144, 0, 8);
    t132 = (t144 + 4);
    t141 = (t136 + 4);
    t120 = *((unsigned int *)t136);
    t121 = (t120 >> 6);
    *((unsigned int *)t144) = t121;
    t122 = *((unsigned int *)t141);
    t123 = (t122 >> 6);
    *((unsigned int *)t132) = t123;
    t124 = *((unsigned int *)t144);
    *((unsigned int *)t144) = (t124 & 1U);
    t126 = *((unsigned int *)t132);
    *((unsigned int *)t132) = (t126 & 1U);
    t142 = (t0 + 1848U);
    t146 = *((char **)t142);
    memset(t145, 0, 8);
    t142 = (t145 + 4);
    t147 = (t146 + 4);
    t127 = *((unsigned int *)t146);
    t128 = (t127 >> 7);
    *((unsigned int *)t145) = t128;
    t129 = *((unsigned int *)t147);
    t130 = (t129 >> 7);
    *((unsigned int *)t142) = t130;
    t133 = *((unsigned int *)t145);
    *((unsigned int *)t145) = (t133 & 1U);
    t134 = *((unsigned int *)t142);
    *((unsigned int *)t142) = (t134 & 1U);
    t135 = *((unsigned int *)t144);
    t137 = *((unsigned int *)t145);
    t138 = (t135 ^ t137);
    *((unsigned int *)t148) = t138;
    t149 = (t144 + 4);
    t150 = (t145 + 4);
    t151 = (t148 + 4);
    t139 = *((unsigned int *)t149);
    t140 = *((unsigned int *)t150);
    t152 = (t139 | t140);
    *((unsigned int *)t151) = t152;
    t153 = *((unsigned int *)t151);
    t154 = (t153 != 0);
    if (t154 == 1)
        goto LAB102;

LAB103:
LAB104:    t158 = *((unsigned int *)t143);
    t159 = *((unsigned int *)t148);
    t160 = (t158 ^ t159);
    *((unsigned int *)t157) = t160;
    t161 = (t143 + 4);
    t162 = (t148 + 4);
    t163 = (t157 + 4);
    t164 = *((unsigned int *)t161);
    t165 = *((unsigned int *)t162);
    t166 = (t164 | t165);
    *((unsigned int *)t163) = t166;
    t167 = *((unsigned int *)t163);
    t168 = (t167 != 0);
    if (t168 == 1)
        goto LAB105;

LAB106:
LAB107:    t172 = *((unsigned int *)t69);
    t173 = *((unsigned int *)t157);
    t174 = (t172 ^ t173);
    *((unsigned int *)t171) = t174;
    t175 = (t69 + 4);
    t176 = (t157 + 4);
    t177 = (t171 + 4);
    t178 = *((unsigned int *)t175);
    t179 = *((unsigned int *)t176);
    t180 = (t178 | t179);
    *((unsigned int *)t177) = t180;
    t181 = *((unsigned int *)t177);
    t182 = (t181 != 0);
    if (t182 == 1)
        goto LAB108;

LAB109:
LAB110:    t186 = (t0 + 1848U);
    t187 = *((char **)t186);
    memset(t185, 0, 8);
    t186 = (t185 + 4);
    t188 = (t187 + 4);
    t189 = *((unsigned int *)t187);
    t190 = (t189 >> 8);
    *((unsigned int *)t185) = t190;
    t191 = *((unsigned int *)t188);
    t192 = (t191 >> 8);
    *((unsigned int *)t186) = t192;
    t193 = *((unsigned int *)t185);
    *((unsigned int *)t185) = (t193 & 1U);
    t194 = *((unsigned int *)t186);
    *((unsigned int *)t186) = (t194 & 1U);
    t196 = (t0 + 1848U);
    t197 = *((char **)t196);
    memset(t195, 0, 8);
    t196 = (t195 + 4);
    t198 = (t197 + 4);
    t199 = *((unsigned int *)t197);
    t200 = (t199 >> 9);
    *((unsigned int *)t195) = t200;
    t201 = *((unsigned int *)t198);
    t202 = (t201 >> 9);
    *((unsigned int *)t196) = t202;
    t203 = *((unsigned int *)t195);
    *((unsigned int *)t195) = (t203 & 1U);
    t204 = *((unsigned int *)t196);
    *((unsigned int *)t196) = (t204 & 1U);
    t206 = *((unsigned int *)t185);
    t207 = *((unsigned int *)t195);
    t208 = (t206 ^ t207);
    *((unsigned int *)t205) = t208;
    t209 = (t185 + 4);
    t210 = (t195 + 4);
    t211 = (t205 + 4);
    t212 = *((unsigned int *)t209);
    t213 = *((unsigned int *)t210);
    t214 = (t212 | t213);
    *((unsigned int *)t211) = t214;
    t215 = *((unsigned int *)t211);
    t216 = (t215 != 0);
    if (t216 == 1)
        goto LAB111;

LAB112:
LAB113:    t220 = (t0 + 1848U);
    t221 = *((char **)t220);
    memset(t219, 0, 8);
    t220 = (t219 + 4);
    t222 = (t221 + 4);
    t223 = *((unsigned int *)t221);
    t224 = (t223 >> 10);
    *((unsigned int *)t219) = t224;
    t225 = *((unsigned int *)t222);
    t226 = (t225 >> 10);
    *((unsigned int *)t220) = t226;
    t227 = *((unsigned int *)t219);
    *((unsigned int *)t219) = (t227 & 1U);
    t228 = *((unsigned int *)t220);
    *((unsigned int *)t220) = (t228 & 1U);
    t230 = (t0 + 1848U);
    t231 = *((char **)t230);
    memset(t229, 0, 8);
    t230 = (t229 + 4);
    t232 = (t231 + 4);
    t233 = *((unsigned int *)t231);
    t234 = (t233 >> 11);
    *((unsigned int *)t229) = t234;
    t235 = *((unsigned int *)t232);
    t236 = (t235 >> 11);
    *((unsigned int *)t230) = t236;
    t237 = *((unsigned int *)t229);
    *((unsigned int *)t229) = (t237 & 1U);
    t238 = *((unsigned int *)t230);
    *((unsigned int *)t230) = (t238 & 1U);
    t240 = *((unsigned int *)t219);
    t241 = *((unsigned int *)t229);
    t242 = (t240 ^ t241);
    *((unsigned int *)t239) = t242;
    t243 = (t219 + 4);
    t244 = (t229 + 4);
    t245 = (t239 + 4);
    t246 = *((unsigned int *)t243);
    t247 = *((unsigned int *)t244);
    t248 = (t246 | t247);
    *((unsigned int *)t245) = t248;
    t249 = *((unsigned int *)t245);
    t250 = (t249 != 0);
    if (t250 == 1)
        goto LAB114;

LAB115:
LAB116:    t254 = *((unsigned int *)t205);
    t255 = *((unsigned int *)t239);
    t256 = (t254 ^ t255);
    *((unsigned int *)t253) = t256;
    t257 = (t205 + 4);
    t258 = (t239 + 4);
    t259 = (t253 + 4);
    t260 = *((unsigned int *)t257);
    t261 = *((unsigned int *)t258);
    t262 = (t260 | t261);
    *((unsigned int *)t259) = t262;
    t263 = *((unsigned int *)t259);
    t264 = (t263 != 0);
    if (t264 == 1)
        goto LAB117;

LAB118:
LAB119:    t268 = (t0 + 1848U);
    t269 = *((char **)t268);
    memset(t267, 0, 8);
    t268 = (t267 + 4);
    t270 = (t269 + 4);
    t271 = *((unsigned int *)t269);
    t272 = (t271 >> 12);
    *((unsigned int *)t267) = t272;
    t273 = *((unsigned int *)t270);
    t274 = (t273 >> 12);
    *((unsigned int *)t268) = t274;
    t275 = *((unsigned int *)t267);
    *((unsigned int *)t267) = (t275 & 1U);
    t276 = *((unsigned int *)t268);
    *((unsigned int *)t268) = (t276 & 1U);
    t278 = (t0 + 1848U);
    t279 = *((char **)t278);
    memset(t277, 0, 8);
    t278 = (t277 + 4);
    t280 = (t279 + 4);
    t281 = *((unsigned int *)t279);
    t282 = (t281 >> 13);
    *((unsigned int *)t277) = t282;
    t283 = *((unsigned int *)t280);
    t284 = (t283 >> 13);
    *((unsigned int *)t278) = t284;
    t285 = *((unsigned int *)t277);
    *((unsigned int *)t277) = (t285 & 1U);
    t286 = *((unsigned int *)t278);
    *((unsigned int *)t278) = (t286 & 1U);
    t288 = *((unsigned int *)t267);
    t289 = *((unsigned int *)t277);
    t290 = (t288 ^ t289);
    *((unsigned int *)t287) = t290;
    t291 = (t267 + 4);
    t292 = (t277 + 4);
    t293 = (t287 + 4);
    t294 = *((unsigned int *)t291);
    t295 = *((unsigned int *)t292);
    t296 = (t294 | t295);
    *((unsigned int *)t293) = t296;
    t297 = *((unsigned int *)t293);
    t298 = (t297 != 0);
    if (t298 == 1)
        goto LAB120;

LAB121:
LAB122:    t302 = (t0 + 1848U);
    t303 = *((char **)t302);
    memset(t301, 0, 8);
    t302 = (t301 + 4);
    t304 = (t303 + 4);
    t305 = *((unsigned int *)t303);
    t306 = (t305 >> 14);
    *((unsigned int *)t301) = t306;
    t307 = *((unsigned int *)t304);
    t308 = (t307 >> 14);
    *((unsigned int *)t302) = t308;
    t309 = *((unsigned int *)t301);
    *((unsigned int *)t301) = (t309 & 1U);
    t310 = *((unsigned int *)t302);
    *((unsigned int *)t302) = (t310 & 1U);
    t312 = (t0 + 1848U);
    t313 = *((char **)t312);
    memset(t311, 0, 8);
    t312 = (t311 + 4);
    t314 = (t313 + 4);
    t315 = *((unsigned int *)t313);
    t316 = (t315 >> 15);
    *((unsigned int *)t311) = t316;
    t317 = *((unsigned int *)t314);
    t318 = (t317 >> 15);
    *((unsigned int *)t312) = t318;
    t319 = *((unsigned int *)t311);
    *((unsigned int *)t311) = (t319 & 1U);
    t320 = *((unsigned int *)t312);
    *((unsigned int *)t312) = (t320 & 1U);
    t322 = *((unsigned int *)t301);
    t323 = *((unsigned int *)t311);
    t324 = (t322 ^ t323);
    *((unsigned int *)t321) = t324;
    t325 = (t301 + 4);
    t326 = (t311 + 4);
    t327 = (t321 + 4);
    t328 = *((unsigned int *)t325);
    t329 = *((unsigned int *)t326);
    t330 = (t328 | t329);
    *((unsigned int *)t327) = t330;
    t331 = *((unsigned int *)t327);
    t332 = (t331 != 0);
    if (t332 == 1)
        goto LAB123;

LAB124:
LAB125:    t336 = *((unsigned int *)t287);
    t337 = *((unsigned int *)t321);
    t338 = (t336 ^ t337);
    *((unsigned int *)t335) = t338;
    t339 = (t287 + 4);
    t340 = (t321 + 4);
    t341 = (t335 + 4);
    t342 = *((unsigned int *)t339);
    t343 = *((unsigned int *)t340);
    t344 = (t342 | t343);
    *((unsigned int *)t341) = t344;
    t345 = *((unsigned int *)t341);
    t346 = (t345 != 0);
    if (t346 == 1)
        goto LAB126;

LAB127:
LAB128:    t350 = *((unsigned int *)t253);
    t351 = *((unsigned int *)t335);
    t352 = (t350 ^ t351);
    *((unsigned int *)t349) = t352;
    t353 = (t253 + 4);
    t354 = (t335 + 4);
    t355 = (t349 + 4);
    t356 = *((unsigned int *)t353);
    t357 = *((unsigned int *)t354);
    t358 = (t356 | t357);
    *((unsigned int *)t355) = t358;
    t359 = *((unsigned int *)t355);
    t360 = (t359 != 0);
    if (t360 == 1)
        goto LAB129;

LAB130:
LAB131:    t364 = *((unsigned int *)t171);
    t365 = *((unsigned int *)t349);
    t366 = (t364 ^ t365);
    *((unsigned int *)t363) = t366;
    t367 = (t171 + 4);
    t368 = (t349 + 4);
    t369 = (t363 + 4);
    t370 = *((unsigned int *)t367);
    t371 = *((unsigned int *)t368);
    t372 = (t370 | t371);
    *((unsigned int *)t369) = t372;
    t373 = *((unsigned int *)t369);
    t374 = (t373 != 0);
    if (t374 == 1)
        goto LAB132;

LAB133:
LAB134:    t377 = (t0 + 2408);
    xsi_vlogvar_assign_value(t377, t363, 0, 0, 16);
    goto LAB31;

LAB25:    xsi_set_current_line(50, ng0);
    t3 = (t0 + 1368U);
    t4 = *((char **)t3);
    t3 = ((char*)((ng12)));
    memset(t11, 0, 8);
    t7 = (t4 + 4);
    t8 = (t3 + 4);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t3);
    t14 = (t12 ^ t13);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 ^ t17);
    t19 = (t14 | t18);
    t20 = *((unsigned int *)t7);
    t21 = *((unsigned int *)t8);
    t22 = (t20 | t21);
    t27 = (~(t22));
    t28 = (t19 & t27);
    if (t28 != 0)
        goto LAB138;

LAB135:    if (t22 != 0)
        goto LAB137;

LAB136:    *((unsigned int *)t11) = 1;

LAB138:    memset(t10, 0, 8);
    t23 = (t11 + 4);
    t29 = *((unsigned int *)t23);
    t30 = (~(t29));
    t31 = *((unsigned int *)t11);
    t32 = (t31 & t30);
    t33 = (t32 & 1U);
    if (t33 != 0)
        goto LAB139;

LAB140:    if (*((unsigned int *)t23) != 0)
        goto LAB141;

LAB142:    t26 = (t10 + 4);
    t34 = *((unsigned int *)t10);
    t35 = *((unsigned int *)t26);
    t36 = (t34 || t35);
    if (t36 > 0)
        goto LAB143;

LAB144:    t37 = *((unsigned int *)t10);
    t38 = (~(t37));
    t42 = *((unsigned int *)t26);
    t43 = (t38 || t42);
    if (t43 > 0)
        goto LAB145;

LAB146:    if (*((unsigned int *)t26) > 0)
        goto LAB147;

LAB148:    if (*((unsigned int *)t10) > 0)
        goto LAB149;

LAB150:    memcpy(t9, t55, 8);

LAB151:    t52 = (t0 + 2408);
    xsi_vlogvar_assign_value(t52, t9, 0, 0, 16);
    goto LAB31;

LAB27:    xsi_set_current_line(51, ng0);
    t3 = (t0 + 1368U);
    t4 = *((char **)t3);
    t3 = ((char*)((ng1)));
    memset(t11, 0, 8);
    xsi_vlog_unsigned_add(t11, 32, t4, 16, t3, 32);
    t7 = ((char*)((ng12)));
    memset(t24, 0, 8);
    t8 = (t11 + 4);
    t15 = (t7 + 4);
    t12 = *((unsigned int *)t11);
    t13 = *((unsigned int *)t7);
    t14 = (t12 ^ t13);
    t16 = *((unsigned int *)t8);
    t17 = *((unsigned int *)t15);
    t18 = (t16 ^ t17);
    t19 = (t14 | t18);
    t20 = *((unsigned int *)t8);
    t21 = *((unsigned int *)t15);
    t22 = (t20 | t21);
    t27 = (~(t22));
    t28 = (t19 & t27);
    if (t28 != 0)
        goto LAB155;

LAB152:    if (t22 != 0)
        goto LAB154;

LAB153:    *((unsigned int *)t24) = 1;

LAB155:    memset(t10, 0, 8);
    t25 = (t24 + 4);
    t29 = *((unsigned int *)t25);
    t30 = (~(t29));
    t31 = *((unsigned int *)t24);
    t32 = (t31 & t30);
    t33 = (t32 & 1U);
    if (t33 != 0)
        goto LAB156;

LAB157:    if (*((unsigned int *)t25) != 0)
        goto LAB158;

LAB159:    t39 = (t10 + 4);
    t34 = *((unsigned int *)t10);
    t35 = *((unsigned int *)t39);
    t36 = (t34 || t35);
    if (t36 > 0)
        goto LAB160;

LAB161:    t37 = *((unsigned int *)t10);
    t38 = (~(t37));
    t42 = *((unsigned int *)t39);
    t43 = (t38 || t42);
    if (t43 > 0)
        goto LAB162;

LAB163:    if (*((unsigned int *)t39) > 0)
        goto LAB164;

LAB165:    if (*((unsigned int *)t10) > 0)
        goto LAB166;

LAB167:    memcpy(t9, t40, 8);

LAB168:    t52 = (t0 + 2408);
    xsi_vlogvar_assign_value(t52, t9, 0, 0, 16);
    goto LAB31;

LAB32:    t21 = *((unsigned int *)t11);
    t22 = *((unsigned int *)t15);
    *((unsigned int *)t11) = (t21 | t22);
    goto LAB34;

LAB37:    t39 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t39) = 1;
    goto LAB38;

LAB39:    *((unsigned int *)t40) = 1;
    goto LAB42;

LAB41:    t47 = (t40 + 4);
    *((unsigned int *)t40) = 1;
    *((unsigned int *)t47) = 1;
    goto LAB42;

LAB43:    t52 = (t0 + 1688U);
    t53 = *((char **)t52);
    t52 = (t0 + 1528U);
    t54 = *((char **)t52);
    t56 = *((unsigned int *)t53);
    t57 = *((unsigned int *)t54);
    t58 = (t56 ^ t57);
    *((unsigned int *)t55) = t58;
    t52 = (t53 + 4);
    t59 = (t54 + 4);
    t60 = (t55 + 4);
    t61 = *((unsigned int *)t52);
    t62 = *((unsigned int *)t59);
    t63 = (t61 | t62);
    *((unsigned int *)t60) = t63;
    t64 = *((unsigned int *)t60);
    t65 = (t64 != 0);
    if (t65 == 1)
        goto LAB46;

LAB47:
LAB48:    t68 = ((char*)((ng2)));
    memset(t69, 0, 8);
    t70 = (t55 + 4);
    t71 = (t68 + 4);
    t72 = *((unsigned int *)t55);
    t73 = *((unsigned int *)t68);
    t74 = (t72 ^ t73);
    t75 = *((unsigned int *)t70);
    t76 = *((unsigned int *)t71);
    t77 = (t75 ^ t76);
    t78 = (t74 | t77);
    t79 = *((unsigned int *)t70);
    t80 = *((unsigned int *)t71);
    t81 = (t79 | t80);
    t82 = (~(t81));
    t83 = (t78 & t82);
    if (t83 != 0)
        goto LAB52;

LAB49:    if (t81 != 0)
        goto LAB51;

LAB50:    *((unsigned int *)t69) = 1;

LAB52:    memset(t85, 0, 8);
    t86 = (t69 + 4);
    t87 = *((unsigned int *)t86);
    t88 = (~(t87));
    t89 = *((unsigned int *)t69);
    t90 = (t89 & t88);
    t91 = (t90 & 1U);
    if (t91 != 0)
        goto LAB53;

LAB54:    if (*((unsigned int *)t86) != 0)
        goto LAB55;

LAB56:    t94 = *((unsigned int *)t40);
    t95 = *((unsigned int *)t85);
    t96 = (t94 & t95);
    *((unsigned int *)t93) = t96;
    t97 = (t40 + 4);
    t98 = (t85 + 4);
    t99 = (t93 + 4);
    t100 = *((unsigned int *)t97);
    t101 = *((unsigned int *)t98);
    t102 = (t100 | t101);
    *((unsigned int *)t99) = t102;
    t103 = *((unsigned int *)t99);
    t104 = (t103 != 0);
    if (t104 == 1)
        goto LAB57;

LAB58:
LAB59:    goto LAB45;

LAB46:    t66 = *((unsigned int *)t55);
    t67 = *((unsigned int *)t60);
    *((unsigned int *)t55) = (t66 | t67);
    goto LAB48;

LAB51:    t84 = (t69 + 4);
    *((unsigned int *)t69) = 1;
    *((unsigned int *)t84) = 1;
    goto LAB52;

LAB53:    *((unsigned int *)t85) = 1;
    goto LAB56;

LAB55:    t92 = (t85 + 4);
    *((unsigned int *)t85) = 1;
    *((unsigned int *)t92) = 1;
    goto LAB56;

LAB57:    t105 = *((unsigned int *)t93);
    t106 = *((unsigned int *)t99);
    *((unsigned int *)t93) = (t105 | t106);
    t107 = (t40 + 4);
    t108 = (t85 + 4);
    t109 = *((unsigned int *)t40);
    t110 = (~(t109));
    t111 = *((unsigned int *)t107);
    t112 = (~(t111));
    t113 = *((unsigned int *)t85);
    t114 = (~(t113));
    t115 = *((unsigned int *)t108);
    t116 = (~(t115));
    t117 = (t110 & t112);
    t118 = (t114 & t116);
    t119 = (~(t117));
    t120 = (~(t118));
    t121 = *((unsigned int *)t99);
    *((unsigned int *)t99) = (t121 & t119);
    t122 = *((unsigned int *)t99);
    *((unsigned int *)t99) = (t122 & t120);
    t123 = *((unsigned int *)t93);
    *((unsigned int *)t93) = (t123 & t119);
    t124 = *((unsigned int *)t93);
    *((unsigned int *)t93) = (t124 & t120);
    goto LAB59;

LAB60:    *((unsigned int *)t10) = 1;
    goto LAB63;

LAB62:    t131 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t131) = 1;
    goto LAB63;

LAB64:    t136 = ((char*)((ng2)));
    goto LAB65;

LAB66:    t141 = (t0 + 1848U);
    t142 = *((char **)t141);
    memcpy(t143, t142, 8);
    goto LAB67;

LAB68:    xsi_vlog_unsigned_bit_combine(t9, 32, t136, 32, t143, 32);
    goto LAB72;

LAB70:    memcpy(t9, t136, 8);
    goto LAB72;

LAB75:    t25 = (t40 + 4);
    *((unsigned int *)t40) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB76;

LAB77:    *((unsigned int *)t10) = 1;
    goto LAB80;

LAB79:    t39 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t39) = 1;
    goto LAB80;

LAB81:    t47 = ((char*)((ng2)));
    goto LAB82;

LAB83:    t48 = (t0 + 1528U);
    t52 = *((char **)t48);
    t48 = ((char*)((ng1)));
    memset(t55, 0, 8);
    xsi_vlog_unsigned_add(t55, 32, t52, 16, t48, 32);
    goto LAB84;

LAB85:    xsi_vlog_unsigned_bit_combine(t9, 32, t47, 32, t55, 32);
    goto LAB89;

LAB87:    memcpy(t9, t47, 8);
    goto LAB89;

LAB90:    t37 = *((unsigned int *)t11);
    t38 = *((unsigned int *)t39);
    *((unsigned int *)t11) = (t37 | t38);
    goto LAB92;

LAB93:    t74 = *((unsigned int *)t55);
    t75 = *((unsigned int *)t68);
    *((unsigned int *)t55) = (t74 | t75);
    goto LAB95;

LAB96:    t87 = *((unsigned int *)t69);
    t88 = *((unsigned int *)t84);
    *((unsigned int *)t69) = (t87 | t88);
    goto LAB98;

LAB99:    t116 = *((unsigned int *)t143);
    t119 = *((unsigned int *)t131);
    *((unsigned int *)t143) = (t116 | t119);
    goto LAB101;

LAB102:    t155 = *((unsigned int *)t148);
    t156 = *((unsigned int *)t151);
    *((unsigned int *)t148) = (t155 | t156);
    goto LAB104;

LAB105:    t169 = *((unsigned int *)t157);
    t170 = *((unsigned int *)t163);
    *((unsigned int *)t157) = (t169 | t170);
    goto LAB107;

LAB108:    t183 = *((unsigned int *)t171);
    t184 = *((unsigned int *)t177);
    *((unsigned int *)t171) = (t183 | t184);
    goto LAB110;

LAB111:    t217 = *((unsigned int *)t205);
    t218 = *((unsigned int *)t211);
    *((unsigned int *)t205) = (t217 | t218);
    goto LAB113;

LAB114:    t251 = *((unsigned int *)t239);
    t252 = *((unsigned int *)t245);
    *((unsigned int *)t239) = (t251 | t252);
    goto LAB116;

LAB117:    t265 = *((unsigned int *)t253);
    t266 = *((unsigned int *)t259);
    *((unsigned int *)t253) = (t265 | t266);
    goto LAB119;

LAB120:    t299 = *((unsigned int *)t287);
    t300 = *((unsigned int *)t293);
    *((unsigned int *)t287) = (t299 | t300);
    goto LAB122;

LAB123:    t333 = *((unsigned int *)t321);
    t334 = *((unsigned int *)t327);
    *((unsigned int *)t321) = (t333 | t334);
    goto LAB125;

LAB126:    t347 = *((unsigned int *)t335);
    t348 = *((unsigned int *)t341);
    *((unsigned int *)t335) = (t347 | t348);
    goto LAB128;

LAB129:    t361 = *((unsigned int *)t349);
    t362 = *((unsigned int *)t355);
    *((unsigned int *)t349) = (t361 | t362);
    goto LAB131;

LAB132:    t375 = *((unsigned int *)t363);
    t376 = *((unsigned int *)t369);
    *((unsigned int *)t363) = (t375 | t376);
    goto LAB134;

LAB137:    t15 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB138;

LAB139:    *((unsigned int *)t10) = 1;
    goto LAB142;

LAB141:    t25 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB142;

LAB143:    t39 = ((char*)((ng1)));
    memset(t24, 0, 8);
    xsi_vlog_unsigned_unary_minus(t24, 32, t39, 32);
    goto LAB144;

LAB145:    t41 = (t0 + 1368U);
    t47 = *((char **)t41);
    t41 = ((char*)((ng1)));
    memset(t40, 0, 8);
    xsi_vlog_unsigned_rshift(t40, 32, t47, 16, t41, 32);
    t48 = ((char*)((ng13)));
    memset(t55, 0, 8);
    xsi_vlog_unsigned_minus(t55, 32, t40, 32, t48, 32);
    goto LAB146;

LAB147:    xsi_vlog_unsigned_bit_combine(t9, 32, t24, 32, t55, 32);
    goto LAB151;

LAB149:    memcpy(t9, t24, 8);
    goto LAB151;

LAB154:    t23 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB155;

LAB156:    *((unsigned int *)t10) = 1;
    goto LAB159;

LAB158:    t26 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB159;

LAB160:    t41 = ((char*)((ng2)));
    goto LAB161;

LAB162:    t47 = (t0 + 1368U);
    t48 = *((char **)t47);
    t47 = ((char*)((ng1)));
    memset(t40, 0, 8);
    xsi_vlog_unsigned_add(t40, 32, t48, 16, t47, 32);
    goto LAB163;

LAB164:    xsi_vlog_unsigned_bit_combine(t9, 32, t41, 32, t40, 32);
    goto LAB168;

LAB166:    memcpy(t9, t41, 8);
    goto LAB168;

LAB170:    xsi_set_current_line(56, ng0);
    t8 = ((char*)((ng16)));
    t15 = (t0 + 2568);
    xsi_vlogvar_assign_value(t15, t8, 0, 0, 1);
    goto LAB174;

}


extern void work_m_14377987638530319773_0886308060_init()
{
	static char *pe[] = {(void *)Cont_33_0,(void *)Always_35_1};
	xsi_register_didat("work_m_14377987638530319773_0886308060", "isim/ALU_tb_isim_beh.exe.sim/work/m_14377987638530319773_0886308060.didat");
	xsi_register_executes(pe);
}
