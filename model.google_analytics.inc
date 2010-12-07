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
            $ini = moduleLoader::getModuleIniSettings('google_analytics');
            if (empty($ini['google_ac'])){
                return;
            }
            $str = <<<EOD
<script type="text/javascript">
var gaJsHost = (("https:" == document.location.protocol) ? "https://ssl." : "http://www.");
document.write(unescape("%3Cscript src='" + gaJsHost + "google-analytics.com/ga.js' type='text/javascript'%3E%3C/script%3E"));
</script>
<script type="text/javascript">
try {
var pageTracker = _gat._getTracker("{$ini['google_ac']}");
pageTracker._trackPageview();
} catch(err) {}</script>
EOD;
        template::setEndHTML($str);
        }
    }
}