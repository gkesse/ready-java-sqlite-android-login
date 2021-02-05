//===============================================
#include "GStyle.h"
#include "GManager.h"
//===============================================
GStyle* GStyle::m_instance = 0;
//===============================================
GStyle::GStyle() {

}
//===============================================
GStyle::~GStyle() {
    
}
//===============================================
GStyle* GStyle::Instance() {
    if(m_instance == 0) {
        m_instance = new GStyle;
    }
    return m_instance;
}
//===============================================
void GStyle::run(int argc, char** argv) {
    sGStyle* lStyle = GManager::Instance()->getData()->style;
    printf("content-type: text/css;\n\n");
    //===============================================
    // config
    //===============================================
    lStyle->app_fg_color = "#ffffff";
    lStyle->app_bg_color = "#301010";
    lStyle->app_light_color = "#503030";
    lStyle->app_font_size = "20";
    lStyle->app_font_family = "Allan";
    //===============================================
    // common
    //===============================================
    printf("\
    * {\n\
        color: %s;\n\
        margin: 0;\n\
        padding: 0;\n\
        box-sizing: border-box;\n\
    }\n", lStyle->app_fg_color);
    
    printf("\
    *:focus {\n\
        border: none;\n\
        outline: none;\n\
    }\n");

    printf("\
    html {\n\
        -webkit-text-size-adjust: 100%%;\n\
        -webkit-tap-highlight-color: transparent;\n\
        overflow: auto;\n\
        scrollbar-color: #5f6681 #051039;\n\
        scrollbar-width: auto;\n\
    }\n");

    printf("\
    body {\n\
        background-color: %s;\n\
        font-family: %s;\n\
        font-size: %spx;\n\
        text-align: left;\n\
    }\n", lStyle->app_bg_color, lStyle->app_font_family, lStyle->app_font_size);

    printf("\
    button {\n\
        background-color: transparent;\n\
        border: none;\n\
        padding: 5px 10px 5px 5px;\n\
        font-size: 20px;\n\
        font-family: %s;\n\
        color: white;\n\
        cursor: pointer;\n\
    }\n", lStyle->app_font_family);

    printf("\
    input {\n\
        background-color: transparent;\n\
        border: none;\n\
        border-radius: 0;\n\
        padding: 5px 10px 5px 10px;\n\
        font-size: 16px;\n\
        color: white;\n\
        width: 100%%;\n\
    }\n");

    printf("\
    input:-webkit-autofill,;\n\
    input:-webkit-autofill:hover,;\n\
    input:-webkit-autofill:focus {\n\
        -webkit-text-fill-color: white ;\n\
        transition: background-color 5000s ease-in-out 0s;\n\
    }\n");

    printf("\
    select {\n\
        background-color: transparent;\n\
        border: none;\n\
        font-size: 16px;\n\
        color: white;\n\
        cursor: pointer;\n\
    }\n");

    printf("\
    textarea {\n\
        background-color: transparent;\n\
        border: none;\n\
        border-radius: 0;\n\
        padding: 5px 10px 5px 10px;\n\
        font-family: allan;\n\
        font-size: 20px;\n\
        color: white;\n\
        width: 100%%;\n\
        resize: none;\n\
    }\n");

    printf("\
    textarea:-webkit-autofill,;\n\
    textarea:-webkit-autofill:hover,;\n\
    textarea:-webkit-autofill:focus {\n\
        transition: background-color 5000s ease-in-out 0s;\n\
    }\n");

    printf("\
    a {\n\
        text-decoration: none;\n\
    }\n");

    printf("\
    b {\n\
        color: cyan;\n\
    }\n");

    printf("\
    span {\n\
        word-break: break-all;\n\
    }\n");
    //===============================================
    // special
    //===============================================
    /* border_id */
    printf("\
    .border_id {\n\
        border: 2px solid black;\n\
        padding: 10px;\n\
    }\n");
    //===============================================
    /* border_id0 */
    printf("\
    .border_id0 {\n\
        border: 2px solid black;\n\
    }\n");
    //===============================================
    // custom
    //===============================================
    /* addresskey_id */
    printf("\
    .addresskey_id {\n\
        padding: 10px 0px;\n\
    }\n");
    
    printf("\
    .addresskey_id .sep {\n\
        padding: 0px 5px;\n\
        font-size: 16px;\n\
    }\n");
    //===============================================
    /* button_id */
    printf("\
    .button_id {\n\
        background-color: %s;\n\
        display: inline-block;\n\
        border-radius: 5px;\n\
        padding: 5px 10px;\n\
        font-family: %s;\n\
        font-size: %spx;\n\
    }\n", lStyle->app_light_color, lStyle->app_font_family, lStyle->app_font_size);
    
    printf("\
    .button_id .icon:not(last-child) {\n\
        margin-right: 5px;\n\
    }\n");
    //===============================================
    /* html_page */
    printf("\
    .html_page {\n\
        padding: 10px;\n\
    }\n");
    //===============================================
    /* listbox_id */
    printf("\
    .listbox_id {\n\
        \n\
    }\n");
    
    printf("\
    .listbox_id .item {\n\
        padding: 5px 10px;\n\
        cursor: pointer;\n\
        border-radius: 5px;\n\
    }\n");
    
    printf("\
    .listbox_id .item .icon {\n\
        margin-right: 5px;\n\
    }\n");
    
    printf("\
    .listbox_id .item:hover {\n\
        background-color: #503030;\n\
    }\n");
    
    printf("\
    .listbox_id .item:active {\n\
        background-color: transparent;\n\
    }\n");
    //===============================================
    /* main_page */
    printf("\
    .main_page {\n\
        max-width: 1000px;\n\
        margin: auto;\n\
    }\n");
    //===============================================
    /* opencv_id */
    printf("\
    .opencv_id .setting {\n\
        position: relative;\n\
        display: inline-block;\n\
        padding-bottom: 10px;\n\
    }\n");
        
    printf("\
    .opencv_id .menu {\n\
        display: none;\n\
        background-color: #301010;\n\
        border: 2px solid #503030;\n\
        border-radius: 5px;\n\
        position: absolute;\n\
        min-width: 200px;\n\
        padding: 5px;\n\
        z-index: 1;\n\
    }\n");
    
    printf("\
    .opencv_id .setting:hover .menu {\n\
        display: block;\n\
    }\n");
    
    printf("\
    .opencv_id .menu .item {\n\
        display: block;\n\
        padding: 5px;\n\
        border-radius: 5px;\n\
        width: 100%%;\n\
        text-align: left;\n\
    }\n");
    
    printf("\
    .opencv_id .menu .item .icon {\n\
        margin-right: 5px;\n\
    }\n");
    
    printf("\
    .opencv_id .menu .item:hover {\n\
        background-color: %s;\n\
    }\n", lStyle->app_light_color);
    
    printf("\
    .opencv_id .body {\n\
        background-color: %s;\n\
        padding: 10px;\n\
        min-height: 300px;\n\
        border-radius: 5px;\n\
        text-align: center;\n\
    }\n", lStyle->app_light_color);
    //===============================================
    // table_id
    printf("\
    .table_id {\n\
        display: inline-block;\n\
    }\n");
    
    printf("\
    .table_id .name {\n\
        background-color: #305050;\n\
        border: 1px solid #aaaaaa;\n\
        border-bottom-color: transparent;\n\
        padding: 5px 10px;\n\
        text-align: center;\n\
    }\n");
    
    printf("\
    .table_id table {\n\
        border-collapse: collapse;\n\
    }\n");
    
    printf("\
    .table_id table thead tr {\n\
        background-color: #305050;\n\
        text-align: left;\n\
    }\n");
    
    printf("\
    .table_id table th, .table_id  table td {\n\
        padding: 5px 10px;\n\
        border: 1px solid #aaaaaa;\n\
    }\n");
    
    printf("\
    .table_id table th {\n\
        font-weight: normal;\n\
    }\n");
    
    printf("\
    .table_id  table td {\n\
        color: #aaaaaa;\n\
    }\n");
    //===============================================
    /* titlebar_id */
    printf("\
    .titlebar_id {\n\
        border-bottom: 5px solid %s;\n\
        padding-bottom: 5px;\n\
    }\n", lStyle->app_light_color);
    
    printf("\
    .titlebar_id .content {\n\
        position: relative;\n\
        min-height: 32px;\n\
    }\n");
    
    printf("\
    .titlebar_id .content .logo {\n\
        position: absolute;\n\
        top: 5px;\n\
        left: 0px;\n\
        width: 25px;\n\
        height: auto;\n\
    }\n");

    printf("\
    .titlebar_id .content .app_name {\n\
        position: absolute;\n\
        top: 0px;\n\
        bottom: 0px;\n\
        left: 30px;\n\
        padding-top: 5px;\n\
    }\n");
    
    printf("\
    .titlebar_id .content .title {\n\
        position: absolute;\n\
        top: 0px;\n\
        bottom: 0px;\n\
        left: 100px;\n\
        right: 130px;\n\
        padding-top: 5px;\n\
        text-align: center;\n\
    }\n");
    
    printf("\
    .titlebar_id .content .login {\n\
        position: absolute;\n\
        top: 0px;\n\
        bottom: 0px;\n\
        right: 0px;\n\
    }\n");
    //===============================================
    /* window_id */
    printf("\
    .window_id {\n\
        border: 1px solid #aaaaaa;\n\
        border-radius: 5px;\n\
        padding: 10px;\n\
        overflow: hidden;\n\
        overflow-x: auto;\n\
    }\n");
    //===============================================
}
//===============================================
