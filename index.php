<?php

if (!session::checkAccessControl('google_analytics_allow')){
    return;
}