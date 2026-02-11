cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME F4_display)

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    Drivers/BSP/LCD/lcd.c
    Drivers/BSP/LCD/lcd_ex.c
    Drivers/BSP/TIMER/btim.c
    Drivers/SYSTEM/delay/delay.c
    Drivers/BSP/TOUCH/touch.c
    Drivers/BSP/TOUCH/gt9xxx.c
    Drivers/BSP/TOUCH/ft5206.c
    Drivers/BSP/TOUCH/ctiic.c
    Drivers/SYSTEM/sys/sys.c
    
    Drivers/BSP/LED/led.c
    Drivers/BSP/KEY/key.c
    Drivers/BSP/IIC/myiic.c
    Drivers/BSP/24CXX/24cxx.c

    Middlewares/LVGL/GUI/lvgl/examples/porting/lv_port_disp_template.c
    Middlewares/LVGL/GUI/lvgl/examples/porting/lv_port_fs_template.c
    Middlewares/LVGL/GUI/lvgl/examples/porting/lv_port_indev_template.c

    Middlewares/LVGL/GUI/lvgl/src/core/lv_disp.c
    Middlewares/LVGL/GUI/lvgl/src/core/lv_event.c
    Middlewares/LVGL/GUI/lvgl/src/core/lv_group.c
    Middlewares/LVGL/GUI/lvgl/src/core/lv_indev.c
    Middlewares/LVGL/GUI/lvgl/src/core/lv_indev_scroll.c
    Middlewares/LVGL/GUI/lvgl/src/core/lv_obj.c
    Middlewares/LVGL/GUI/lvgl/src/core/lv_obj_class.c
    Middlewares/LVGL/GUI/lvgl/src/core/lv_obj_draw.c
    Middlewares/LVGL/GUI/lvgl/src/core/lv_obj_pos.c
    Middlewares/LVGL/GUI/lvgl/src/core/lv_obj_scroll.c
    Middlewares/LVGL/GUI/lvgl/src/core/lv_obj_style.c
    Middlewares/LVGL/GUI/lvgl/src/core/lv_obj_style_gen.c
    Middlewares/LVGL/GUI/lvgl/src/core/lv_obj_tree.c
    Middlewares/LVGL/GUI/lvgl/src/core/lv_refr.c
    Middlewares/LVGL/GUI/lvgl/src/core/lv_theme.c

    Middlewares/LVGL/GUI/lvgl/src/draw/arm2d/lv_gpu_arm2d.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sdl/lv_draw_sdl.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sdl/lv_draw_sdl_arc.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sdl/lv_draw_sdl_bg.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sdl/lv_draw_sdl_composite.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sdl/lv_draw_sdl_img.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sdl/lv_draw_sdl_label.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sdl/lv_draw_sdl_layer.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sdl/lv_draw_sdl_line.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sdl/lv_draw_sdl_mask.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sdl/lv_draw_sdl_polygon.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sdl/lv_draw_sdl_rect.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sdl/lv_draw_sdl_utils.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sw/lv_draw_sw.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sw/lv_draw_sw_arc.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sw/lv_draw_sw_blend.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sw/lv_draw_sw_dither.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sw/lv_draw_sw_gradient.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sw/lv_draw_sw_img.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sw/lv_draw_sw_layer.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sw/lv_draw_sw_letter.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sw/lv_draw_sw_line.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sw/lv_draw_sw_polygon.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sw/lv_draw_sw_rect.c
    Middlewares/LVGL/GUI/lvgl/src/draw/sw/lv_draw_sw_transform.c
    Middlewares/LVGL/GUI/lvgl/src/draw/lv_draw.c
    Middlewares/LVGL/GUI/lvgl/src/draw/lv_draw_arc.c
    Middlewares/LVGL/GUI/lvgl/src/draw/lv_draw_img.c
    Middlewares/LVGL/GUI/lvgl/src/draw/lv_draw_label.c
    Middlewares/LVGL/GUI/lvgl/src/draw/lv_draw_layer.c
    Middlewares/LVGL/GUI/lvgl/src/draw/lv_draw_line.c
    Middlewares/LVGL/GUI/lvgl/src/draw/lv_draw_mask.c
    Middlewares/LVGL/GUI/lvgl/src/draw/lv_draw_rect.c
    Middlewares/LVGL/GUI/lvgl/src/draw/lv_draw_transform.c
    Middlewares/LVGL/GUI/lvgl/src/draw/lv_draw_triangle.c
    Middlewares/LVGL/GUI/lvgl/src/draw/lv_img_buf.c
    Middlewares/LVGL/GUI/lvgl/src/draw/lv_img_cache.c
    Middlewares/LVGL/GUI/lvgl/src/draw/lv_img_decoder.c

    Middlewares/LVGL/GUI/lvgl/src/extra/layouts/flex/lv_flex.c
    Middlewares/LVGL/GUI/lvgl/src/extra/layouts/grid/lv_grid.c
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/bmp/lv_bmp.c
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/ffmpeg/lv_ffmpeg.c
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/freetype/lv_freetype.c
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.c
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/fsdrv/lv_fs_littlefs.c
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/fsdrv/lv_fs_posix.c
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/fsdrv/lv_fs_stdio.c
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/fsdrv/lv_fs_win32.c
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/gif/gifdec.c
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/gif/lv_gif.c
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/png/lodepng.c
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/png/lv_png.c
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/qrcode/lv_qrcode.c
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/qrcode/qrcodegen.c
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/rlottie/lv_rlottie.c
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/sjpg/lv_sjpg.c
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/sjpg/tjpgd.c
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/tiny_ttf/lv_tiny_ttf.c
    Middlewares/LVGL/GUI/lvgl/src/extra/others/fragment/lv_fragment.c
    Middlewares/LVGL/GUI/lvgl/src/extra/others/fragment/lv_fragment_manager.c
    Middlewares/LVGL/GUI/lvgl/src/extra/others/gridnav/lv_gridnav.c
    Middlewares/LVGL/GUI/lvgl/src/extra/others/ime/lv_ime_pinyin.c
    Middlewares/LVGL/GUI/lvgl/src/extra/others/imgfont/lv_imgfont.c
    Middlewares/LVGL/GUI/lvgl/src/extra/others/monkey/lv_monkey.c
    Middlewares/LVGL/GUI/lvgl/src/extra/others/msg/lv_msg.c
    Middlewares/LVGL/GUI/lvgl/src/extra/others/snapshot/lv_snapshot.c
    Middlewares/LVGL/GUI/lvgl/src/extra/themes/basic/lv_theme_basic.c
    Middlewares/LVGL/GUI/lvgl/src/extra/themes/default/lv_theme_default.c
    Middlewares/LVGL/GUI/lvgl/src/extra/themes/mono/lv_theme_mono.c
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/animimg/lv_animimg.c
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/calendar/lv_calendar.c
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/calendar/lv_calendar_header_arrow.c
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/calendar/lv_calendar_header_dropdown.c
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/chart/lv_chart.c
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/colorwheel/lv_colorwheel.c
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/imgbtn/lv_imgbtn.c
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/keyboard/lv_keyboard.c
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/led/lv_led.c
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/list/lv_list.c
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/menu/lv_menu.c
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/meter/lv_meter.c
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/msgbox/lv_msgbox.c
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/span/lv_span.c
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/spinbox/lv_spinbox.c
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/spinner/lv_spinner.c
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/tabview/lv_tabview.c
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/tileview/lv_tileview.c
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/win/lv_win.c
    Middlewares/LVGL/GUI/lvgl/src/extra/lv_extra.c

    Middlewares/LVGL/GUI/lvgl/src/font/lv_font.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_dejavu_16_persian_hebrew.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_fmt_txt.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_loader.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_montserrat_8.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_montserrat_10.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_montserrat_12.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_montserrat_12_subpx.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_montserrat_14.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_montserrat_16.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_montserrat_18.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_montserrat_20.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_montserrat_22.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_montserrat_24.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_montserrat_26.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_montserrat_28.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_montserrat_28_compressed.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_montserrat_30.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_montserrat_32.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_montserrat_34.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_montserrat_36.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_montserrat_38.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_montserrat_40.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_montserrat_42.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_montserrat_44.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_montserrat_46.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_montserrat_48.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_simsun_16_cjk.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_unscii_8.c
    Middlewares/LVGL/GUI/lvgl/src/font/lv_font_unscii_16.c
    
    Middlewares/LVGL/GUI/lvgl/src/hal/lv_hal_tick.c
    Middlewares/LVGL/GUI/lvgl/src/hal/lv_hal_indev.c
    Middlewares/LVGL/GUI/lvgl/src/hal/lv_hal_disp.c

    Middlewares/LVGL/GUI/lvgl/src/misc/lv_anim.c
    Middlewares/LVGL/GUI/lvgl/src/misc/lv_anim_timeline.c
    Middlewares/LVGL/GUI/lvgl/src/misc/lv_area.c
    Middlewares/LVGL/GUI/lvgl/src/misc/lv_async.c
    Middlewares/LVGL/GUI/lvgl/src/misc/lv_bidi.c
    Middlewares/LVGL/GUI/lvgl/src/misc/lv_color.c
    Middlewares/LVGL/GUI/lvgl/src/misc/lv_fs.c
    Middlewares/LVGL/GUI/lvgl/src/misc/lv_gc.c
    Middlewares/LVGL/GUI/lvgl/src/misc/lv_ll.c
    Middlewares/LVGL/GUI/lvgl/src/misc/lv_log.c
    Middlewares/LVGL/GUI/lvgl/src/misc/lv_lru.c
    Middlewares/LVGL/GUI/lvgl/src/misc/lv_math.c
    Middlewares/LVGL/GUI/lvgl/src/misc/lv_mem.c
    Middlewares/LVGL/GUI/lvgl/src/misc/lv_printf.c
    Middlewares/LVGL/GUI/lvgl/src/misc/lv_style.c
    Middlewares/LVGL/GUI/lvgl/src/misc/lv_style_gen.c
    Middlewares/LVGL/GUI/lvgl/src/misc/lv_templ.c
    Middlewares/LVGL/GUI/lvgl/src/misc/lv_timer.c
    Middlewares/LVGL/GUI/lvgl/src/misc/lv_tlsf.c
    Middlewares/LVGL/GUI/lvgl/src/misc/lv_txt.c
    Middlewares/LVGL/GUI/lvgl/src/misc/lv_txt_ap.c
    Middlewares/LVGL/GUI/lvgl/src/misc/lv_utils.c

    Middlewares/LVGL/GUI/lvgl/src/widgets/lv_arc.c
    Middlewares/LVGL/GUI/lvgl/src/widgets/lv_bar.c
    Middlewares/LVGL/GUI/lvgl/src/widgets/lv_btn.c
    Middlewares/LVGL/GUI/lvgl/src/widgets/lv_btnmatrix.c
    Middlewares/LVGL/GUI/lvgl/src/widgets/lv_canvas.c
    Middlewares/LVGL/GUI/lvgl/src/widgets/lv_checkbox.c
    Middlewares/LVGL/GUI/lvgl/src/widgets/lv_dropdown.c
    Middlewares/LVGL/GUI/lvgl/src/widgets/lv_img.c
    Middlewares/LVGL/GUI/lvgl/src/widgets/lv_label.c
    Middlewares/LVGL/GUI/lvgl/src/widgets/lv_line.c
    Middlewares/LVGL/GUI/lvgl/src/widgets/lv_objx_templ.c
    Middlewares/LVGL/GUI/lvgl/src/widgets/lv_roller.c
    Middlewares/LVGL/GUI/lvgl/src/widgets/lv_slider.c
    Middlewares/LVGL/GUI/lvgl/src/widgets/lv_switch.c
    Middlewares/LVGL/GUI/lvgl/src/widgets/lv_table.c
    Middlewares/LVGL/GUI/lvgl/src/widgets/lv_textarea.c

    

)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    Drivers/BSP/LCD
    Drivers/BSP/TIMER
    Drivers/SYSTEM/sys
    Drivers/SYSTEM/delay
    Drivers/BSP/TOUCH
    Drivers/SYSTEM/usart
    Drivers/BSP/LED
    Drivers/BSP/KEY
    Drivers/BSP/IIC
    Drivers/BSP/24CXX
    Middlewares/LVGL/GUI
    Middlewares/LVGL/GUI/lvgl
    Middlewares/LVGL/GUI/lvgl/src
    Middlewares/LVGL/GUI/lvgl/examples/porting
    Middlewares/LVGL/GUI/lvgl/src/core

    Middlewares/LVGL/GUI/lvgl/src/draw
    Middlewares/LVGL/GUI/lvgl/src/draw/arm2d
    Middlewares/LVGL/GUI/lvgl/src/draw/renesas
    Middlewares/LVGL/GUI/lvgl/src/draw/sdl
    Middlewares/LVGL/GUI/lvgl/src/draw/sw

    Middlewares/LVGL/GUI/lvgl/src/extra
    Middlewares/LVGL/GUI/lvgl/src/extra/layouts
    Middlewares/LVGL/GUI/lvgl/src/extra/layouts/flex
    Middlewares/LVGL/GUI/lvgl/src/extra/layouts/grid
    Middlewares/LVGL/GUI/lvgl/src/extra/libs
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/bmp
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/ffmpeg
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/freetype
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/fsdrv
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/gif
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/png
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/qrcode
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/rlottie
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/sjpg
    Middlewares/LVGL/GUI/lvgl/src/extra/libs/tiny_ttf
    Middlewares/LVGL/GUI/lvgl/src/extra/others
    Middlewares/LVGL/GUI/lvgl/src/extra/others/fragment
    Middlewares/LVGL/GUI/lvgl/src/extra/others/gridnav
    Middlewares/LVGL/GUI/lvgl/src/extra/others/ime
    Middlewares/LVGL/GUI/lvgl/src/extra/others/imgfont
    Middlewares/LVGL/GUI/lvgl/src/extra/others/monkey
    Middlewares/LVGL/GUI/lvgl/src/extra/others/msg
    Middlewares/LVGL/GUI/lvgl/src/extra/others/snapshot
    Middlewares/LVGL/GUI/lvgl/src/extra/themes
    Middlewares/LVGL/GUI/lvgl/src/extra/themes/basic
    Middlewares/LVGL/GUI/lvgl/src/extra/themes/default
    Middlewares/LVGL/GUI/lvgl/src/extra/themes/mono
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/animimg
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/calendar
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/chart
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/colorwheel
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/imgbtn
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/keyboard
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/led
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/list
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/menu
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/meter
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/msgbox
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/span
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/spinbox
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/tabview
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/tileview
    Middlewares/LVGL/GUI/lvgl/src/extra/widgets/win

    Middlewares/LVGL/GUI/lvgl/src/font

    Middlewares/LVGL/GUI/lvgl/src/hal
    Middlewares/LVGL/GUI/lvgl/src/misc
    Middlewares/LVGL/GUI/lvgl/src/widgets
    
    Core/Inc
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Remove wrong libob.a library dependency when using cpp files
list(REMOVE_ITEM CMAKE_C_IMPLICIT_LINK_LIBRARIES ob)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx
    # Add user defined libraries
)

# 自动生成 hex 文件
add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${CMAKE_PROJECT_NAME}> ${CMAKE_PROJECT_NAME}.hex
    COMMENT "生成 HEX 文件: ${CMAKE_PROJECT_NAME}.hex"
)