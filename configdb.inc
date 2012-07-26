<?php

$db_config = array (
    array ('name' => 'google_analytics_code', 
           'description' => lang::translate('google_analytics_code'),
           'type' => 'text', 
           'value' => 'UA-XXXXXXX-X',
           'auth' => 'admin'),
    array ('name' => 'google_analytics_webmaster_code', 
           'description' => lang::translate('google_analytics_webmaster_code'),
           'type' => 'text', 
           'value' => '',
           'auth' => 'admin'),
);

//$db_config_menu = true;