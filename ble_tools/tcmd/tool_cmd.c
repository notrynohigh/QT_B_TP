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



