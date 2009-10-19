/*
 * =====================================================================================
 *
 *       Filename:  Graph.cxx
 *
 *    Description:  CURSOR>this is graph library
 *
 *        Version:  1.0
 *        Created:  2009ǯ08��04�� 00��06ʬ01��
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH S���dwestfalen, Iserlohn
 *
 * =====================================================================================
 */

typedef int Weight;
struct Edge {
  int src, dst;
  Wegith weight;
  Edge(int src, int dst, Weight weight):
    src(src), dst(dst), weight(weight){}
};
bool operator <(const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight :
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;
