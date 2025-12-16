#include <gtkmm.h>

class Win : public Gtk::Window {
public:
    Win() {
        set_default_size(400,300);
        set_title("window");

        button.set_label("click me");
        button.signal_clicked().connect([this](){
            button.set_label("CLicked!");
        });

        set_child(button);

    }

private:
    Gtk::Button button;
};

int main(int argc, char** argv){
    auto app = Gtk::Application::create("com.example.app");
    return app->make_window_and_run<Win>(argc, argv);
}