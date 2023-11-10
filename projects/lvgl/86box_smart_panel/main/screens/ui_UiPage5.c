// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.3
// Project name: AiotArc

#include "../ui.h"

void ui_UiPage5_screen_init(lv_obj_t *parent)
{
    ui_UiPage5 = lv_obj_create(parent);
    lv_obj_clear_flag(ui_UiPage5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_UiPage5, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_UiPage5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(ui_UiPage5, LV_HOR_RES, LV_VER_RES);
    lv_obj_set_style_border_width(ui_UiPage5, 0, 0);
    lv_obj_set_style_pad_all(ui_UiPage5, 0, 0);
    lv_obj_set_style_radius(ui_UiPage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Ui5Tittle = lv_label_create(ui_UiPage5);
    lv_obj_set_width(ui_Ui5Tittle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Ui5Tittle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Ui5Tittle, 20);
    lv_obj_set_y(ui_Ui5Tittle, 20);
    lv_label_set_text(ui_Ui5Tittle, "设置");
    lv_obj_set_style_text_color(ui_Ui5Tittle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Ui5Tittle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Ui5Tittle, &ui_font_FontHei32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Ui5Panel1 = lv_obj_create(ui_UiPage5);
    lv_obj_set_width(ui_Ui5Panel1, 433);
    lv_obj_set_height(ui_Ui5Panel1, 50);
    lv_obj_set_x(ui_Ui5Panel1, 0);
    lv_obj_set_y(ui_Ui5Panel1, 70);
    lv_obj_set_align(ui_Ui5Panel1, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Ui5Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Ui5Panel1, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Ui5Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Ui5Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Ui5Panel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Ui5Panel1, 100, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Ui5Symbol1 = lv_img_create(ui_Ui5Panel1);
    lv_img_set_src(ui_Ui5Symbol1, &ui_img_wifi_symbol_png);
    lv_obj_set_width(ui_Ui5Symbol1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Ui5Symbol1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Ui5Symbol1, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_Ui5Symbol1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Ui5Symbol1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Ui5Label1 = lv_label_create(ui_Ui5Panel1);
    lv_obj_set_width(ui_Ui5Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Ui5Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Ui5Label1, 60);
    lv_obj_set_y(ui_Ui5Label1, 0);
    lv_obj_set_align(ui_Ui5Label1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Ui5Label1, "无线网络");
    lv_obj_set_style_text_color(ui_Ui5Label1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Ui5Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Ui5Label1, &ui_font_FontHei24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Ui5Panel2 = lv_obj_create(ui_UiPage5);
    lv_obj_set_width(ui_Ui5Panel2, 433);
    lv_obj_set_height(ui_Ui5Panel2, 50);
    lv_obj_set_x(ui_Ui5Panel2, 0);
    lv_obj_set_y(ui_Ui5Panel2, 140);
    lv_obj_set_align(ui_Ui5Panel2, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Ui5Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Ui5Panel2, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Ui5Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Ui5Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Ui5Panel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Ui5Panel2, 100, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Ui5Symbol2 = lv_img_create(ui_Ui5Panel2);
    lv_img_set_src(ui_Ui5Symbol2, &ui_img_display_symbol_png);
    lv_obj_set_width(ui_Ui5Symbol2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Ui5Symbol2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Ui5Symbol2, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_Ui5Symbol2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Ui5Symbol2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Ui5Label2 = lv_label_create(ui_Ui5Panel2);
    lv_obj_set_width(ui_Ui5Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Ui5Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Ui5Label2, 60);
    lv_obj_set_y(ui_Ui5Label2, 0);
    lv_obj_set_align(ui_Ui5Label2, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Ui5Label2, "显示");
    lv_obj_set_style_text_color(ui_Ui5Label2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Ui5Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Ui5Label2, &ui_font_FontHei24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Ui5Panel3 = lv_obj_create(ui_UiPage5);
    lv_obj_set_width(ui_Ui5Panel3, 433);
    lv_obj_set_height(ui_Ui5Panel3, 50);
    lv_obj_set_x(ui_Ui5Panel3, 0);
    lv_obj_set_y(ui_Ui5Panel3, 210);
    lv_obj_set_align(ui_Ui5Panel3, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Ui5Panel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Ui5Panel3, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Ui5Panel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Ui5Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Ui5Panel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Ui5Panel3, 100, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Ui5Symbol3 = lv_img_create(ui_Ui5Panel3);
    lv_img_set_src(ui_Ui5Symbol3, &ui_img_voice_symbol_png);
    lv_obj_set_width(ui_Ui5Symbol3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Ui5Symbol3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Ui5Symbol3, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_Ui5Symbol3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Ui5Symbol3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Ui5Label3 = lv_label_create(ui_Ui5Panel3);
    lv_obj_set_width(ui_Ui5Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Ui5Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Ui5Label3, 60);
    lv_obj_set_y(ui_Ui5Label3, 0);
    lv_obj_set_align(ui_Ui5Label3, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Ui5Label3, "声音");
    lv_obj_set_style_text_color(ui_Ui5Label3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Ui5Label3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Ui5Label3, &ui_font_FontHei24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Ui5Panel4 = lv_obj_create(ui_UiPage5);
    lv_obj_set_width(ui_Ui5Panel4, 433);
    lv_obj_set_height(ui_Ui5Panel4, 50);
    lv_obj_set_x(ui_Ui5Panel4, 0);
    lv_obj_set_y(ui_Ui5Panel4, 280);
    lv_obj_set_align(ui_Ui5Panel4, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Ui5Panel4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Ui5Panel4, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Ui5Panel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Ui5Panel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Ui5Panel4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Ui5Panel4, 100, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Ui5Symbol4 = lv_img_create(ui_Ui5Panel4);
    lv_img_set_src(ui_Ui5Symbol4, &ui_img_info_symbol_png);
    lv_obj_set_width(ui_Ui5Symbol4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Ui5Symbol4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Ui5Symbol4, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_Ui5Symbol4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Ui5Symbol4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Ui5Label4 = lv_label_create(ui_Ui5Panel4);
    lv_obj_set_width(ui_Ui5Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Ui5Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Ui5Label4, 60);
    lv_obj_set_y(ui_Ui5Label4, 0);
    lv_obj_set_align(ui_Ui5Label4, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Ui5Label4, "关于本机");
    lv_obj_set_style_text_color(ui_Ui5Label4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Ui5Label4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Ui5Label4, &ui_font_FontHei24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Ui5Panel5 = lv_obj_create(ui_UiPage5);
    lv_obj_set_width(ui_Ui5Panel5, 433);
    lv_obj_set_height(ui_Ui5Panel5, 50);
    lv_obj_set_x(ui_Ui5Panel5, 0);
    lv_obj_set_y(ui_Ui5Panel5, 350);
    lv_obj_set_align(ui_Ui5Panel5, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Ui5Panel5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Ui5Panel5, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Ui5Panel5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Ui5Panel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Ui5Panel5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Ui5Panel5, 100, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Ui5Symbol5 = lv_img_create(ui_Ui5Panel5);
    lv_img_set_src(ui_Ui5Symbol5, &ui_img_updata_symbol_png);
    lv_obj_set_width(ui_Ui5Symbol5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Ui5Symbol5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Ui5Symbol5, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_Ui5Symbol5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Ui5Symbol5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Ui5Label5 = lv_label_create(ui_Ui5Panel5);
    lv_obj_set_width(ui_Ui5Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Ui5Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Ui5Label5, 60);
    lv_obj_set_y(ui_Ui5Label5, 0);
    lv_obj_set_align(ui_Ui5Label5, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Ui5Label5, "系统更新");
    lv_obj_set_style_text_color(ui_Ui5Label5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Ui5Label5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Ui5Label5, &ui_font_FontHei24, LV_PART_MAIN | LV_STATE_DEFAULT);

}
