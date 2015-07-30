<?php

use diversen\template;
use diversen\conf;
use diversen\html;
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
            $webmaster = conf::getModuleIni('google_analytics_webmaster_code');
            if (!empty($webmaster)) {
                $ary = array ('google-site-verification' => $webmaster);
                template::setMeta($ary);
            }
            
            
            $code = html::specialEncode(conf::getModuleIni('google_analytics_code'));
            $override = conf::getModuleIni('google_analytics_code_override');
            
            $search = array ('google_analytics_code', 'google_analytics_domain');
            if (isset($override)) {
                $code = $override;
                $domain = conf::getModuleIni('google_analytics_domain');
                $google_js = conf::pathModules() . '/google_analytics/google_multi.js';
            } else {
                $domain = '';
                $google_js = conf::pathModules() . '/google_analytics/google.js';
            }
            //velKWzYd5Td2vvUzhdzx9lMutXZBpR8aw4cXKjG5MNM
            $replace = array($code, $domain);
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