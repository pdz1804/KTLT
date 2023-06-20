#include "knight2.h"

// DEFINE METHODS
// -------------------------------------------------------------
bool checkPrime(int n) {
    int i = 1;
    int so_uoc = 0;
    if (n == 1) {
        return false;
    }
    for (i; i <= n; i++) {
        if (n % i == 0) {
            so_uoc += 1;
        }
        if (so_uoc > 2) {
            break;
        }
    }
    if (so_uoc == 2) {
        return true;
    }
    else {
        return false;
    }
}
// -------------------------------------------------------------
bool checkPytagoTriple(int n) {
    if (n == 101 || n == 110) {
        return false;
    }
    else if ((n == 345) || (n == 354)) {
        return true;
    }
    else if ((n == 435) || (n == 453)) {
        return true;
    }
    else if ((n == 534) || (n == 543)) {
        return true;
    }
    else {
        return false;
    }
}
// -------------------------------------------------------------
KnightType classifyKnightType(int maxhp) {
    if (checkPrime(maxhp)) {
        return PALADIN;
    }
    else if (maxhp == 888) {
        return LANCELOT;
    }
    else if (checkPytagoTriple(maxhp)) {
        return DRAGON;
    }
    else {
        return NORMAL;
    }
}
// -------------------------------------------------------------
// END DEFINE METHODS
// -------------------------------------------------------------
// DEFINE CLASSES
// -------------------------------------------------------------
// CLASS EVENTS
// define the constructor of class Events
Events::Events(const string& file_events) {
    ifstream ifs;
    ifs.open(file_events);
    ifs >> num_event;
    arr_of_event = new int[num_event];
    for (int i = 0; i < num_event; i++) {
        ifs >> arr_of_event[i];
    }
    ifs.close();
}

// constructor cua class Events, luc cuoi cung chung ta se goi no 
Events::~Events() {
    // cout << "Start the destructor of class Event" << endl;
    delete[] get_pointer_arr_event();
    // cout << "End the destructor of class Event" << endl;
};

int Events::count() const {
    return num_event;
};

// get number of event 
int Events::get_num_event() {
    return num_event;
}

// get arr_of_event[i]
int Events::get_event_index_i(int i) const {
    if (i < 0 || i >= num_event) {
        return -99999999;
    }
    else {
        return arr_of_event[i];
    }
}; 

// END CLASS EVENTS
// -------------------------------------------------------------
// CLASS BASEKNIGHT
// -------------------------------------------------------------
BaseKnight* BaseKnight::create (int id , int maxhp , int level , int gil , int antidote , int phoenixdownI) {
    Knight_Count++;
    KnightType checktype = classifyKnightType(maxhp);
    BaseKnight* new_obj = nullptr;
    if (checktype == 0) {
        new_obj = new PaladinKnight(0.06, PALADIN);
        new_obj->bag = new PaladinBag(new_obj, antidote, phoenixdownI);
    }
    else if (checktype == 1) {
        new_obj = new LancelotKnight(0.05, LANCELOT);
        new_obj->bag = new LancelotBag(new_obj, antidote, phoenixdownI);
    }
    else if (checktype == 2) {
        new_obj = new DragonKnight(0.075, DRAGON);
        new_obj->bag = new DragonBag(new_obj, antidote, phoenixdownI);
    }
    else {
        new_obj = new NormalKnight(0, NORMAL);
        new_obj->bag = new NormalBag(new_obj, antidote, phoenixdownI);
    }

    new_obj->id =id;
    new_obj->hp = maxhp;
    new_obj->maxhp = maxhp;
    new_obj->level = level;
    new_obj->gil = gil;
    new_obj->antidote = antidote;
    new_obj->phoenixdownI = phoenixdownI;
    if (new_obj->phoenixdownI > 0) {
        for (int i = 0; i < new_obj->phoenixdownI; i++) {
            PhoenixDownI* new_item = new PhoenixDownI();
            if (new_obj->bag->insertFirst(new_item)) {
                new_obj->bag->insert_index(0, new_item);
            }
            else { 
                break;
            }
        }
    }
    if ((new_obj->antidote > 0) && (new_obj->getKnightType() != DRAGON)) {
        for (int i = 0; i < new_obj->antidote; i++) {
            Antidote* new_new = new Antidote();
            BaseItem* new_item = new_new;
            if (new_obj->bag->insertFirst(new_item)) {
                new_obj->bag->insert_index(0, new_item);
            }
            else { 
                break;
            }
        }
    }
    return new_obj;
}
// -------------------------------------------------------------
int BaseKnight::Knight_Count = 0;
// -------------------------------------------------------------
PaladinKnight::PaladinKnight(double dam, KnightType type) {
    setKnightType(type);
    set_knightbasedamage(dam);
}

LancelotKnight::LancelotKnight(double dam, KnightType type) {
    setKnightType(type);
    set_knightbasedamage(dam);
}

DragonKnight::DragonKnight(double dam, KnightType type) {
    setKnightType(type);
    set_knightbasedamage(dam);
}

NormalKnight::NormalKnight(double dam, KnightType type) {
    setKnightType(type);
    set_knightbasedamage(dam);
}

// -------------------------------------------------------------
string BaseKnight::toString() const {
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    string s("");
    s += "[Knight:id:" + to_string(id) 
        + ",hp:" + to_string(hp) 
        + ",maxhp:" + to_string(maxhp)
        + ",level:" + to_string(level)
        + ",gil:" + to_string(gil) + ","
        + bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
}
// -------------------------------------------------------------
// END BASEKNIGHT
// -------------------------------------------------------------
// CLASS OPPONENT
void BaseOpponent::set_OppName(string name) {
    OppName = name;
}
void BaseOpponent::set_order_of_event(int order) {
    order_of_event = order;
}
void BaseOpponent::set_event_id(int id) {
    event_id = id;
}
void BaseOpponent::set_gils(int Gils) {
    gils = Gils;
}
void BaseOpponent::set_base_damage(int dam) {
    basedamage = dam;
}

string BaseOpponent::get_Oppname() {
    return OppName;
}
int BaseOpponent::get_order_of_event() {
    return order_of_event;
}
int BaseOpponent::get_base_damage() {
    return basedamage;
}
int BaseOpponent::get_event_id() {
    return event_id;
}
int BaseOpponent::get_gils() {
    return gils;
}
int BaseOpponent::get_levelO() {
    return levelO;
}
void BaseOpponent::calculate_Opponent_Level() {
    levelO = (order_of_event + event_id)%10 + 1;
}

MadBear::MadBear(int order, int basedam = 10, int id = 1, int gils = 100, string name = "MadBear") {
    set_order_of_event(order);
    set_base_damage(basedam);
    set_event_id(id);
    set_gils(gils);
    set_OppName(name);
};

Bandit::Bandit(int order, int basedam = 15, int id = 2, int gils = 150, string name = "Bandit") {
    set_order_of_event(order);
    set_base_damage(basedam);
    set_event_id(id);
    set_gils(gils);
    set_OppName(name);
}

LordLupin::LordLupin(int order, int basedam = 45, int id = 3, int gils = 450, string name = "LordLupin") {
    set_order_of_event(order);
    set_base_damage(basedam);
    set_event_id(id);
    set_gils(gils);
    set_OppName(name);
}

Elf::Elf(int order, int basedam = 75, int id = 4, int gils = 750, string name = "Elf") {
    set_order_of_event(order);
    set_base_damage(basedam);
    set_event_id(id);
    set_gils(gils);
    set_OppName(name);
}

Troll::Troll(int order, int basedam = 95, int id = 5, int gils = 800, string name = "Troll") {
    set_order_of_event(order);
    set_base_damage(basedam);
    set_event_id(id);
    set_gils(gils);
    set_OppName(name);
}

Tornbery::Tornbery(int order, int id = 6, string name = "Tornbery") {
    set_order_of_event(order);
    set_event_id(id);
    set_OppName(name);
}

QueenOfCards::QueenOfCards(int order, int id = 7, string name = "Queen Of Cards") {
    set_order_of_event(order);
    set_event_id(id);
    set_OppName(name);
}

NinaDeRings::NinaDeRings(int order, int id = 8, string name = "Nina De Rings") {
    set_order_of_event(order);
    set_event_id(id);
    set_OppName(name);
}

void NinaDeRings::trade(BaseKnight* knight) {
    if (knight->get_gil() < 50) {
        return;
    }
    else {
        int hpchia3 = (knight->get_maxhp())/3;
        if (knight->get_hp() < hpchia3) {
            knight->set_gil(knight->get_gil() - 50);
            int hpadd = (knight->get_maxhp())/5;
            knight->set_hp(knight->get_hp() + hpadd);
        }
        else { return; }
    }
} 

DurianGarden::DurianGarden(int order, int id = 9, string name = "Durian Garden") {
    set_order_of_event(order);
    set_event_id(id);
    set_OppName(name);
}

void DurianGarden::HoiMaxHP(BaseKnight* knight) {
    knight->set_hp(knight->get_maxhp());
}

OmegaWeapon::OmegaWeapon(int order, int id = 10, string name = "Omega Weapon") {
    set_order_of_event(order);
    set_event_id(id);
    set_OppName(name);
}

Hades::Hades(int order, int id = 11, string name = "Hades") {
    set_order_of_event(order);
    set_event_id(id);
    set_OppName(name);
}

// -------------------------------------------------------------
// CLASS BASEITEM - mới declare basic của item
// During events, after the fight and HP giảm, Knight sẽ kiem trong 
// bag ra his first usable phoenixtears và sử dụng
void BaseItem::set_type(ItemType Type) { type = Type; }  

ItemType BaseItem::get_type() { return type; }

BaseItem::BaseItem()
{
    next = NULL;
}

bool BaseItem::canUse(BaseKnight* knight) { return true; }
void BaseItem::use (BaseKnight * knight) {};

Antidote::Antidote() { 
    set_type(ANTIDOTE); 
    next = NULL;
};

bool Antidote::canUse(BaseKnight* knight) {
    if (knight->get_antidote() > 0) {
        return true;
    }
    else {
        return false;
    }
}

void Antidote::use(BaseKnight* knight) {
    knight->set_antidote(knight->get_antidote()-1);
}

// -------------------------------------------------------------
PhoenixDownI::PhoenixDownI() { 
    set_type(PHOENIXI); 
    next = NULL;
};

bool PhoenixDownI::canUse(BaseKnight* knight) {
    if (knight->get_hp() <= 0) {
        return true;
    }
    else {
        return false;
    }
}

void PhoenixDownI::use(BaseKnight* knight) {
    knight->set_phoenixdownI(knight->get_phoenixdownI()-1);
    knight->set_hp(knight->get_maxhp());
}

// -------------------------------------------------------------
PhoenixDownII::PhoenixDownII() { 
    set_type(PHOENIXII); 
    next = NULL;
};

bool PhoenixDownII::canUse(BaseKnight* knight) {
    if (knight->get_hp() < ((knight->get_maxhp())/4)) {
        return true;
    }
    else {
        return false;
    }
}

void PhoenixDownII::use(BaseKnight* knight) {
    knight->set_hp(knight->get_maxhp());
    knight->set_phoenixdownII(knight->get_phoenixdownII()-1);
}

// -------------------------------------------------------------
PhoenixDownIII::PhoenixDownIII() { 
    set_type(PHOENIXIII); 
    next = NULL;
};

bool PhoenixDownIII::canUse(BaseKnight* knight) {
    if (knight->get_hp() < ((knight->get_maxhp())/3)) {
        return true;
    }
    else {
        return false;
    }
}

void PhoenixDownIII::use(BaseKnight* knight) {
    if (knight->get_hp() <= 0) {
        knight->set_hp((knight->get_maxhp())/3);
    }
    else {
        int add_hp = (knight->get_maxhp())/4;
        knight->set_hp(knight->get_hp() + add_hp);
    }
    knight->set_phoenixdownIII(knight->get_phoenixdownIII()-1);
}

// -------------------------------------------------------------
PhoenixDownIV::PhoenixDownIV() { 
    set_type(PHOENIXIV); 
    next = NULL;
};

bool PhoenixDownIV::canUse(BaseKnight* knight) {
    if (knight->get_hp() < ((knight->get_maxhp())/2)) {
        return true;
    }
    else {
        return false;
    }
}

void PhoenixDownIV::use(BaseKnight* knight) {
    if (knight->get_hp() <= 0) {
        knight->set_hp((knight->get_maxhp())/2);
    }
    else {
        int add_hp = (knight->get_maxhp())/5;
        knight->set_hp(knight->get_hp() + add_hp);
    }
    knight->set_phoenixdownIV(knight->get_phoenixdownIV()-1);
}

// END CLASS BASEITEM
// -------------------------------------------------------------
// CLASS BASEBAG
BaseBag::BaseBag() {
    head = NULL;
}

// CLASS CON CUA BASEBAG
PaladinBag::PaladinBag(BaseKnight* knight, int Anti, int Phoenix) {
    initialAnti = Anti;
    initialPhoenix = Phoenix;
    KnightType checktype = knight->getKnightType();
    if (checktype == 0) {
        setMaxItem(1024);
    }
    else if (checktype == 1) {
        setMaxItem(16);
    }
    else if (checktype == 2) {
        setMaxItem(14);
    }
    else {
        setMaxItem(19);
    }
}

LancelotBag::LancelotBag(BaseKnight* knight, int Anti, int Phoenix) {
    initialAnti = Anti;
    initialPhoenix = Phoenix;
    KnightType checktype = knight->getKnightType();
    if (checktype == 0) {
        setMaxItem(1024);
    }
    else if (checktype == 1) {
        setMaxItem(16);
    }
    else if (checktype == 2) {
        setMaxItem(14);
    }
    else {
        setMaxItem(19);
    }
}

DragonBag::DragonBag(BaseKnight* knight, int Anti, int Phoenix) {
    initialAnti = Anti;
    initialPhoenix = Phoenix;
    KnightType checktype = knight->getKnightType();
    if (checktype == 0) {
        setMaxItem(1024);
    }
    else if (checktype == 1) {
        setMaxItem(16);
    }
    else if (checktype == 2) {
        setMaxItem(14);
    }
    else {
        setMaxItem(19);
    }
}

NormalBag::NormalBag(BaseKnight* knight, int Anti, int Phoenix) {
    initialAnti = Anti;
    initialPhoenix = Phoenix;
    KnightType checktype = knight->getKnightType();
    if (checktype == 0) {
        setMaxItem(1024);
    }
    else if (checktype == 1) {
        setMaxItem(16);
    }
    else if (checktype == 2) {
        setMaxItem(14);
    }
    else {
        setMaxItem(19);
    }
}

// Set max item of bag
void BaseBag::setMaxItem(int len) {
    max_item = len;
}

// Getter of max item
int BaseBag::getMaxItem() {
    return max_item;
}

// Function to print the length of linked list
int BaseBag::printLength() const {
    BaseItem* temp = head;
    int Len = 0;
    if (temp == NULL) {
        return 0;
    }
    else {
        while (temp != NULL) {
            temp = temp->next;
            Len++;
        }
        return Len;
    }
}

// Function to delete the node at given position
void BaseBag::deleteNode(int index_delete)
{
	BaseItem *temp1 = head, *temp2 = NULL;
	int ListLen = 0;

	if (head == NULL) {
		return; // get out of the function and not return anything
	}

	// Find length of the linked-list.
	while (temp1 != NULL) {
		temp1 = temp1->next; 
		ListLen++;
	}
	// Check if the position to be deleted is greater than the length of the linked list.
	if (ListLen <= index_delete) {
		cout << "Index out of range" << endl;
		return;
	}

	// (Re)Declare temp1
	temp1 = head;

	// Deleting the head.
	if (index_delete == 0) {
		// Update head
		head = head->next;
		delete temp1;
		return;
	}

	// Traverse the list to find the node to be deleted.
	while (index_delete-- > 0) {
		// Update temp2
		temp2 = temp1;

		// Update temp1
		temp1 = temp1->next;
	}

	// Change the next pointer of the previous node.
	temp2->next = temp1->next; // pointer của thg trc thg bị xóa -> point to the obj of thg phía sau thg bị xóa

	// Delete the node
	delete temp1;
}

// Function to insert a new node to any position (index) in the linked list
void BaseBag::insert_index(int index, BaseItem* newdata) {
    BaseItem* temp = head;
    BaseItem* temp2 = NULL;
    

    // check if empty
    if (temp == NULL) {
        head = newdata;
        return;
    }
    
    // find the length of the linked List
    int LenList = 1;
    while (temp->next != NULL) { // check pointer "next" of object temp if NULL
        LenList++;
        temp = temp->next;
    }

    // Redeclare temp
    temp = head; // temp đang là head, index 0 
    
    // check if the index is "possible"
    if (index > LenList || index < 0) {
        cout << "Out of range" << endl;
    }
    else {
        int indexList = 0;
        if (index == 0) {
            head = newdata;
            head->next = temp;
            return;
        }
        do {
            temp2 = temp;
            temp = temp->next;
            indexList++;
        } while (indexList != index);
        newdata->next = temp;
        temp2->next = newdata;
    }
}

// Function to swap Node 
void BaseBag::swapNode(int a, int b) { // a < b
    BaseItem* temp4 = head; // chua node tai index b+1
    BaseItem* temp5 = nullptr; // chua node tai index b
    BaseItem* temp6 = nullptr; // chua node tai index b-1
    BaseItem* temp1 = head; // chua node tai index a+1
    BaseItem* temp2 = nullptr; // chua node tai index a
    BaseItem* temp3 = nullptr; // chua node tai index a-1
    // find the length of the linked List
    int LenList = 1;
    while (temp1->next != NULL) { // check pointer "next" of object temp if NULL
        LenList++;
        temp1 = temp1->next;
    }
    temp1 = head; // redeclare temp1 = head

    if (a >= LenList || b >= LenList) {
        cout << "out of range" << endl;
        return;
    }
    if (LenList == 1) { cout << "Cannot swap" << endl; return; }
    if (LenList == 2) { 
        temp2 = temp1;
        temp1 = temp1->next;
        temp1->next = temp2;
        temp2->next = nullptr;
        head = temp1;
        return;
    }
    int index1 = 0;
    int index2 = 0;
    while (index1 <= a) {
        temp3 = temp2;
        temp2 = temp1;
        temp1 = temp1->next;
        index1++;
    }
    while (index2 <= b) {
        temp6 = temp5;
        temp5 = temp4;
        temp4 = temp4->next;
        index2++;
    }

    BaseItem* change1 = nullptr;
    BaseItem* change2 = nullptr;
    if (temp5->get_type() == 0) {
        Antidote* anti = new Antidote();
        change1 = anti;
    }
    else if (temp5->get_type() == 1) {
        PhoenixDownI* phoe1 = new PhoenixDownI();
        change1 = phoe1;
    }
    else if (temp5->get_type() == 2) {
        PhoenixDownII* phoe2 = new PhoenixDownII();
        change1 = phoe2;
    }
    else if (temp5->get_type() == 3) {
        PhoenixDownIII* phoe3 = new PhoenixDownIII();
        change1 = phoe3;
    }
    else {
        PhoenixDownIV* phoe4 = new PhoenixDownIV();
        change1 = phoe4;
    }

    if (temp2->get_type() == 0) {
        Antidote* anti = new Antidote();
        change2 = anti;
    }
    else if (temp2->get_type() == 1) {
        PhoenixDownI* phoe1 = new PhoenixDownI();
        change2 = phoe1;
    }
    else if (temp2->get_type() == 2) {
        PhoenixDownII* phoe2 = new PhoenixDownII();
        change2 = phoe2;
    }
    else if (temp2->get_type() == 3) {
        PhoenixDownIII* phoe3 = new PhoenixDownIII();
        change2 = phoe3;
    }
    else {
        PhoenixDownIV* phoe4 = new PhoenixDownIV();
        change2 = phoe4;
    }
    
    insert_index(a, change1);
    insert_index(b+1, change2);
    deleteNode(b+2);
    deleteNode(a+1);
    // Node* temp4 = head; // chua node tai index b+1
    // Node* temp5 = nullptr; // chua node tai index b
    // Node* temp6 = nullptr; // chua node tai index b-1
    // Node* temp1 = head; // chua node tai index a+1
    // Node* temp2 = nullptr; // chua node tai index a
    // Node* temp3 = nullptr; // chua node tai index a-1
}

// Function to return boolen if/if not able to insert item
bool BaseBag::insertFirst(BaseItem * item) {
    if (printLength() < max_item) { return true; }
    else { return false; }
}

// Lấy first item mà same type, xong roi swap len vi tri dau
BaseItem* BaseBag::get(ItemType itemType) 
{ 
    int index = 0;
    BaseItem* newitem = head;

    while ((newitem->get_type() != itemType) && (index < printLength())) {
        newitem = newitem->next;
        index++;
    }

    if (newitem == head) { return newitem; }
    else { swapNode(0, index); newitem = head; }
    return newitem;
};

// In ra thông tin trong bag của hiệp sĩ
string BaseBag::toString() const {
    string out_put = "";
    if (printLength() == 0) {
        out_put += "Bag[count=0;]";
    }
    else {
        out_put = out_put + "Bag[count=" + to_string(printLength()) + ";";
        BaseItem* temp = nullptr;
        temp = head;
        for (int i = 0; (i < printLength()) && (temp != nullptr); i++) {
            if (temp->get_type() == 0) {
                out_put += "Antidote";
            }
            else if (temp->get_type() == 1) {
                out_put += "PhoenixI";
            }
            else if (temp->get_type() == 2) {
                out_put += "PhoenixII";
            }
            else if (temp->get_type() == 3) {
                out_put += "PhoenixIII";
            }
            else {
                out_put += "PhoenixIV";
            }

            if (i != printLength()-1) {
                out_put += ",";
            }
            else {
                out_put += "]";
            }
            temp = temp->next;
        }
    }
    return out_put;
};

// END CLASS BASEBAG
// -------------------------------------------------------------
// -------------------------------------------------------------
// CLASS ARMYKNIGHT
// Constructor of ArmyKnight
ArmyKnights::ArmyKnights(const string& file_armyknights) {
    int HP, Level, PhoenixdownI, Gil, ANtidote;
    ifstream ifs;
    ifs.open(file_armyknights);
    ifs >> num_Army;
    arr_of_Knights = new BaseKnight*[num_Army];
    for (int i = 0; i < num_Army; i++) { 
        ifs >> HP >> Level >> PhoenixdownI >> Gil >> ANtidote;

        // Tạo hiệp sĩ, trong create tự specify knightType

        arr_of_Knights[i] = BaseKnight::create(i+1, HP, Level, Gil, ANtidote, PhoenixdownI);

        // Sau khi lấy input từ file army, xét xem phải DRAGON kh, nếu phải thì truyền antidote cho thg trước nó
        // Không truyền anti đầu vào của dragon cho knight trc nó
        if (arr_of_Knights[i]->getKnightType() == DRAGON) {
            arr_of_Knights[i]->set_antidote(0);
        }
    }
    ifs.close();
}

// Destructor of ArmyKnight
// - Trong từng Knight: Xóa items, xong xóa bag, xong xóa Knight
// - Khi xóa hết knight, xóa arr_of_knight

// Destructor BaseKnight
BaseKnight::~BaseKnight(){
    delete this->bag;
}

// Destructor BaseBag
BaseBag::~BaseBag(){
    BaseItem* temp = this->head;
    while (temp != NULL) {
        BaseItem* temp1 = temp->next;
        delete temp;
        temp = temp1;
    }
    this->head = nullptr;
}

ArmyKnights::~ArmyKnights() {
    int numknight = get_Num_Army();
    for (int i = 0; i < numknight; i++) {
        delete this->arr_of_Knights[i];
    }
    delete[] this->arr_of_Knights;
};

int ArmyKnights::get_Num_Army() {
    return num_Army;
}

BaseKnight* ArmyKnights::get_pointer_knight(int i) {
    return arr_of_Knights[i];
}

// Method fight của ArmyKnight: 1 Knight đánh 1 Opponent
// - Chỉ xét thắng/hòa và thua, nghĩa là chỉ 2 TH: level >= levelO hay level < levelO
// - Khi hiệp sĩ đánh, xong hi sinh (nghĩa là hp <= 0), dùng thuốc để hồi sinh đc, thì cho đánh sự kiện típ theo luôn
// - Trong 1 lượt dùng thuốc (hay check appropriatePhoenix) thì chỉ dùng đc 1 thuốc
bool ArmyKnights::fight(BaseOpponent* opponent) {
    opponent->calculate_Opponent_Level();
    int levelO = opponent->get_levelO();
    int event_id = opponent->get_event_id();

    BaseKnight* knight = lastKnight();
    int level = knight->get_level();

    if ((event_id == 1) || (event_id == 2) || (event_id == 3) || (event_id == 4) || (event_id == 5)) {
        if ((knight->getKnightType() == LANCELOT) || (knight->getKnightType() == PALADIN)) {
            knight->set_gil(knight->get_gil() + opponent->get_gils());
            checkGils(knight);
            return true;
        }
        else if (level >= levelO) {
            knight->set_gil(knight->get_gil() + opponent->get_gils());
            checkGils(knight);
            return true;
        }
        else {
            int damage = opponent->get_base_damage()*(levelO - level);
            int newhp = knight->get_hp() - damage;
            knight->set_hp(newhp);
            if (knight->get_hp() <= 0) {
                appropriatePhoenix(knight);
                if (knight->get_hp() > 0) {
                    return true;
                }
                else {
                    if (knight->get_gil() >= 100) {
                        knight->set_gil(knight->get_gil()-100);
                        int newhp = (knight->get_maxhp())/2;
                        knight->set_hp(newhp);
                        return true;
                    }
                    else {
                        return false;
                    }
                }
            }
            else { 
                appropriatePhoenix(knight);
                return true; 
            }
        }
    }
    else if (event_id == 6) {
        if (level >= levelO) {
            if (level + 1 >= 10) {
                knight->set_level(10);
            }
            else {
                knight->set_level(level + 1);
            }
            return true;
        }
        else {
            if (knight->getKnightType() == DRAGON) {
                return true;
            }
            else if (knight->get_antidote() == 0) {
                BaseBag* bag = knight->getBag();
                int numItem = bag->printLength();
                if (numItem <= 3) {
                    for (int i = 0; i < numItem; i++) {
                        bag->deleteNode(0);
                    }
                    bag = NULL;
                }
                else {
                    bag->deleteNode(0);
                    bag->deleteNode(0);
                    bag->deleteNode(0);
                }
                int newhp = knight->get_hp() - 10;
                knight->set_hp(newhp);
                if (knight->get_hp() <= 0) {
                    appropriatePhoenix(knight);
                    if (knight->get_hp() > 0) {
                        return true;
                    }
                    else {
                        if (knight->get_gil() >= 100) {
                            knight->set_gil(knight->get_gil()-100);
                            int newhp = (knight->get_maxhp())/2;
                            knight->set_hp(newhp);
                            return true;
                        }
                        else {
                            return false;
                        }
                    }
                }
                else { 
                    appropriatePhoenix(knight);
                    return true; 
                }                                   
            }
            else {
                // khi antidote > 0, cần dùng hàm swap antidote với head để use
                BaseItem* usedItem = knight->getBag()->get(ANTIDOTE);
                usedItem->use(knight);
                knight->getBag()->deleteNode(0);
                return true;
            }
        }
    }
    else if (event_id == 7) {
        if (level >= levelO) {
            int newgil = (knight->get_gil())*2;
            knight->set_gil(newgil);
            checkGils(knight);
            return true;
        }
        else {
            if (knight->getKnightType() == PALADIN) {
                return true;
            }
            else {
                int newgil = (knight->get_gil())/2;
                knight->set_gil(newgil);
                return true;
            }
        }
    }
    else if (event_id == 8) {
        if ((knight->get_gil() < 50) && (knight->getKnightType() != PALADIN)) { return true; }
        else {
            int hpchia3 = (knight->get_maxhp())/3;
            if (knight->get_hp() < hpchia3) {
                if (knight->getKnightType() != PALADIN) {
                    int newgil = knight->get_gil() - 50;
                    knight->set_gil(newgil);
                }
                int addHP = knight->get_maxhp()/5;
                knight->set_hp(knight->get_hp() + addHP);
                return true;
            }
            else {
                return true;
            }
        }
    }
    else if (event_id == 9) {
        knight->set_hp(knight->get_maxhp());
        return true;
    }
    // Omega Weapon
    else if (event_id == 10) {
        bool a1 = (knight->get_level() == 10) && (knight->get_hp() == knight->get_maxhp());
        bool a2 = (knight->getKnightType() == DRAGON);
        if (a1 || a2) {
            knight->set_level(10);
            knight->set_gil(999);
            metOmega = true;
            return true;
        }
        else {
            knight->set_hp(0);
            appropriatePhoenix(knight);
            if (knight->get_hp() > 0) {
                return true;
            }
            else {
                if (knight->get_gil() >= 100) {
                    knight->set_gil(knight->get_gil()-100);
                    int newhp = (knight->get_maxhp())/2;
                    knight->set_hp(newhp);
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }
    // Hades
    else if (event_id == 11) {
        bool a1 = (knight->get_level() == 10);
        bool a2 = ((knight->getKnightType() == PALADIN) && (knight->get_level() >= 8));
        if (a1 || a2) {
            metHades = true;
            getShield = true;
            return true;
        }
        else {
            knight->set_hp(0);
            appropriatePhoenix(knight);
            if (knight->get_hp() > 0) {
                return true;
            }
            else {
                if (knight->get_gil() >= 100) {
                    knight->set_gil(knight->get_gil()-100);
                    int newhp = (knight->get_maxhp())/2;
                    knight->set_hp(newhp);
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }
    else {
        cout << "Here just for event 1 to 11" << endl;
        return false;
    }
    return true;
}

int ArmyKnights::count() const {
    int a = 0;
    for (int i = 0; i < num_Army; i++) {
        if (arr_of_Knights[i]->get_hp() > 0) {
            a++;
        }
        else {
            continue;
        }
    }
    return a;
}

BaseKnight* ArmyKnights::lastKnight() const {
    BaseKnight* _return = nullptr;
    for (int i = num_Army-1; i >= 0; i--) {
        if ((i == 0) && (arr_of_Knights[i]->get_hp() <= 0)) {
            _return = NULL;
        }
        if (arr_of_Knights[i]->get_hp() > 0) {
            _return = arr_of_Knights[i];
            break;
        }
    }
    return _return;
}

bool ArmyKnights::hasPaladinShield() const {
    if (getShield == false) { return false; }
    else { return true; }
}

bool ArmyKnights::hasGuinevereHair() const {
    if (getHair == false) { return false; }
    else { return true; }
}

bool ArmyKnights::hasLancelotSpear() const {
    if (getSpear == false) { return false; }
    else { return true; }
}

bool ArmyKnights::has3treasure() const {
    if ((getShield == true) && (getHair == true) && (getSpear == true)) { return true; }
    else { return false; }
}

bool ArmyKnights::hasExcaliburSword() const {
    if (getExcalibur == false) { return false; }
    else { return true; }
}

void ArmyKnights::appropriatePhoenix(BaseKnight* knight) {
    BaseBag* bag = knight->getBag();
    BaseItem* temp = bag->gethead();
    int index = 0;
    if (temp == nullptr) { return; }
    while ((temp != nullptr) && !((temp->canUse(knight)) && (temp->get_type() != ANTIDOTE))) {
        temp = temp->next;
        index++;
    } 

    if (temp != nullptr) {
        if (index != 0) {
            bag->swapNode(0, index);
        }
        temp = bag->gethead();

        temp->use(knight); // trong ham use da -1 thuoc roi
        bag->deleteNode(0);
    }
    else { 
        return; 
    }
}

void ArmyKnights::checkGils(BaseKnight* knight) {
    if (knight->get_gil() > 999) {
        int gil_extra = knight->get_gil() - 999;
        knight->set_gil(999);
        if (count() == 1) { return; }
        int index = count() - 2; // index knight kế last knight
        while ((gil_extra > 0) && (index >= 0)) {
            BaseKnight* knight_check = get_pointer_knight(index); 
            int gil = knight_check->get_gil();
            if (gil + gil_extra <= 999) {
                knight_check->set_gil(gil + gil_extra);
                break;
            }
            else {
                knight_check->set_gil(999);
                gil_extra = (gil + gil_extra) - 999;
            }
            index--;
        }
    }
    else {
        return;
    }
}

void ArmyKnights::checkItem(BaseKnight* knight, BaseItem* item) {
    ItemType type = item->get_type();
    BaseBag* bag = knight->getBag();
    BaseKnight* knight_check = nullptr;
    if (bag->printLength() <  bag->getMaxItem()) {
        if (type == PHOENIXII) {
            int numPhoe2 = knight->get_phoenixdownII() + 1;
            knight->set_phoenixdownII(numPhoe2);
        }
        if (type == PHOENIXIII) {
            int numPhoe3 = knight->get_phoenixdownIII() + 1;
            knight->set_phoenixdownIII(numPhoe3);
        }
        if (type == PHOENIXIV) {
            int numPhoe4 = knight->get_phoenixdownIV() + 1;
            knight->set_phoenixdownIV(numPhoe4);
        }
        bag->insert_index(0, item);
    }
    else {
        int index = count()-1; // index luc nay la index cua lastknight
        for (int i = index-1; i >= 0; i--) {
            knight_check = get_pointer_knight(i);
            BaseBag* bag_check = knight_check->getBag();
            if (bag_check->printLength() <  bag_check->getMaxItem()) {
                if (type == PHOENIXII) {
                    int numPhoe2 = knight_check->get_phoenixdownII() + 1;
                    knight_check->set_phoenixdownII(numPhoe2);
                }
                if (type == PHOENIXIII) {
                    int numPhoe3 = knight_check->get_phoenixdownIII() + 1;
                    knight_check->set_phoenixdownIII(numPhoe3);
                }
                if (type == PHOENIXIV) {
                    int numPhoe4 = knight_check->get_phoenixdownIV() + 1;
                    knight_check->set_phoenixdownIV(numPhoe4);
                }
                bag_check->insert_index(0, item);
                break;
            }
        }
    }
}

// Method adventure class ArmyKnight, trả xem win hay thua Ultimecia
// - Cứ mỗi event code (1 -> 11) thì gọi opponent tương ứng ra, quăng vào fight cho 1 knight đánh, nếu knight chết thì gọi knight kế
// - Khi đánh Ulti, không có Sword, có 3 treasures, từng knight khác NORMAL đánh, NORMAL vẫn còn đó chưa chết
// đến cuối nếu Ulti chết thì currentKnight vẫn còn NORMAL, nếu Ulti kh chết thì NORMAL chết tất -> currentKnight = 0
bool ArmyKnights::adventure(Events* events) {
    getShield = 0; getSpear = 0; getHair = 0; getExcalibur = 0;
    win_99 = false; metOmega = false; metHades = false;
    int current_knight = count();
    BaseKnight* knight = lastKnight();

    for (int i = 0; i < events->get_num_event(); i++) {
        int eventcode = events->get_event_index_i(i);

        if (eventcode == 1) {
            MadBear* newopp = new MadBear(i);
            bool result = fight(newopp);
            if (result) { printInfo(); }
            else {
                knight = lastKnight();
                printInfo();
            }
            delete newopp;
        }
        else if (eventcode == 2) {
            Bandit* newopp = new Bandit(i);
            bool result = fight(newopp);
            if (result) { printInfo(); }
            else {
                knight = lastKnight();
                printInfo();
            }
            delete newopp;
        }
        else if (eventcode == 3) {
            LordLupin* newopp = new LordLupin(i);
            bool result = fight(newopp);
            if (result) { printInfo(); }
            else {
                knight = lastKnight();
                printInfo();
            }
            delete newopp;
        }
        else if (eventcode == 4) {
            Elf* newopp = new Elf(i);
            bool result = fight(newopp);
            if (result) { printInfo(); }
            else {
                knight = lastKnight();
                printInfo();
            }
            delete newopp;
        }
        else if (eventcode == 5) {
            Troll* newopp = new Troll(i);
            bool result = fight(newopp);
            if (result) { printInfo(); }
            else {
                knight = lastKnight();
                printInfo();
            }
            delete newopp;
        }
        else if (eventcode == 6) {
            Tornbery* newopp = new Tornbery(i);
            bool result = fight(newopp);
            if (result) { printInfo(); }
            else {
                printInfo();
            }
            delete newopp;
        }
        else if (eventcode == 7) {
            QueenOfCards* newopp = new QueenOfCards(i);
            bool result = fight(newopp);
            printInfo();
            delete newopp;
        }
        else if (eventcode == 8) {
            NinaDeRings* newopp = new NinaDeRings(i);
            bool result = fight(newopp);
            printInfo();
            delete newopp;
        }
        else if (eventcode == 9) {
            DurianGarden* newopp = new DurianGarden(i);
            bool result = fight(newopp);
            printInfo();
            delete newopp;
        }
        else if (eventcode == 10) {
            if (metOmega) { 
                printInfo();
            }
            else {
                OmegaWeapon* newopp = new OmegaWeapon(i);
                bool result = fight(newopp);
                if (result) { 
                    // cout << "aa" << endl;
                    printInfo(); 
                }
                else {
                    knight = lastKnight();
                    printInfo();
                }
                delete newopp;
            }
            // OmegaWeapon* newopp = new OmegaWeapon(i);
            // bool result = fight(newopp);
            // if (result) { 
            //     printInfo(); 
            // }
            // else {
            //     knight = lastKnight();
            //     // while (!result && (knight != NULL)) {
            //     //     current_knight--;
            //     //     knight = lastKnight();
            //     //     result = fight(newopp);
            //     // }
            //     // cout << "Het knight cmnr" << endl;
            //     printInfo();
            // }
            // delete newopp;
        }
        else if (eventcode == 11) {
            if (metHades) { 
                printInfo();
            }
            else {
                Hades* newopp = new Hades(i);
                bool result = fight(newopp);
                if (result) { printInfo(); }
                else {
                    knight = lastKnight();
                    printInfo();
                }
                delete newopp;
            }
        }
        else if (eventcode == 112) {
            PhoenixDownII* newitem = new PhoenixDownII;
            BaseItem* newobj = newitem;
            BaseKnight* knight = lastKnight();
            checkItem(knight, newobj);
            printInfo();
        }
        else if (eventcode == 113) {
            PhoenixDownIII* newitem = new PhoenixDownIII;
            BaseItem* newobj = newitem;
            BaseKnight* knight = lastKnight();
            checkItem(knight, newobj);
            printInfo();
        }
        else if (eventcode == 114) {
            PhoenixDownIV* newitem = new PhoenixDownIV;
            BaseItem* newobj = newitem;
            BaseKnight* knight = lastKnight();
            checkItem(knight, newobj);
            printInfo();
        }
        else if (eventcode == 95) {
            if (getShield) { 
                printInfo();
            }
            else {
                getShield = true;
                printInfo();
            }
        }
        else if (eventcode == 96) {
            if (getSpear) { 
                printInfo();
            }
            else {
                getSpear = true;
                printInfo();
            }
        }
        else if (eventcode == 97) {
            if (getHair) { 
                printInfo();
            }
            else {
                getHair = true;
                printInfo();
            }
        }
        else if (eventcode == 98) {
            if (getExcalibur) { 
                printInfo();
            }
            else if (has3treasure()) { 
                getExcalibur = true; 
                printInfo();
            }
            else {
                printInfo();
            }
        }
        // ULTIMECIA
        else {
            int hpUltimecia = 5000;
            if (hasExcaliburSword()) { 
                win_99 = true; 
            }
            else if (!(hasExcaliburSword() && (has3treasure()))) {
                int index_last = count() - 1; // index last knight
                for (int i = index_last; i >= 0; i--) {
                    BaseKnight* knight = get_pointer_knight(i);
                    KnightType type = knight->getKnightType();
                    if (type == NORMAL) { 
                        continue; 
                    }

                    int damageKnight = (knight->get_hp())*(knight->get_level())*(knight->get_knightbasedamage());
                    hpUltimecia -= damageKnight;
                    if (hpUltimecia <= 0) {
                        win_99 = true;
                        break;
                    }
                    else {
                        knight->set_hp(0);
                    }
                }
                // Neu danh xong het ma hpUlti > 0, set het hp cua cac army = 0
                if (hpUltimecia > 0) {
                    for (int i = index_last; i >= 0; i--) {
                        BaseKnight* knight = get_pointer_knight(i);
                        knight->set_hp(0);
                    }
                    win_99 = false;
                }
            }
            else {
                int index_last = count() - 1; // index last knight
                for (int i = index_last; i >= 0; i--) {
                    BaseKnight* knight = get_pointer_knight(i);
                    knight->set_hp(0);
                }
                win_99 = false;
                printInfo();
                break;
            }
            printInfo();
        }

        // NẾU ĐANG ĐÁNH GIỮA CHỪNG KNIGHT HẾT THÌ RETURN FALSE
        if (count() == 0) {
            break;
        }
    }
    return win_99;
}

// -------------------------------------------------------------
void ArmyKnights::printInfo() const { // Chữ const -> chỉ gọi sử dụng chứ hong được thay đổi thuộc tính class
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight * lknight = lastKnight();
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << "--------------------------------------------------" << endl;
}
// -------------------------------------------------------------
void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}
// -------------------------------------------------------------
// END CLASS ARMYKNIGHT
// -------------------------------------------------------------
// CLASS KNIGHTADVENTURE
// Constructor KnightAdventure
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}

// Destructor KnightAdventure
// - chỉ delete armyknights và events thôi, tự destructor của ArmyKnights và Events đã xóa các dynamic elements của nó
KnightAdventure::~KnightAdventure() {
    delete armyKnights;
    delete events;
}

// Chứa thông tin về các events của class Events
void KnightAdventure::loadEvents(const string& event_file) {
    events = new Events(event_file);
}

// Chứa thông tin về các Knights của class ArmyKnights
void KnightAdventure::loadArmyKnights(const string& army_knight_file) {
    armyKnights = new ArmyKnights(army_knight_file);
}

// Chạy hàm adventure của ArmyKnights cho nó đánh các quái (cả Ulti)
// Xong rồi chạy hàm printResult của ArmyKnights xem có thắng Ulti hay không
void KnightAdventure::run() {
    // TEST ADVENTURE - ARMYKNIGHTS
    bool phudepzai = armyKnights->adventure(events);
    armyKnights->printResult(phudepzai);
}

// END CLASS ADVENTURE
// -------------------------------------------------------------
// END DEFINE CLASSES
// -------------------------------------------------------------