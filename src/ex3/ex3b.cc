#include "utils.h"
#include "point.h"

#include <random>
#include <iostream>

void plot_graph(int N, double x[], double y[]){

    TCanvas *c = new TCanvas("c", "c", 800, 800);
    TGraph *gr = new TGraph(N, x, y);

    gr->SetTitle("");
    gr->Draw("AP");

    TEllipse *el1 = new TEllipse(0.,0.,1.,1.);
    el1->SetFillStyle(0);
    el1->Draw("SAME");

    c->SetLeftMargin(0.15);
    c->SetBottomMargin(0.15);

    c->SetGrid();

    c->Print("square.pdf");

}

int main(){

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> distr(0.0,1.0);

    int inside = 0;
    int tot = 0;

    int N = 10000;

    double x[N],y[N];
    
    for(size_t i = 0; i<N; i++){
        Point p = rand_in_unit_square(distr, mt);
        x[i] = p.x;
        y[i] = p.y;
    }
    plot_graph(N, x, y);

}