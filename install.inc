<?php


$_INSTALL['RUN_LEVEL'] = "0,5";
$_INSTALL['VERSION'] = 3.01;

$disable_menu = config::getModuleIni('google_analytics_disable_menu');
if (!$disable_menu) {
    $_INSTALL['MAIN_MENU_ITEM'] = array (
        'title' => lang::translate('Google analytics', null, array('no_translate'=>true)),
        'url' => '/google_analytics/config/index',
        'module_name' => 'google_analytics',
        'parent' => 0,
        'weight' => 1,
        'auth' => 'admin',
        'admin_only' => 1,
        'section' => 'settings'
    );
}

$_INSTALL['PUBLIC_CLONE_URL'] = 'git://github.com/diversen/google_analytics.git';
$_INSTALL['PRIVATE_CLONE_URL'] = 'git@github.com:diversen/google_analytics.git';
