#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG
// -------------------------------------------------------------
bool checkPrime(int);
bool checkPytagoTriple(int);
// end define methods
// -------------------------------------------------------------
// define class and enum type
enum KnightType {
    PALADIN = 0, // BY DEFAULT, THIS HAS VALUE 0
    LANCELOT = 1, // 1
    DRAGON = 2, // 2
    NORMAL = 3 // 3
};
// -------------------------------------------------------------
enum ItemType {
    ANTIDOTE = 0,
    PHOENIXI = 1,
    PHOENIXII = 2,
    PHOENIXIII = 3,
    PHOENIXIV = 4
};
// -------------------------------------------------------------
class BaseItem;

class BaseBag { // base bag implement như linked list
private:
    BaseItem* head;
public:
    int initialAnti;
    int initialPhoenix;
    int max_item;
    // Default constructor
	BaseBag();

    // Destructor
    ~BaseBag();

    void setMaxItem(int len);
    int getMaxItem();

    BaseItem* gethead() { return head; }

    // Length of the linked list
    int printLength() const;
	
	// Function to insert a node at any position in the linked list 
	void insert_index(int, BaseItem*);

	// Function to delete the node at given position
	void deleteNode(int);

    void swapNode(int, int);

    virtual bool insertFirst(BaseItem * item);
    virtual BaseItem * get(ItemType itemType);
    virtual string toString() const;
};

// -------------------------------------------------------------
class BaseOpponent;
// -------------------------------------------------------------
class BaseKnight {
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    int antidote; 
    int phoenixdownI; // thêm vào
    int phoenixdownII;
    int phoenixdownIII;
    int phoenixdownIV;
    double knightBaseDamage;
    BaseBag* bag;
    KnightType knightType;
public:
    ~BaseKnight();

    static int Knight_Count; // thêm vào

    // Methods
    static BaseKnight* create (int id , int maxhp , int level , int gil , int antidote , int phoenixdownI);
    
    // hong thấy trong đề, nhưng có trong initial code
    string toString() const;
    
    // GET, CALCULTE MEMBER OF THE CLASS
    int get_id() { return id;}
    int get_hp() { return hp;}
    int get_maxhp() { return maxhp;}
    int get_level() { return level;}
    int get_gil() { return gil; }
    int get_antidote() { return antidote; }
    int get_phoenixdownI() { return phoenixdownI; }
    int get_phoenixdownII() { return phoenixdownII; }
    int get_phoenixdownIII() { return phoenixdownIII; }
    int get_phoenixdownIV() { return phoenixdownIV; }
    double get_knightbasedamage() { return knightBaseDamage; }
    KnightType getKnightType() { return knightType; }
    BaseBag* getBag() { return bag; }

    void set_id(int Id) { id = Id; }
    void set_hp(int Hp) { hp = Hp;}
    void set_level(int Level) { level = Level;}
    void set_gil(int Gil) { gil = Gil;}
    void set_antidote(int Antidote) { antidote = Antidote;}
    void set_phoenixdownI(int PhoenixdownI) { phoenixdownI = PhoenixdownI;}
    void set_phoenixdownII(int PhoenixdownII) { phoenixdownII = PhoenixdownII;}
    void set_phoenixdownIII(int PhoenixdownIII) { phoenixdownIII = PhoenixdownIII;}
    void set_phoenixdownIV(int PhoenixdownIV) { phoenixdownIV = PhoenixdownIV;}
    void set_knightbasedamage(double dam) { knightBaseDamage = dam; }
    void setKnightType(KnightType type) { knightType = type; }
    
    // END GET, CALCULATE MEMBER OF THE CLASS
};

class PaladinKnight:public BaseKnight {
public:
    PaladinKnight(double, KnightType);
};

class LancelotKnight:public BaseKnight {
public:
    LancelotKnight(double, KnightType);
};

class DragonKnight:public BaseKnight {
public:
    DragonKnight(double, KnightType);

};

class NormalKnight:public BaseKnight {
public:
    NormalKnight(double, KnightType);
};

// -------------------------------------------------------------
class Events {
private:
    int num_event;
    int* arr_of_event;
public:
    // Constructor, destructor
    Events(const string& file_events);
    ~Events();

    // Methods
    // get num_event
    int count() const;
    // get number of event 
    int get_num_event();
    // get arr_of_event[i]
    int get_event_index_i(int i) const; 
    // get pointer at index i
    int* get_pointer_arr_event() { return arr_of_event; }
};
// -------------------------------------------------------------
class ArmyKnights {
private:
    BaseKnight** arr_of_Knights;
    int num_Army;
public:
    bool getShield;
    bool getSpear;
    bool getHair;
    bool getExcalibur;
    bool win_99;
    bool metOmega;
    bool metHades;

    // Constructor, destructor
    ArmyKnights(const string& file_armyknights);
    ~ArmyKnights();

    // Methods
    // khi hp <= 0
    void hp_leq_0(BaseKnight*);

    // check push gils
    void checkGils(BaseKnight*);

    // check push items
    void checkItem(BaseKnight*, BaseItem*);

    // khi hp giảm thì tìm thg phoenix phù hợp nhất
    void appropriatePhoenix(BaseKnight*);

    // -get number of army
    int get_Num_Army();

    // -get army at index i
    BaseKnight* get_pointer_knight(int);

    // -get pointer to the arr_knight
    BaseKnight** get_arr_knight() { return arr_of_Knights; }

    // -how a knight engage an opponent -> update to Knight
    virtual bool fight (BaseOpponent * opponent);

    // -holds event in the journey
    bool adventure(Events * events);

    // -current number of knights
    int count() const;

    // -pointer -> the last knight of the army
    BaseKnight* lastKnight() const;

    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool has3treasure() const;
    bool hasExcaliburSword() const;

    // These 2 in the KnightAdventure, we will use
    // -print information after each event
    void printInfo() const;

    // -print after the last event, if defeat Ultimecia or not
    void printResult(bool win) const;
};
// -------------------------------------------------------------
class BaseOpponent {
private:
    string OppName;
    int order_of_event;
    int basedamage;
    int event_id;
    int gils;
    int levelO;
public:
    // METHODS
    void set_OppName(string name);
    void set_order_of_event(int order);
    void set_event_id(int id);
    void set_gils(int Gils) ;
    void set_base_damage(int dam);

    string get_Oppname();
    int get_order_of_event();
    int get_levelO();
    int get_base_damage();
    int get_event_id();
    int get_gils();

    void calculate_Opponent_Level();
};
// -------------------------------------------------------------
class MadBear:public BaseOpponent{
public:
    MadBear(int order, int basedamage, int id, int gils, string name);
};
// -------------------------------------------------------------
class Bandit:public BaseOpponent{ 
public:
    Bandit(int order, int basedamage, int id, int gils, string name);
};
// -------------------------------------------------------------
class LordLupin:public BaseOpponent{  
public:
    LordLupin(int order, int basedamage, int id, int gils, string name);
};
// -------------------------------------------------------------
class Elf:public BaseOpponent {
public:
    Elf(int order, int basedamage, int id, int gils, string name);
};
// -------------------------------------------------------------
class Troll:public BaseOpponent{ 
public:
    Troll(int order, int basedamage, int id, int gils, string name);
};
// -------------------------------------------------------------
class Tornbery:public BaseOpponent{
private:
    bool poisoned;
public:
    Tornbery(int order, int id, string name);
    bool getPoisoned() { return poisoned; }
    void setPoisoned(bool poison) { poisoned = poison; }
};
// -------------------------------------------------------------
class QueenOfCards:public BaseOpponent{
public:
    QueenOfCards(int order, int id, string name);
};
// -------------------------------------------------------------
class NinaDeRings:public BaseOpponent{
public:
    NinaDeRings(int order, int id, string name);
    void trade(BaseKnight* knight);
};
// -------------------------------------------------------------
class DurianGarden:public BaseOpponent{
public:
    DurianGarden(int order, int id, string name);
    void HoiMaxHP(BaseKnight* knight);
};
// -------------------------------------------------------------
class OmegaWeapon:public BaseOpponent{
public:
    OmegaWeapon(int order, int id, string name);
};
// -------------------------------------------------------------
class Hades:public BaseOpponent{
public:
    Hades(int order, int id, string name);
};
// -------------------------------------------------------------
// base item implement như node
class BaseItem {
private:
    ItemType type;
public: 
    void set_type(ItemType Type);  
    ItemType get_type();

    // int data;
    BaseItem* next;

    // Default constructor
	BaseItem();

    virtual bool canUse ( BaseKnight * knight ) = 0;
    virtual void use ( BaseKnight * knight ) = 0;
};

class Antidote : public BaseItem {
public:
    Antidote();
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};

class PhoenixDownI : public BaseItem {
public:
    PhoenixDownI();
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};

class PhoenixDownII : public BaseItem {
public:
    PhoenixDownII();
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};

class PhoenixDownIII : public BaseItem {
public:
    PhoenixDownIII();
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};

class PhoenixDownIV : public BaseItem {
public:
    PhoenixDownIV();
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};

// -------------------------------------------------------------
class PaladinBag:public BaseBag {
public:
    PaladinBag(BaseKnight*, int, int);
};

class LancelotBag:public BaseBag {
public:
    LancelotBag(BaseKnight*, int, int);
};

class DragonBag:public BaseBag {
public:
    DragonBag(BaseKnight*, int, int);
};

class NormalBag:public BaseBag {
public:
    NormalBag(BaseKnight*, int, int);
};

// -------------------------------------------------------------
class KnightAdventure {
private:
    ArmyKnights* armyKnights;
    Events* events;
public:
    KnightAdventure();
    ~KnightAdventure();

    // load file
    void loadArmyKnights(const string &);

    // load event
    void loadEvents(const string &);

    // run the program, print Info after each event, print result after last event
    void run();
};
// -------------------------------------------------------------
#endif // __KNIGHT2_H__