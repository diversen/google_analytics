<?php

namespace modules\analytics;

use diversen\conf;
use diversen\html;
use diversen\template;


/**
 * model file add google analytics to page
 *
 * @package    analytics
 */

/**
 * path class implements runlevel 5
 *
 * @package    analytics
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
            $override = conf::getModuleIni('analytics_code_override');
            
            $search = array ('analytics_code', 'analytics_domain');
            if (isset($override)) {
                $code = $override;
                $domain = conf::getModuleIni('analytics_domain');
                $google_js = conf::pathModules() . '/analytics/assets/google_multi.js';
            } else {
                $domain = '';
                $google_js = conf::pathModules() . '/analytics/assets/google.js';
            }

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
