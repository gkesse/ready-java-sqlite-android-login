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
    // custom
    //===============================================
    /* addresskey */
    printf("\
    .addresskey {\n\
        padding: 10px 0px;\n\
    }\n");
    //===============================================
    /* app_name */
    printf("\
    .app_name {\n\
        position: absolute;\n\
        top: 0px;\n\
        bottom: 0px;\n\
        left: 30px;\n\
        padding-top: 5px;\n\
    }\n");
    //===============================================
    /* button */
    printf("\
    .button {\n\
        background-color: %s;\n\
        display: inline-block;\n\
        border-radius: 5px;\n\
        padding: 5px 10px;\n\
        font-family: %s;\n\
        font-size: %spx;\n\
    }\n", lStyle->app_light_color, lStyle->app_font_family, lStyle->app_font_size);
        
    printf("\
    .button:not(last-child) {\n\
        margin-right: 5px;\n\
    }\n");
    //===============================================
    /* content */
    printf("\
    .content {\n\
        position: relative;\n\
        min-height: 32px;\n\
    }\n");
    //===============================================
    /* html */
    printf("\
    .html {\n\
        padding: 10px;\n\
    }\n");
    //===============================================
    /* icon */
    printf("\
    .icon {\n\
        margin-right: 5px;\n\
    }\n");
    //===============================================
    /* item */
    printf("\
    .item {\n\
        padding: 5px 10px;\n\
        cursor: pointer;\n\
        border-radius: 5px;\n\
    }\n");
    
    printf("\
    .item:hover {\n\
        background-color: #503030;\n\
    }\n");
    
    printf("\
    .item:active {\n\
        background-color: transparent;\n\
    }\n");
    //===============================================
    /* login */
    printf("\
    .login {\n\
        position: absolute;\n\
        top: 0px;\n\
        bottom: 0px;\n\
        right: 0px;\n\
    }\n");
    //===============================================
    /* logo */
    printf("\
    .logo {\n\
        position: absolute;\n\
        top: 5px;\n\
        left: 0px;\n\
        width: 25px;\n\
        height: auto;\n\
    }\n");
    //===============================================
    /* main */
    printf("\
    .main {\n\
        max-width: 1000px;\n\
        margin: auto;\n\
    }\n");
    //===============================================
    /* sep */
    printf("\
    .sep {\n\
        padding: 0px 5px;\n\
        font-size: 16px;\n\
    }\n");
    //===============================================
    /* title */
    printf("\
    .title {\n\
        position: absolute;\n\
        top: 0px;\n\
        bottom: 0px;\n\
        left: 100px;\n\
        right: 130px;\n\
        padding-top: 5px;\n\
        text-align: center;\n\
    }\n");
    //===============================================
    /* window */
    printf("\
    .window {\n\
        border: 1px solid #aaaaaa;\n\
        border-radius: 5px;\n\
        padding: 10px;\n\
        overflow: hidden;\n\
        overflow-x: auto;\n\
        position: relative;\n\
    }\n");
    //===============================================
}
//===============================================
