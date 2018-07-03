#include "tcmd/tool_cmd.h"
#include "b_tp/inc/b_tp.h"
#include "string.h"

void tc_send(uint8_t cmd, uint8_t status, uint8_t *pbuf, uint32_t len)
{
    uint8_t tmp_buf[256];
    tcmd_struct_t *pstruct = (tcmd_struct_t *)tmp_buf;
    if(pbuf == NULL && len > 0)
    {
        return;
    }
    pstruct->cmd = cmd;
    pstruct->status = status;
    memcpy(pstruct->buf, pbuf, len);
    b_tp_send_data(tmp_buf, len + 2);
}


void tc_scan_start()
{
    pro_scan_require_t scan_req;
    scan_req.type = 1;
    tc_send(CMD_TOOL_SCAN, 0, (uint8_t *)&scan_req, sizeof(pro_scan_require_t));
}

void tc_scan_stop()
{
    pro_scan_require_t scan_req;
    scan_req.type = 0;
    tc_send(CMD_TOOL_SCAN, 0, (uint8_t *)&scan_req, sizeof(pro_scan_require_t));
}

void tc_set_date(int year, int month, int day, int hour, int minute, int second)
{
    pro_time_t set_time;
    set_time.year = (uint8_t)(year - 2000);
    set_time.month = (uint8_t)month;
    set_time.day = (uint8_t)day;
    set_time.hour = (uint8_t)hour;
    set_time.minute = (uint8_t)minute;
    set_time.second = (uint8_t)second;
    tc_send(CMD_SET_TIME, 0, (uint8_t *)&set_time, sizeof(pro_time_t));
}

void tc_get_date()
{
    tc_send(CMD_GET_TIME, 0, NULL, 0);
}

void tc_get_version()
{
    tc_send(CMD_VERSION, 0, NULL, 0);
}

void tc_get_total_step(uint8_t month, uint8_t day)
{
    pro_total_step_require_t total_step_req;
    total_step_req.month = month;
    total_step_req.day = day;
    tc_send(CMD_GET_TOTAL_STEP, 0, (uint8_t *)&total_step_req, sizeof(pro_total_step_require_t));
}

void tc_draw_wave_start()
{
    pro_draw_wave_type_t dr;
    dr.type = 0;
    tc_send(CMD_DRAW_WAVE_START, 0, (uint8_t *)&dr, sizeof(pro_draw_wave_type_t));
}

void tc_draw_wave_stop()
{
    tc_send(CMD_DRAW_WAVE_END, 0, NULL, 0);
}


void tc_chip_adjust()
{
    tc_send(CMD_CHIP_ADJUST, 0, NULL, 0);
}

void tc_syn_walk_step(uint8_t month, uint8_t day, uint8_t s_hour, uint8_t s_minute, uint8_t e_hour, uint8_t e_minute)
{
    pro_syn_require_t sys_req;
    sys_req.month = month;
    sys_req.day = day;
    sys_req.s_hour = s_hour;
    sys_req.e_hour = e_hour;
    sys_req.e_minute = e_minute;
    sys_req.s_minute = s_minute;

    tc_send(CMD_SYN_WALK_DATA, 0, (uint8_t *)&sys_req, sizeof(pro_syn_require_t));
}

void tc_syn_walk_go_on()
{
    tc_send(CMD_SYN_WALK_DATA, CMD_STATUS_ACK, NULL, 0);
}

void tc_syn_err_go_on()
{
    tc_send(CMD_GET_ERR_INFO, CMD_STATUS_ACK, NULL, 0);
}


void tc_syn_run_step(uint8_t month, uint8_t day, uint8_t s_hour, uint8_t s_minute, uint8_t e_hour, uint8_t e_minute)
{
    pro_syn_require_t sys_req;
    sys_req.month = month;
    sys_req.day = day;
    sys_req.s_hour = s_hour;
    sys_req.e_hour = e_hour;
    sys_req.e_minute = e_minute;
    sys_req.s_minute = s_minute;

    tc_send(CMD_SYN_RUN_DATA, 0, (uint8_t *)&sys_req, sizeof(pro_syn_require_t));
}


void tc_syn_run_go_on()
{
    tc_send(CMD_SYN_RUN_DATA, CMD_STATUS_ACK, NULL, 0);
}

void tc_get_connect_status()
{
    tc_send(CMD_TOOL_CONN_STA, 0, NULL, 0);
}


void tc_realtime_start()
{
    tc_send(CMD_RT_RUN_START, 0, NULL, 0);
}



void tc_realtime_end()
{
    tc_send(CMD_RT_RUN_STOP, 0, NULL, 0);
}


void tc_get_battery()
{
    tc_send(CMD_BATTERY, 0, NULL, 0);
}

void tc_get_breakdown()
{
    tc_send(CMD_GET_BREAKDOWN, 0, NULL, 0);
}

void tc_set_reboot()
{
    tc_send(CMD_REBOOT, 0, NULL, 0);
}

void tc_set_normal_mode()
{
    tc_send(CMD_FAC_TO_NORMAL, 0, NULL, 0);
}

void tc_erase_chip()
{
    tc_send(CMD_ERASE_CHIP, 0, NULL, 0);
}

void tc_send_hb()
{
    tc_send(CMD_HEART, 0, NULL, 0);
}


void tc_set_id(uint32_t id)
{
    pro_user_id_t id_tmp;
    id_tmp.user_id = id;
    tc_send(CMD_SET_USER_ID, 0, (uint8_t *)&id_tmp, sizeof(pro_user_id_t));
}

void tc_get_restart()
{
    pro_req_err_code_t tmp;
    tmp.utc = 0;
    tc_send(CMD_GET_ERR_INFO, 0, (uint8_t *)&tmp, sizeof(pro_req_err_code_t));
}

void tc_get_algo_param()
{
    tc_send(CMD_GET_ALGO_PARAM, 0, NULL, 0);
}

void tc_get_user_id()
{
    tc_send(CMD_GET_USER_ID, 0, NULL, 0);
}


