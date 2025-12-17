#include <gtkmm.h>
#include "callbacks.h"

int winH = 600;
int winW = 1000;

class Win : public Gtk::Window {
public:
    Win() {
        set_default_size(winW,winH);
        set_title("RSS Feed");

        set_child(root);

        sidebar.set_size_request(220, -1);
        sidebar.set_hexpand(false);

        root.append(sidebar);

        main_area.set_hexpand(true);
        root.append(main_area);

        auto settings_button = Gtk::make_managed<Gtk::Button>("Settings");
        settings_button->set_margin_top(winH);
        sidebar.append(*settings_button);



        //--------adding CSS styling for the window----------

        //giving classes to objects
        sidebar.add_css_class("sidebar");

        //initiating the file
        auto css = Gtk::CssProvider::create();
        css->load_from_path("resources/style.css");
        
        //adding the CSS provider for the display
        Gtk::StyleContext::add_provider_for_display(
            get_display(),
            css,
            GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
        );

        //signals for buttons pressing
        settings_button->signal_clicked().connect(sigc::ptr_fun(&on_settings_clicked));
    }

private:
    Gtk::Box root{Gtk::Orientation::HORIZONTAL};

    Gtk::Box sidebar{Gtk::Orientation::VERTICAL};
    Gtk::Box main_area{Gtk::Orientation::VERTICAL};
        
};

int main(int argc, char** argv){
    auto app = Gtk::Application::create("com.example.app");
    return app->make_window_and_run<Win>(argc, argv);
}