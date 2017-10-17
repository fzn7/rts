#include <iostream>
#include "CollisionHandler.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    CollisionQuery ColQ;
    ColQ.AnyHit();
    ColQ.EgressHit();
    ColQ.GetEgressPos();
    ColQ.GetEgressPosDist(0.5, 0.5);
    ColQ.GetHitPiece();
    ColQ.GetHitPos();
    ColQ.GetHitPosDist(0.5, 0.5);
    ColQ.GetIngressPos();
    ColQ.GetIngressPosDist(0.5, 0.5);
    ColQ.IngressHit();
    ColQ.InsideHit();
    ColQ.Reset();
    //ColQ.SetHitPiece();

    //CCollisionHandler Hand;
    //Hand.PrintStats();



    return 0;
}
