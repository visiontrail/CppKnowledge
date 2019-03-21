#include <stdlib.h>
#include <iostream>
#include "CallBackInterface.h"
#include "NotifyInterface.h"
#include "MO.h"

using namespace std;

/*
 * 作用：回调函数的发起者
*/
class Boss
{
  private:
    CallBackInterface secretary1;
    NotifyInterface secretary2;
    /*
     * 作用：BOSS接收回调函数之后的处理
    */
    static bool StratgyA(void *param)
    {
        oam_subsysa_cellconfig *recv_para = (oam_subsysa_cellconfig *)param;

        cout << "Boss do something receive employee msg: " << endl;
        cout << "cell ID is" << recv_para->cell_id << " NR PCI is " << recv_para->nr_pci << endl;
        cout << "prts_enable " << recv_para->prts_enable << endl;
        cout << "tag_mcc1 is " << recv_para->tag_mcc1 << " tag_mcc2 is " << recv_para->tag_mcc2 << endl;
    }

  public:
    Boss(/* args */);
    ~Boss();

    void do_work_a()
    {
        secretary1.GetVal_ByMOCode(OAM_SUBSYSA_GETXXX, 0, StratgyA);
        secretary2.SetNotify_ByMOCode(OAM_SUBSYSA_GETXXX, StratgyA);
    }
};

Boss::Boss(/* args */)
{
}

Boss::~Boss()
{
}

int main(int argc, char const *argv[])
{
    Boss boss;
    boss.do_work_a();
    cout << "Boss Waiting for report" << endl;
    while(1){
        /* code */
    }
    
}
