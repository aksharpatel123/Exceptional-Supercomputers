#include "mainwin.h"
#include "entrydialog.h"
#include <iomanip>
#include <fstream>
//#include <string>
#include <sstream>

Mainwin::Mainwin() : store{nullptr} {

    // ** G U I   S E T U P **

    set_default_size(600, 500);
    set_title("ELSA");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*menubar);

    //     ** F I L E **
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //     F I L E  >  N E W
    // Append New to the File menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New Store", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_store_click();});
    filemenu->append(*menuitem_new);


    //     F I L E  >  SAVE
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_save);

    //     F I L E  >  SAVE AS
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_save_as = Gtk::manage(new Gtk::MenuItem("_SaveAs", true));
    menuitem_save_as->signal_activate().connect([this] {this->on_save_as_click();});
    filemenu->append(*menuitem_save_as);

    //     F I L E  >  OPEN
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect([this] {this->on_open_click();});
    filemenu->append(*menuitem_open);

    //     F I L E  >  Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);


    //     ** H E L P **
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //      H E L P  > DATABASE
    Gtk::MenuItem *menuitem_data = Gtk::manage(new Gtk::MenuItem("_Show Data", true));
    menuitem_data->signal_activate().connect([this] {this->on_data_click();});
    helpmenu->append(*menuitem_data);

    //      H E L P  >  A B O U T
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);

    //     ** V I E W **
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);

    //     V I E W > Customer
    Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menuitem_customer->signal_activate().connect([this] {this->on_view_customer_click();});
    viewmenu->append(*menuitem_customer);

        //     V I E W > Peripheral
    Gtk::MenuItem *menuitem_peripheral = Gtk::manage(new Gtk::MenuItem("_Peripheral", true));
    menuitem_peripheral->signal_activate().connect([this] {this->on_view_peripheral_click();});
    viewmenu->append(*menuitem_peripheral);

        //     V I E W > Desktop
    Gtk::MenuItem *menuitem_desktop = Gtk::manage(new Gtk::MenuItem("_Desktop", true));
    menuitem_desktop->signal_activate().connect([this] {this->on_view_desktop_click();});
    viewmenu->append(*menuitem_desktop);

        //     V I E W > Order
    Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menuitem_order->signal_activate().connect([this] {this->on_view_order_click();});
    viewmenu->append(*menuitem_order);



    //     ** I N S E R T **
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);

    //     I N S E R T > Customer
    Gtk::MenuItem *menuitem_Inscustomer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menuitem_Inscustomer->signal_activate().connect([this] {this->on_insert_customer_click();});
    insertmenu->append(*menuitem_Inscustomer);

        //     I N S E R T > Peripheral
    Gtk::MenuItem *menuitem_Insperipheral = Gtk::manage(new Gtk::MenuItem("_Peripheral", true));
    menuitem_Insperipheral->signal_activate().connect([this] {this->on_insert_peripheral_click();});
    insertmenu->append(*menuitem_Insperipheral);

        //     I N S E R T > Peripheral > RAM
    Gtk::MenuItem *menuitem_Insperipheral_ram = Gtk::manage(new Gtk::MenuItem("_RAM", true));
    menuitem_Insperipheral_ram->signal_activate().connect([this] {this->on_insert_peripheral_click();});
    insertmenu->menuitem_Insperipheral->append(*menuitem_Insperipheral_ram);

        //     I N S E R T > Peripheral > Cancel
    Gtk::MenuItem *menuitem_Insperipheral_cancel = Gtk::manage(new Gtk::MenuItem("_Cancel", true));
    menuitem_Insperipheral_cancel->signal_activate().connect([this] {this->on_quit_click();});
    insertmenu->menuitem_Insperipheral_cancel->append(*menuitem_Insperipheral_cancel);

        //     I N S E R T > Desktop
    Gtk::MenuItem *menuitem_Insdesktop = Gtk::manage(new Gtk::MenuItem("_Desktop", true));
    menuitem_Insdesktop->signal_activate().connect([this] {this->on_insert_desktop_click();});
    insertmenu->append(*menuitem_Insdesktop);

        //     I N S E R T > Order
    Gtk::MenuItem *menuitem_Insorder = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menuitem_Insorder->signal_activate().connect([this] {this->on_insert_order_click();});
    insertmenu->append(*menuitem_Insorder);


    // D I S P L A Y	D A T A  
    data = Gtk::manage(new Gtk::Label{"", Gtk::ALIGN_START, Gtk::ALIGN_START});
    data->set_hexpand(); 

    Gtk::EventBox *eb = Gtk::manage(new Gtk::EventBox);
    eb->set_hexpand();
    eb->override_background_color(Gdk::RGBA("white"));
    eb->add(*data);

    vbox->pack_start(*eb, Gtk::PACK_EXPAND_WIDGET, 0);

    msg = Gtk::manage(new Gtk::Label);
    msg->set_hexpand();

    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);

    // Make the box and everything in it visible
    vbox->show_all();

    on_new_store_click();
}

Mainwin::~Mainwin() { }


// C A L L B A C K S

void Mainwin::on_new_store_click() {
    delete store;
    store = new Store;
    filename = "untitled.elsa";
    set_data("");
    set_msg("New store has been created!!");
}

void Mainwin::on_open_click() {
    
    Gtk::FileChooserDialog dialog("Please choose a file",
    Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    auto filter_elsa = Gtk::FileFilter::create();
    filter_elsa->set_name("ELSA files");
    filter_elsa->add_pattern("*.elsa");
    dialog.add_filter(filter_elsa);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename(filename);

    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Open", 1);

    int result = dialog.run();

    if (result == 1) {
        try {
            delete store;
            store = nullptr;
            filename = dialog.get_filename();
            std::ifstream ifs{filename};
            store = new Store{ifs};
            
            if(!ifs) throw std::runtime_error{"Bad File Contents"};
            on_view_customer_click();
            set_msg("Loaded " + filename);
        } 
        catch (std::exception& e) {
            std::string err = "Unable to open " + filename + " (" + e.what() + " )";
            on_new_store_click();
            set_msg("<b>ERROR:</b>: " + err);
            Gtk::MessageDialog{*this, err, false, Gtk::MESSAGE_WARNING}.run();
        }
    }
}


void Mainwin::on_save_click() {
    
    try {
            std::ofstream ofs{filename};
            store->save(ofs);
            if(!ofs) throw std::runtime_error{"Error writing file"};
            set_msg(filename + " is Saved!!");
    } catch(std::exception& e) {
            std::string err = "Unable to save store to " + filename;
            set_msg("<b>ERROR:</b> " + err);
            Gtk::MessageDialog{*this, err, false, Gtk::MESSAGE_WARNING}.run();
    }

}


void Mainwin::on_save_as_click() {
    Gtk::FileChooserDialog dialog("Please choose a file",
    Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);

    auto filter_elsa = Gtk::FileFilter::create();
    filter_elsa->set_name("ELSA files");
    filter_elsa->add_pattern("*.elsa");
    dialog.add_filter(filter_elsa);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename(filename);

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Save", 1);

    int result = dialog.run();

    if (result == 1) {
        filename = dialog.get_filename();
        on_save_click();
    }
}


void Mainwin::on_quit_click() {
    close();
}

void Mainwin::on_view_peripheral_click() {
	std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    oss << "<big><b>Peripherals</b></big><tt>\n\n";

    for(int i=0; i<store->num_options(); ++i) 
         oss << i << ") " << store->option(i) << "\n";

    oss<<"</tt>";
    set_data(oss.str());
    set_msg("");
}

void Mainwin::on_view_desktop_click() {
	std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    oss << "<big><b>Products</b></big><tt>\n\n";

    for(int i=0; i<store->num_desktops(); ++i) 
        oss << i << ") " << store->desktop(i) << "\n";

    oss<<"</tt>";
    set_data(oss.str());
    set_msg("");
}

void Mainwin::on_view_order_click() {
	std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    oss << "<big><b>Orders</b></big><tt>\n\n";

    for(int i=0; i<store->num_orders(); ++i) 
        oss << i << ") " << store->order(i) << "\n";

    oss<<"</tt>";
    set_data(oss.str());
    set_msg("");
}
        
void Mainwin::on_view_customer_click() {
	std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    oss << "<big><b>Customers</b></big><tt>\n\n";

    for(int i=0; i<store->num_customers(); ++i) {
        oss << i << ") " << store->customer(i) << "\n";
    }
    
    oss<<"</tt>";
    set_data(oss.str()); 
    set_msg("");
}
        
void Mainwin::on_insert_peripheral_click() {
	std::string str_peripheral = get_string("Enter new peripheral name: ");

	double cost;
	cost = get_double("Enter Peripheral Cost:");
    
    Options option{str_peripheral, cost};
    store->add_option(option);

    on_view_peripheral_click();
    set_msg("Peripheral has been added! " + str_peripheral);
}
        
void Mainwin::on_insert_desktop_click() {
	on_view_peripheral_click();
    int desktop = store->new_desktop();
    while(true) {
    	std::ostringstream oss;
        oss << store->desktop(desktop) << "\n\nYou may add peripheral (-1 when done)?";

        int option = get_int(oss.str());;
        //std::cin >> option; std::cin.ignore(32767, '\n');
        if(option == -1) break;
        try {
            store->add_option(option, desktop);
        } 
        catch(std::exception& e) {
            Gtk::MessageDialog{*this, "#### INVALID OPTION ####\n\n"}.run();
        }
    }
    on_view_desktop_click();
    set_msg("Added desktop " + std::to_string(desktop));
}
        
void Mainwin::on_insert_order_click() {
    int customer, order;
    on_view_customer_click();

    customer = get_int("Enter Customer");
    if(customer == -1) return;

    order = store->new_order(customer);
    on_view_desktop_click();
    while(true) {
        int desktop = get_int("Desktop (-1 when done)?");

        if(desktop == -1) break;
        store->add_desktop(desktop, order);
    }

    on_view_order_click();
    set_msg("Added order " + std::to_string(order) + " for $" + std::to_string(store->order(order).price()));

}
        
void Mainwin::on_insert_customer_click() {

    Gtk::Dialog dialog{"Insert Customer", *this};
    Gtk::Grid grid;

    Gtk::Label lbl_name{"Name"};
    Gtk::Entry etr_name;
    grid.attach(lbl_name, 0, 0, 1, 1);
    grid.attach(etr_name, 1, 0, 2, 1);

    Gtk::Label ph_num{"Phone"};
    Gtk::Entry etr_num;
    grid.attach(ph_num, 0, 1, 1, 1);
    grid.attach(etr_num, 1, 1, 2, 1);

    Gtk::Label e_mail{"Email"};
    Gtk::Entry email_entry;
    grid.attach(e_mail, 0, 2, 1, 1);
    grid.attach(email_entry, 1, 2, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Insert", 1);
    dialog.add_button("Cancel", 0);

    int r;

    dialog.show_all();

    while((r = dialog.run()) == 1) {
        if (etr_name.get_text().size() == 0) {
            etr_name.set_text("*req-field*");
            continue;
        }
        if (etr_num.get_text().size() != 12) {
            etr_num.set_text("*req-field*");
            continue;
        }
        if (email_entry.get_text().size() == 0) {
            email_entry.set_text("*req-field*");
            continue;
        }
        break;
    }

    try {
        std::string name = etr_name.get_active_text();

        std::string phone = etr_num.get_active_text();
        
        std::string email = email_entry.get_active_text();

        Customer customer{name, phone, email};
        store->add_customer(customer);
    }
    catch (std::exception& e) {
        Gtk::MessageDialog{*this, "#### INVALID OPTION ####\n\n"}.run();
    }
    
    on_view_customer_click();
    set_msg("Added customer " + name);
}

void Mainwin::on_data_click() {
    Customer c{"Amy Fire", "817-AJJ-HOOO", "am@jc.fdo"};          store->add_customer(c);
    c = Customer{"Superman", "817-UIU-TECH", "sup@man.hero"}; store->add_customer(c);
    c = Customer{"Pro Dome", "817-PRO-8989", "pro@fun.domo"};     store->add_customer(c);
    c = Customer{"Alex", "817-ALE-XYXY", "king@alex.rule"};            store->add_customer(c);

    Options o{"CPU: 2.6 GHz Liio 2128G", 889.85};         store->add_option(o);
    o = Options{"CPU: 2.4 MHz Core i9-5563M", 90.80};      store->add_option(o);
    o = Options{"CPU: 2.2 GHz WBN Opteron", 567.11};        store->add_option(o);
    o = Options{"CPU: 300 MHz MM3351KPCEA30R ARM", 109.83}; store->add_option(o);
    o = Options{"CPU: 240 GHz SUPDOOP LCA7", 99.00};      store->add_option(o);
    o = Options{"1 GB RAM", 12.06};                        store->add_option(o);
    o = Options{"2 GB RAM", 29.05};                        store->add_option(o);
    o = Options{"2 GB RAM", 94.09};                        store->add_option(o);
    o = Options{"8 GB RAM", 122.90};                       store->add_option(o);
    o = Options{"64 GB RAM", 184.66};                      store->add_option(o);
    o = Options{"64 GB RAM", 411.99};                      store->add_option(o);
    o = Options{"0.5 TB SSD", 39.99};                      store->add_option(o);
    o = Options{"1 TB SSD", 149.99};                       store->add_option(o);
    o = Options{"4 TB SSD", 249.99};                       store->add_option(o);
    o = Options{"4 TB SSD", 549.99};                       store->add_option(o);
    o = Options{"2 TB RAW Disk", 49.99};                    store->add_option(o);
    o = Options{"2 TB Floppy Disk", 89.99};                store->add_option(o);
    o = Options{"4 TB Optical Disk", 99.99};                store->add_option(o);

    int desktop = store->new_desktop();
    store->add_option(0, desktop);
    store->add_option(6, desktop);
    store->add_option(16, desktop);
    desktop = store->new_desktop();
    store->add_option(1, desktop);
    store->add_option(5, desktop);
    store->add_option(14, desktop);
    desktop = store->new_desktop();
    store->add_option(3, desktop);
    store->add_option(9, desktop);
    store->add_option(17, desktop);
}




void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name("Elsa");

    dialog.set_version("Version 1.2.3");
    dialog.set_copyright("Copyright 2019-2020");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"Akshar Patel"};
    dialog.set_authors(authors);
    
    dialog.run();
    set_msg("");
}


std::string Mainwin::get_string(std::string prompt) {
    EntryDialog edialog{*this, prompt};
    //edialog.set_text(prompt);
    edialog.run();

    return edialog.get_text();
}

double Mainwin::get_double(std::string prompt) {
    double val = 0.0;
    try{
        val = std::stod(get_string(prompt));
    }
    catch (std::exception& e){
        return (-1.0);
    }

    return val;
}


int Mainwin::get_int(std::string prompt) {
    int v = 0;
    try{
        v = std::stoi(get_string(prompt));
    }
    catch (std::exception& e){
        return (-1);
    }

    return v;
}

void Mainwin::set_data(std::string s) {
    data->set_markup(s);
}

void Mainwin::set_msg(std::string s) {
    msg->set_markup(s);
}

