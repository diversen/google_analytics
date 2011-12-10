<?php

/**
 * model file add google analytics to page
 *
 * @package    google_analytics
 */

/**
 * path class implements runlevel 5
 *
 * @package    google_analytics
 */
class google_analytics {
    /**
     * constructor of cache model
     */

    public function runLevel($level){
        if ($level == 5){
            $code = html::specialEncode(get_module_ini('google_analytics_code'));
            $google_js = _COS_PATH . "/modules/google_analytics/google.js";
            str_replace('google_analytics_code', $code, $google_js);
            
            $search = 'google_analytics_code';
            $replace = $code;
            template::setInlineJs(
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