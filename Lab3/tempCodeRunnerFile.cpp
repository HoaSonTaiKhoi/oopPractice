this->day  =  (get_total_sec/86400);
    this->hour =  (get_total_sec/3600)%24;
    this->min  =  (get_total_sec/60)%60;
    this->sec  =   get_total_sec%60;