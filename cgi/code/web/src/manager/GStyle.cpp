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
        font-family: %s;\n\
        font-size: %spx;\n\
        color: white;\n\
        cursor: pointer;\n\
    }\n", lStyle->app_font_family, lStyle->app_font_size);

    printf("\
    input {\n\
        background-color: transparent;\n\
        border: none;\n\
        border-radius: 0;\n\
        font-family: %s;\n\
        font-size: %spx;\n\
        color: white;\n\
    }\n", lStyle->app_font_family, lStyle->app_font_size);

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
    
    printf("\
    form {\n\
        display: inline-block;\n\
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
    /* body */
    printf("\
    .body {\n\
        background-color: %s;\n\
        padding: 10px;\n\
        min-height: 300px;\n\
        border-radius: 5px;\n\
        text-align: center;\n\
        overflow: auto;\n\
    }\n", lStyle->app_light_color);
    //===============================================
    /* body2 */
    printf("\
    .body2 {\n\
        border: 1px solid %s;\n\
        padding: 0px 0px 5px 0px;\n\
        min-height: 300px;\n\
        border-radius: 5px;\n\
        text-align: center;\n\
        overflow: auto;\n\
    }\n", lStyle->app_light_color);
    //===============================================
    /* bottom */
    printf("\
    .bottom {\n\
        margin-bottom: 5px;\n\
    }\n");
    //===============================================
    /* box */
    printf("\
    .box {\n\
        background-color: %s;\n\
        padding: 10px;\n\
        text-align: left;\n\
        max-width: 600px;\n\
        margin: auto;\n\
        margin-top: 50px;\n\
        border-radius: 5px;\n\
    }\n", lStyle->app_bg_color);
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
    /* button2 */
    printf("\
    .button2 {\n\
        background-color: #101030;\n\
    }\n");
    //===============================================    
    /* button3 */
    printf("\
    .button3 {\n\
        background-color: %s;\n\
        display: inline-block;\n\
        border-radius: 5px;\n\
        padding: 5px 10px;\n\
        font-family: %s;\n\
        font-size: %spx;\n\
    }\n", lStyle->app_light_color, lStyle->app_font_family, lStyle->app_font_size);
    //===============================================
    /* center */
    printf("\
    .center {\n\
        text-align: center;\n\
    }\n");
    //===============================================
    /* content */
    printf("\
    .content {\n\
        position: relative;\n\
        min-height: 32px;\n\
    }\n");
    //===============================================
    /* content2 */
    printf("\
    .content2 {\n\
        display: none;\n\
        background-color: #301010;\n\
        border: 2px solid #603030;\n\
        border-radius: 5px;\n\
        position: absolute;\n\
        min-width: 250px;\n\
        padding: 5px;\n\
        z-index: 1;\n\
    }\n");
    //===============================================
    /* header */
    printf("\
    .header {\n\
        position: relative;\n\
        margin-bottom: 10px;\n\
    }\n");
    //===============================================
    /* header2 */
    printf("\
    .header2 {\n\
        border-bottom: 1px solid %s;\n\
        padding: 10px;\n\
        margin-bottom: 5px;\n\
    }\n", lStyle->app_light_color);
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
    /* img */
    printf("\
    .img {\n\
        border: 2px solid transparent;\n\
        display: inline-block;\n\
        width: 100px;\n\
        height: auto;\n\
        border-radius: 5px;\n\
        margin: 5px;\n\
    }\n");
    
    printf("\
    .img:hover {\n\
        border: 2px solid orange;\n\
    }\n");
    //===============================================
    /* img2 */
    printf("\
    .img2 {\n\
        display: inline-block;\n\
        width: 100px;\n\
        height: auto;\n\
        border-radius: 5px;\n\
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
    /* item2 */
    printf("\
    .item2 {\n\
        display: block;\n\
        padding: 5px 10px;\n\
        border-radius: 5px;\n\
        width: 100%%;\n\
        text-align: left;\n\
    }\n");

    printf("\
    .item2:hover {\n\
        background-color: #503030;\n\
    }\n");
    //===============================================
    /* item3 */
    printf("\
    .item3 {\n\
        margin: 20px 0px;\n\
    }\n");
    //===============================================
    /* item4 */
    printf("\
    .item4 {\n\
        background-color: %s;\n\
        border: 1px solid %s;\n\
        display: inline-block;\n\
        margin-right: 5px;\n\
        padding: 5px;\n\
        border-radius: 5px 10px;\n\
    }\n", lStyle->app_light_color, lStyle->app_light_color);
    //===============================================
    /* left */
    printf("\
    .left {\n\
        text-align: left;\n\
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
    /* menu */
    printf("\
    .menu {\n\
        position: relative;\n\
        display: inline-block;\n\
    }\n");
        
    printf("\
    .menu:hover .button {\n\
        background-color: #603030;\n\
    }\n");
        
    printf("\
    .menu:hover .content2 {\n\
        display: block;\n\
    }\n");
    //===============================================
    /* right */
    printf("\
    .right {\n\
        text-align: right;\n\
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
    printf("\
    .title2 {\n\
        position: absolute;\n\
        top: 0px;\n\
        bottom: 0px;\n\
        right: 0px;\n\
        left: 120px;\n\
        padding-top: 5px;\n\
        text-align: center;\n\
    }\n");
    //===============================================
    /* titlebar */
    printf("\
    .titlebar {\n\
        border-bottom: 5px solid %s;\n\
        padding-bottom: 5px;\n\
    }\n", lStyle->app_light_color);
    //===============================================
    /* window */
    printf("\
    .window {\n\
        border: 1px solid #aaaaaa;\n\
        border-radius: 5px;\n\
        padding: 10px;\n\
        overflow: hidden;\n\
        overflow-x: auto;\n\
    }\n");
    //===============================================
}
//===============================================
