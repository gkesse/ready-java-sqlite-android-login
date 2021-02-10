//===============================================
// struct
//===============================================
function sGManager() {
    this.app = null;
}
//===============================================
function sGApp() {
    // app
    this.app_name = null;
    // view
    this.view_timer = null;
}
//===============================================
// manager
//===============================================
var GManager = (function() {
    //===============================================
    var m_instance;
    //===============================================
    var mgr;
    //===============================================
    var Container = function() {
        return {
            //===============================================
            init: function() {
                this.construct();
                this.setTime();
            },
            //===============================================
            construct: function() {
                // manager
                this.mgr = new sGManager();
                // app
                this.mgr.app = new sGApp();
                this.mgr.app.app_name = "ReadyApp";
            },
            //===============================================
            // request
            //===============================================
            run: function(obj, req) {
                // select_file
                if(req == "select_file_page_change") {this.select_file_page_change(obj, req); return;}
            },
            //===============================================
            select_file_page_change: function(obj, req) {
                var lForm = document.getElementById("select_file_page_form");
                lForm.submit();
            },
            //===============================================
            // view
            //===============================================
            setTime: function() {
                var lApp = GManager.Instance().mgr.app;
                this.countTime();
                lApp.view_timer = setInterval(this.countTime, 1000);
            },
            //===============================================
            countTime: function() {
                var lViewDate = document.getElementById("view_date");
                var lViewTime = document.getElementById("view_time");
                var lDate = new Date();
                var lDay = lDate.getDate();
                var lMonth = lDate.getMonth() + 1;
                var lYear = lDate.getFullYear();
                lDay = (lDay < 10) ? "0" + lDay : lDay;
                lMonth = (lMonth < 10) ? "0" + lMonth : lMonth;
                var lDateFormat = lDay + "/" + lMonth + "/" + lYear;
                lViewDate.innerHTML = lDateFormat;
                lViewTime.innerHTML = lDate.toLocaleTimeString();
            }
            //===============================================
        };
    }
    //===============================================
    return {
        Instance: function() {
            if(!m_instance) {
                m_instance = Container();
            }
            return m_instance;
        }
    };
    //===============================================
})();
//===============================================
GManager.Instance().init();
//===============================================
