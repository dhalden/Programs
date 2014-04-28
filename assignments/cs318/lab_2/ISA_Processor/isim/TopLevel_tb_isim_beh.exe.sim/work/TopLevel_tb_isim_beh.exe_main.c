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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_11211262394552056272_2352116331_init();
    work_m_03484898299460613440_1817270755_init();
    work_m_06182839511139081908_2058220583_init();
    work_m_12221351626149339226_3866583278_init();
    work_m_12120086073075627185_3082083525_init();
    work_m_04544521582776293586_0886308060_init();
    work_m_14696055914231528139_3915170638_init();
    work_m_05108143443723865430_4007889531_init();
    work_m_16541823861846354283_2073120511_init();


    xsi_register_tops("work_m_05108143443723865430_4007889531");
    xsi_register_tops("work_m_16541823861846354283_2073120511");


    return xsi_run_simulation(argc, argv);

}
