<?php

namespace modules\analytics;

use diversen\conf;
use diversen\html;
use diversen\template;
use diversen\template\assets;


/**
 * Module that runs the analytics code after normal loading of ini settings
 */

class module {
    /**
     * constructor of cache model
     */

    public function runLevel($level){
        if ($level == 5){
            $webmaster = conf::getModuleIni('analytics_webmaster_code');
            if (!empty($webmaster)) {
                $ary = array ('google-site-verification' => $webmaster);
                template::setMeta($ary);
            }
                      
            $code = html::specialEncode(conf::getModuleIni('analytics_code'));
            $search = array ('analytics_code');

            $google_js = conf::pathModules() . '/analytics/assets/google.js';
            $replace = array($code);
            assets::setInlineJs(
                $google_js, 
                // load last or close to. 
                10000, 
                array ('no_cache'   => 1, 
                       'search'     => $search, 
                       'replace'    => $replace)
            );
        }
    }
}
