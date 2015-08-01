<?php

use diversen\lang;
$db_config = array (
    array ('name' => 'google_analytics_code', 
           'description' => lang::translate('Google analytics code'),
           'type' => 'text', 
           'value' => 'UA-XXXXXXX-X',
           'auth' => 'admin'),
    array ('name' => 'google_analytics_webmaster_code', 
           'description' => lang::translate('Google webmaster code'),
           'type' => 'text', 
           'value' => '',
           'auth' => 'admin'),
);
