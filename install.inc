<?php

use diversen\conf;
use diversen\lang;

$_INSTALL['RUN_LEVEL'] = "0,5";

$disable_menu = conf::getModuleIni('analytics_disable_menu');
if (!$disable_menu) {
    $_INSTALL['MAIN_MENU_ITEM'] = array (
        'title' => lang::translate('Google analytics', null, array('no_translate'=>true)),
        'url' => '/analytics/config/index',
        'module_name' => 'analytics',
        'parent' => 0,
        'weight' => 1,
        'auth' => 'admin',
        'admin_only' => 1,
        'section' => 'settings'
    );
}

