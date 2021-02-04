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
        font-family: allan;\n\
        font-size: %spx;\n\
        text-align: left;\n\
    }\n", lStyle->app_bg_color, lStyle->app_font_size);

    printf("\
    button {\n\
        background-color: transparent;\n\
        border: none;\n\
        padding: 5px 10px 5px 5px;\n\
        font-size: 16px;\n\
        color: white;\n\
        cursor: pointer;\n\
    }\n");

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
    /* html_page */
    printf("\
    .html_page {\n\
        background-color: red;\n\
        padding: 10px;\n\
    }\n");
    //===============================================
    /* listbox */
    printf("\
    .listbox {\n\
        border: 1px solid #ffffff;\n\
    }\n");
    printf("\
    .listbox .item {\n\
        padding: 5px 10px;\n\
        cursor: pointer;\n\
    }\n");
    printf("\
    .listbox .item:hover {\n\
        background-color: #503030;\n\
    }\n");
    printf("\
    .listbox .item:active {\n\
        background-color: transparent;\n\
    }\n");
    //===============================================
    // table
    printf("\
    .table_id {\n\
        display: inline-block;\n\
        padding: 10px;\n\
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
}
//===============================================
