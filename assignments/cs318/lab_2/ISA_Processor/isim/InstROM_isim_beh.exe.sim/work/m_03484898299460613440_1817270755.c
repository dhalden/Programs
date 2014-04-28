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
static const char *ng0 = "/students/home/dhalden/Programs/assignments/cs318/lab_2/InstROM.v";
static int ng1[] = {0, 0};
static unsigned int ng2[] = {496U, 0U};
static int ng3[] = {1, 0};
static unsigned int ng4[] = {6U, 0U};
static int ng5[] = {2, 0};
static unsigned int ng6[] = {193U, 0U};
static int ng7[] = {3, 0};
static unsigned int ng8[] = {194U, 0U};
static int ng9[] = {4, 0};
static unsigned int ng10[] = {195U, 0U};
static int ng11[] = {5, 0};
static unsigned int ng12[] = {319U, 0U};
static int ng13[] = {6, 0};
static unsigned int ng14[] = {688U, 0U};
static int ng15[] = {7, 0};
<<<<<<< HEAD
static unsigned int ng16[] = {583U, 0U};
static int ng17[] = {8, 0};
static unsigned int ng18[] = {394U, 0U};
static int ng19[] = {9, 0};
static unsigned int ng20[] = {64U, 0U};
=======
static unsigned int ng16[] = {64U, 0U};
static const char *ng17 = "Instruction: %b";
>>>>>>> 1c345190586a4179a688d53399b200471a444ddd



static void Always_29_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    char *t8;

LAB0:    t1 = (t0 + 2360U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(29, ng0);
    t2 = (t0 + 2680);
    *((int *)t2) = 1;
    t3 = (t0 + 2392);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(30, ng0);

LAB5:    xsi_set_current_line(31, ng0);
    t4 = (t0 + 1048U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 8, t4, 32);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 8, t2, 32);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 8, t2, 32);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng7)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 8, t2, 32);
    if (t6 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng9)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 8, t2, 32);
    if (t6 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng11)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 8, t2, 32);
    if (t6 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng13)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 8, t2, 32);
    if (t6 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng15)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 8, t2, 32);
    if (t6 == 1)
        goto LAB21;

LAB22:    t2 = ((char*)((ng17)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 8, t2, 32);
    if (t6 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng19)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 8, t2, 32);
    if (t6 == 1)
        goto LAB25;

LAB26:
LAB28:
LAB27:    xsi_set_current_line(89, ng0);
    t2 = ((char*)((ng20)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 10);

<<<<<<< HEAD
LAB29:    goto LAB2;
=======
LAB25:    xsi_set_current_line(91, ng0);
    t2 = (t0 + 1448);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng17, 2, t0, (char)118, t4, 10);
    goto LAB2;
>>>>>>> 1c345190586a4179a688d53399b200471a444ddd

LAB7:    xsi_set_current_line(59, ng0);
    t7 = ((char*)((ng2)));
    t8 = (t0 + 1448);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 10);
    goto LAB29;

LAB9:    xsi_set_current_line(62, ng0);
    t3 = ((char*)((ng4)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 10);
    goto LAB29;

LAB11:    xsi_set_current_line(65, ng0);
    t3 = ((char*)((ng6)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 10);
    goto LAB29;

LAB13:    xsi_set_current_line(68, ng0);
    t3 = ((char*)((ng8)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 10);
    goto LAB29;

LAB15:    xsi_set_current_line(71, ng0);
    t3 = ((char*)((ng10)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 10);
    goto LAB29;

LAB17:    xsi_set_current_line(74, ng0);
    t3 = ((char*)((ng12)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 10);
    goto LAB29;

LAB19:    xsi_set_current_line(77, ng0);
    t3 = ((char*)((ng14)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 10);
    goto LAB29;

LAB21:    xsi_set_current_line(80, ng0);
    t3 = ((char*)((ng16)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 10);
    goto LAB29;

LAB23:    xsi_set_current_line(83, ng0);
    t3 = ((char*)((ng18)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 10);
    goto LAB29;

LAB25:    xsi_set_current_line(86, ng0);
    t3 = ((char*)((ng20)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 10);
    goto LAB29;

}


extern void work_m_03484898299460613440_1817270755_init()
{
	static char *pe[] = {(void *)Always_29_0};
	xsi_register_didat("work_m_03484898299460613440_1817270755", "isim/InstROM_isim_beh.exe.sim/work/m_03484898299460613440_1817270755.didat");
	xsi_register_executes(pe);
}
