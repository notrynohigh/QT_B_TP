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
    tc_send(CMD_SET_TIME, 0, &set_time, sizeof(pro_time_t));
}

void tc_get_date()
{
    tc_send(CMD_GET_TIME, 0, NULL, 0);
}

void tc_get_version()
{
    tc_send(CMD_VERSION, 0, NULL, 0);
}

void tc_get_total_step()
{
    tc_send(CMD_VERSION, 0, NULL, 0);
}
