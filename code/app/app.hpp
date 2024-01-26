/**
*********************************************************************************************************
* Copyright (C) 2023-2026 by xiongqulin - All Rights Reserved.                                              *
*                                                                                                       *
* This file is part of the project.                                                                     *
*                                                                                                       *
* This file can not be copied and/or distributed without the express permission of the project owner.   *
*********************************************************************************************************/

/**
*********************************************************************************************************
* @file   : app.cpp
* @author : xiongqulin
* @date   : 25 Dev 2023
* @brief  :
*
*********************************************************************************************************
*/

#pragma once

#include "bsp.hpp"
#include "infrastructure/device/led/blink_led.hpp"
#include "infrastructure/device/motor/m3508.hpp"
#include "infrastructure/device/dr16/dr16.hpp"
#include "infrastructure/component/common/pid.hpp"

namespace App {
struct App {
    IncrementalPid<float> _pid_lf; // 左前轮PID参数
    IncrementalPid<float> _pid_lr; // 左后轮PID参数
    IncrementalPid<float> _pid_rr; // 右前轮PID参数
    IncrementalPid<float> _pid_rf; // 左前轮PID参数

    BlinkLed blink_led;
    Dr16 dr16;

    M3508 m3508_lf; // 左前轮电机
    M3508 m3508_lr; // 左后轮电机
    M3508 m3508_rr; // 右后轮电机
    M3508 m3508_rf; // 右前轮电机

    App();
};

void init();

}; // namespace App

extern App::App *app;