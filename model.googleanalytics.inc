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
class googleanalytics {
    /**
     * constructor of cache model
     */

    public function runLevel($level){
        if ($level == 5){
            $webmaster = config::getModuleIni('google_analytics_webmaster_code');
            if (!empty($webmaster)) {
                $ary = array ('google-site-verification' => $webmaster);
                template::setMeta($ary);
            }
            
            
            $code = html::specialEncode(config::getModuleIni('google_analytics_code'));
            $override = config::getModuleIni('google_analytics_code_override');
            
            $search = array ('google_analytics_code', 'google_analytics_domain');
            if (isset($override)) {
                $code = $override;
                $domain = config::getModuleIni('google_analytics_domain');
                $google_js = _COS_MOD_PATH . '/googleanalytics/google_multi.js';
            } else {
                $domain = '';
                $google_js = _COS_MOD_PATH . '/googleanalytics/google.js';
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