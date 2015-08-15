<?php

namespace modules\analytics\config;

use diversen\lang;
use modules\configdb\module as configdb;

class module {
    public function indexAction () {
        configdb::displayConfig('analytics');
    }
    
    public static function getConfigSetup() {
        $db_config = array(
            array('name' => 'analytics_code',
                'description' => lang::translate('Google analytics code'),
                'type' => 'text',
                'value' => 'UA-XXXXXXX-X',
                'auth' => 'admin'),
            array('name' => 'analytics_webmaster_code',
                'description' => lang::translate('Google webmaster code'),
                'type' => 'text',
                'value' => 'webmaster code',
                'auth' => 'admin'),
        );
        return $db_config;
    }

}
