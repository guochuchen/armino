// Copyright 2020-2021 Beken
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <common/bk_include.h>
#include <driver/uvc_camera_types.h>
#include <components/video_types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define WORD_REVERSE(x) ((((x) & 0x000000ffUL) << 24) | \
						(((x) & 0x0000ff00UL) <<  8) | \
						(((x) & 0x00ff0000UL) >>  8) | \
						(((x) & 0xff000000UL) >> 24))


typedef enum
{
	APP_CAMERA_DVP_JPEG,
	APP_CAMERA_DVP_YUV,
	APP_CAMERA_DVP_MIX,
	APP_CAMERA_UVC_MJPEG,
	APP_CAMERA_UVC_MJPEG_TO_H264,
	APP_CAMERA_UVC_H264,
	APP_CAMERA_NET_MJPEG,
	APP_CAMERA_NET_H264,
	APP_CAMERA_DVP_H264_TRANSFER,
	APP_CAMERA_DVP_H264_LOCAL,
	APP_CAMERA_DVP_H264_ENC_LCD,
	APP_CAMERA_INVALIED,
} app_camera_type_t;

/*
* legacy
*/
#define APP_CAMERA_DVP APP_CAMERA_DVP_JPEG
#define APP_CAMERA_YUV APP_CAMERA_DVP_YUV
#define APP_CAMERA_MIX APP_CAMERA_DVP_MIX
#define APP_CAMERA_UVC APP_CAMERA_UVC_MJPEG

typedef enum
{
	APP_LCD_RGB,
	APP_LCD_MCU,
} app_lcd_type_t;

#ifdef CONFIG_INTEGRATION_DOORBELL
typedef int (*media_transfer_send_cb)(uint8_t *data, uint32_t length);
typedef int (*media_transfer_prepare_cb)(uint8_t *data, uint32_t length);
typedef void* (*media_transfer_get_tx_buf_cb)(void);
typedef int (*media_transfer_get_tx_size_cb)(void);

typedef struct {
	media_transfer_send_cb send;
	media_transfer_prepare_cb prepare;
	media_transfer_get_tx_buf_cb get_tx_buf;
	media_transfer_get_tx_size_cb get_tx_size;
} media_transfer_cb_t;
#endif

#ifdef CONFIG_INTEGRATION_DOORBELL
bk_err_t media_app_camera_open(camera_config_t *camera_config);
#else
bk_err_t media_app_camera_open(app_camera_type_t type, media_ppi_t ppi);
#endif
bk_err_t media_app_camera_close(app_camera_type_t type);
bk_err_t media_app_h264_open(void *setup_cfg);
bk_err_t media_app_h264_close(void);
#ifdef CONFIG_INTEGRATION_DOORBELL
bk_err_t media_app_transfer_open(const media_transfer_cb_t *cb);
#else
bk_err_t media_app_transfer_open(video_setup_t *setup_cfg);
#endif
bk_err_t media_app_transfer_close(void);
bk_err_t media_app_usb_open(video_setup_t *setup_cfg);
bk_err_t media_app_usb_close(void);
bk_err_t media_app_lcd_open(void *lcd_open);
bk_err_t media_app_lcd_close(void);
bk_err_t media_app_storage_enable(app_camera_type_t type, uint8_t enable);
bk_err_t media_app_capture(char *name);
bk_err_t media_app_save_start(char *name);
bk_err_t media_app_save_stop(void);
bk_err_t media_app_lcd_set_backlight(uint8_t level);
bk_err_t media_app_mailbox_test(void);
bk_err_t media_app_lcd_rotate(media_rotate_t rotate);
bk_err_t media_app_lcd_resize(media_ppi_t ppi);
bk_err_t media_app_dump_display_frame(void);
bk_err_t media_app_dump_decoder_frame(void);
bk_err_t media_app_dump_jpeg_frame(void);
bk_err_t media_app_lcd_step_mode(bool enable);
bk_err_t media_app_lcd_step_trigger(void);
bk_err_t media_app_transfer_pause(bool pause);
bk_err_t  media_app_lcd_display_file(char *file_name);  //display sd card file
bk_err_t media_app_lcd_display(void* lcd_display);
bk_err_t media_app_lcd_display_beken(void* lcd_display);
bk_err_t media_app_lcd_blend(void *param);
bk_err_t media_app_register_uvc_connect_state_cb(void *cb);
bk_err_t media_app_lcd_gui_blend_open(int blend_x_size, int blend_y_size);
bk_err_t media_app_lcd_gui_blend_close(void);
bk_err_t media_app_register_read_frame_cb(void *cb);

#if CONFIG_VIDEO_AVI
bk_err_t media_app_avi_open(void);
bk_err_t media_app_avi_close(void);
#endif

bk_err_t media_app_lvgl_draw(void *lcd_open);

#ifdef __cplusplus
}
#endif
