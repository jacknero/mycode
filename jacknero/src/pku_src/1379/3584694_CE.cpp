#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define Vector(p1, p2, u, v) (u = p2->x - p1->x, v = p2->y - p1->y)
#define Cross_product_2v(u1, v1, u2, v2) (u1 * v2 - v1 * u2)
#define Cross_product_3p(p1, p2, p3) ((p2->x - p1->x) * (p3->y - p1->y) - (p2->y - p1->y) * (p3->x - p1->x))
#define Dot_product_2v(u1, v1, u2, v2) (u1 * u2 + v1 * v2)
#define Org(e) ((e)->org)
#define Dest(e) ((e)->dest)
#define Onext(e) ((e)->onext)
#define Oprev(e) ((e)->oprev)
#define Dnext(e) ((e)->dnext)
#define Dprev(e) ((e)->dprev)
#define Other_point(e, p) ((e)->org == p ? (e)->dest : (e)->org)
#define Next(e, p) ((e)->org == p ? (e)->onext : (e)->dnext)
#define Prev(e, p) ((e)->org == p ? (e)->oprev : (e)->dprev)
#define Visited(p) ((p)->f)
#define Identical_refs(e1, e2) (e1 == e2)

typedef enum {right, left} side;/**//*Edge sides.*/

typedef double Real;
typedef int boolean;

typedef struct point point;
typedef struct edge edge;

struct point
{
    Real x, y;
    edge *entry_pt;
};

struct edge
{
    point *org, *dest;
    edge *onext, *oprev, *dnext, *dprev;
};

struct Point
{
    int x, y;
};

Point p[2000];

double safest;
double answer_x, answer_y;

double X, Y;

typedef double matrix [3][3];

double value(matrix a)
{
    double h = 0.0;
    h += a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[2][0] + a[0][2] * a[1][0] * a[2][1];
    h -= a[2][0] * a[1][1] * a[0][2] + a[0][1] * a[1][0] * a[2][2] + a[0][0] * a[1][2] * a[2][1];
    return h;
}

double calculate(double p0x, double p0y, double p1x, double p1y, double p2x, double p2y)
{
    double a, bx, by, c;
    matrix t;
    t[0][0] = p0x, t[0][1] = p0y, t[0][2] = 1.0;
    t[1][0] = p1x, t[1][1] = p1y, t[1][2] = 1.0;
    t[2][0] = p2x, t[2][1] = p2y, t[2][2] = 1.0;
    a = value(t);
    t[0][0] = p0x * p0x + p0y * p0y;
    t[1][0] = p1x * p1x + p1y * p1y;
    t[2][0] = p2x * p2x + p2y * p2y;
    bx = (-1) * value(t);
    t[0][1] = p0x, t[1][1] = p1x, t[2][1] = p2x;
    by = value(t);
    t[0][2] = p0y, t[1][2] = p1y, t[2][2] = p2y;
    c = (-1) * value(t);

    double center_x = (-1) * bx / (2 * a);
    double center_y = (-1) * by / (2 * a);
    double R = sqrt(bx * bx + by * by - 4 * a * c) / fabs(2 * a);
    if(center_x >= 0 && center_x <= X && center_y >= 0 && center_y <= Y)
    {
        if(R > safest)
        {
            safest = R;
            answer_x = center_x;
            answer_y = center_y;
        }
    }
}

//memory
point *p_array;
static edge *e_array;
static edge **free_list_e;
static int n_free_e;

void alloc_memory(int n)
{
    edge *e;
    int i;
    p_array = (point *)calloc(n, sizeof(point));/**//*Point storage*/
    n_free_e = 3 * n;   /**//* Edges --- Eulers relation */
    e_array = e = (edge *)calloc(n_free_e, sizeof(edge));
    free_list_e = (edge **)calloc(n_free_e, sizeof(edge *));
    for(i = 0; i < n_free_e; i++, e++)
        free_list_e[i] = e;
}

void free_memory(void)
{
    free(p_array);  
    free(e_array);
    free(free_list_e);  
}

edge *get_edge(void)
{
    if(n_free_e == 0)
        printf("Out of memory for edges\n");
    return (free_list_e[--n_free_e]);
}

void free_edge(edge *e)
{
    free_list_e[n_free_e++] = e;
}

//extern point *p_array;

/**//*Add an edge to a ring of edges*/
void splice(edge *a, edge *b, point *v)
{
    edge *next;
    /**//*b must be the unnattached edge and a must be the previous ccw edge to b*/
    if(Org(a) == v)
    { 
        next = Onext(a);
        Onext(a) = b;
    }
    else
    {
        next = Dnext(a);
        Dnext(a) = b;
    }
    if(Org(next) == v)
        Oprev(next) = b;
    else
        Dprev(next) = b;
    if(Org(b) == v)
    {
        Onext(b) = next;
        Oprev(b) = a;
    }
    else
    {
        Dnext(b) = next;
        Dprev(b) = a;
    }
}

/**//*Initialise a new edge*/
edge *make_edge(point *u, point *v)
{
    edge *e;
    e = get_edge();
    e->onext = e->oprev = e->dnext = e->dprev = e;
    e->org = u;
    e->dest = v;
    if(u->entry_pt == NULL)
        u->entry_pt = e;
    if(v->entry_pt == NULL)
        v->entry_pt = e;
    return e;
}
/**//*Creates a new edge and adds it to two rings of edges.*/
edge *join(edge *a, point *u, edge *b, point *v, side s)
{
    edge *e;
    /**//*u and v are the two vertices which are being joined.a and b are the two edges associated with u and v res.*/
    e = make_edge(u, v);
    if(s == left)
    {
        if (Org(a) == u)
            splice(Oprev(a), e, u);
        else
            splice(Dprev(a), e, u);
        splice(b, e, v);
    }
    else
    {
        splice(a, e, u);
        if(Org(b) == v)
            splice(Oprev(b), e, v);
        else
            splice(Dprev(b), e, v);
    }
    return e;
}

/**//*Remove an edge*/
void delete_edge(edge *e)
{
    point *u, *v;
    /**//*Cache origin and destination*/
    u = Org(e);
    v = Dest(e);
    /**//*Adjust entry points*/
    if(u->entry_pt == e)
        u->entry_pt = e->onext;
    if(v->entry_pt == e)
        v->entry_pt = e->dnext;
    /**//*Four edge links to change*/
    if(Org(e->onext) == u)
        e->onext->oprev = e->oprev;
    else
        e->onext->dprev = e->oprev;
    if(Org(e->oprev) == u)
        e->oprev->onext = e->onext;
    else
        e->oprev->dnext = e->onext;
    if(Org(e->dnext) == v)
        e->dnext->oprev = e->dprev;
    else
        e->dnext->dprev = e->dprev;
    if(Org(e->dprev) == v)
        e->dprev->onext = e->dnext;
    else
        e->dprev->dnext = e->dnext;
    free_edge(e);
}
//IO
void read_points(int np)
{
    int i;
    for(i = 0; i < np; i++)
    {

        scanf("%d %d", &p[i].x, &p[i].y);
        p_array[i].x = p[i].x;
        p_array[i].y = p[i].y;
    }
}

/**//*Print the ring of edges about each vertex*/
static void print_edges(int n)
{
    edge *e_start, *e;
    point *u, *v;
    int i;
    for(i = 0; i < n; i++)
    {
        u = &p_array[i];
        e_start = e = u->entry_pt;
        do
        {
            v = Other_point(e, u);
            if(u < v)
                if(printf("%d %d\n", u - p_array, v - p_array) == EOF)
                    printf("Error printing results\n");
            e = Next(e, u);
        }while(!Identical_refs(e, e_start));
    }
}

/**//*Print the ring of triangles about each vertex*/
static void print_triangles(int n)
{
    edge *e_start, *e, *next;
    point *u, *v, *w, *t;
    int i;
    for(i = 0; i < n; i++)
    {
        u = &p_array[i];
        e_start = e = u->entry_pt;
        do
        {
            v = Other_point(e, u);
            if(u < v)
            {
                next = Next(e, u);
                w = Other_point(next, u);
                if(u < w)
                    if(Identical_refs(Next(next, w), Prev(e, v)))
                    {
                        /**//*Triangle*/
                        if(v > w)
                        {
                            t = v; v = w; w = t;
                        }
                        //printf("%d %d %d\n", u - p_array, v - p_array, w - p_array);
                        
                        calculate(u->x, u->y, v->x, v->y, w->x, w->y);
                    }
            }
            e = Next(e, u);/**//*Next edge around u*/
        }while(!Identical_refs(e, e_start));
    }
}

void print_results(int n, char o)
{
    /**//*Output edges or triangles*/
    if(o == 't') print_triangles(n);
    else print_edges(n);
}

void merge_sort(point *p[], point *p_temp[], int l, int r)
{
    int i, j, k, m;
    if(r - l > 0)
    {
        m = (r + l) / 2;
        merge_sort(p, p_temp, l, m);
        merge_sort(p, p_temp, m + 1, r);
        for(i = m + 1; i > l; i--)
            p_temp[i - 1] = p[i - 1];
        for(j = m; j < r; j++)
            p_temp[r + m - j] = p[j + 1];
        for(k = l; k <= r; k++)
            if(p_temp[i]->x < p_temp[j]->x)
            {
                p[k] = p_temp[i];
                i = i + 1;
            }
            else if(p_temp[i]->x == p_temp[j]->x && p_temp[i]->y < p_temp[j]->y)
            {
                p[k] = p_temp[i];
                i = i + 1;
            }
            else
            {
                p[k] = p_temp[j];
                j = j - 1;
            }
    }
}

/**//*Determines the lower tangent of two triangulations*/
static void lower_tangent(edge *r_cw_l, point *s, edge *l_ccw_r, point *u, edge **l_lower, point **org_l_lower, edge **r_lower, point **org_r_lower)
{
    edge *l, *r;
    point *o_l, *o_r, *d_l, *d_r;
    boolean finished;
    l = r_cw_l;
    r = l_ccw_r;
    o_l = s;
    d_l = Other_point(l, s);
    o_r = u;
    d_r = Other_point(r, u);
    finished = FALSE;
    while(!finished)
        if(Cross_product_3p(o_l, d_l, o_r) > 0.0)
        {
            l = Prev(l, d_l);
            o_l = d_l;
            d_l = Other_point(l, o_l);
        }
        else if(Cross_product_3p(o_r, d_r, o_l) < 0.0)
        {
            r = Next(r, d_r);
            o_r = d_r;
            d_r = Other_point(r, o_r);
        }
        else
            finished = TRUE;
    *l_lower = l;
    *r_lower = r;
    *org_l_lower = o_l;
    *org_r_lower = o_r;
}

/**//*The merge function is where most of the work actually gets done.It is written as one (longish) function for speed.*/
static void merge(edge *r_cw_l, point *s, edge *l_ccw_r, point *u, edge **l_tangent)
{
    edge *base, *l_cand, *r_cand;
    point *org_base, *dest_base;
    Real u_l_c_o_b, v_l_c_o_b, u_l_c_d_b, v_l_c_d_b;
    Real u_r_c_o_b, v_r_c_o_b, u_r_c_d_b, v_r_c_d_b;
    Real c_p_l_cand, c_p_r_cand;
    Real d_p_l_cand, d_p_r_cand;
    boolean above_l_cand, above_r_cand, above_next, above_prev;
    point *dest_l_cand, *dest_r_cand;
    Real cot_l_cand, cot_r_cand;
    edge *l_lower, *r_lower;
    point *org_r_lower, *org_l_lower;
    /**//*Create first cross edge by joining lower common tangent*/
    lower_tangent(r_cw_l, s, l_ccw_r, u, &l_lower, &org_l_lower, &r_lower, &org_r_lower);
    base = join(l_lower, org_l_lower, r_lower, org_r_lower, right);
    org_base = org_l_lower;
    dest_base = org_r_lower;
    /**//*Need to return lower tangent.*/
    *l_tangent = base;
    /**//*Main merge loop*/
    do
    {
        /**//*Initialise l_cand and r_cand*/
        l_cand = Next(base, org_base);
        r_cand = Prev(base, dest_base);
        dest_l_cand = Other_point(l_cand, org_base);
        dest_r_cand = Other_point(r_cand, dest_base);
        /**//*Vectors for above and "in_circle" tests*/
        Vector(dest_l_cand, org_base, u_l_c_o_b, v_l_c_o_b);
        Vector(dest_l_cand, dest_base, u_l_c_d_b, v_l_c_d_b);
        Vector(dest_r_cand, org_base, u_r_c_o_b, v_r_c_o_b);
        Vector(dest_r_cand, dest_base, u_r_c_d_b, v_r_c_d_b);
        /**//*Above tests.*/
        c_p_l_cand = Cross_product_2v(u_l_c_o_b, v_l_c_o_b, u_l_c_d_b, v_l_c_d_b);
        c_p_r_cand = Cross_product_2v(u_r_c_o_b, v_r_c_o_b, u_r_c_d_b, v_r_c_d_b);
        above_l_cand = c_p_l_cand > 0.0;
        above_r_cand = c_p_r_cand > 0.0;
        if(!above_l_cand && !above_r_cand)
            break;/**//*Finished*/
        /**//*Advance l_cand ccw,  deleting the old l_cand edge,  until the "in_circle" test fails*/
        if(above_l_cand)
        {
            Real u_n_o_b, v_n_o_b, u_n_d_b, v_n_d_b;
            Real c_p_next, d_p_next, cot_next;
            edge *next;
            point *dest_next;
            d_p_l_cand = Dot_product_2v(u_l_c_o_b, v_l_c_o_b, u_l_c_d_b, v_l_c_d_b);
            cot_l_cand = d_p_l_cand / c_p_l_cand;
            do
            {
                next = Next(l_cand, org_base);
                dest_next = Other_point(next, org_base);
                Vector(dest_next, org_base, u_n_o_b, v_n_o_b);
                Vector(dest_next, dest_base, u_n_d_b, v_n_d_b);
                c_p_next = Cross_product_2v(u_n_o_b, v_n_o_b, u_n_d_b, v_n_d_b);
                above_next = c_p_next > 0.0;
                if(!above_next) 
                    break;/**//*Finished*/
                d_p_next = Dot_product_2v(u_n_o_b, v_n_o_b, u_n_d_b, v_n_d_b);
                cot_next = d_p_next / c_p_next;
                if(cot_next > cot_l_cand)
                    break;/**//*Finished*/
                delete_edge(l_cand);
                l_cand = next;
                cot_l_cand = cot_next;
            }while(TRUE);
        }
        /**//*Now do the symmetrical for r_cand*/
        if(above_r_cand)
        {
            Real u_p_o_b, v_p_o_b, u_p_d_b, v_p_d_b;
            Real c_p_prev, d_p_prev, cot_prev;
            edge *prev;
            point *dest_prev;
            d_p_r_cand = Dot_product_2v(u_r_c_o_b, v_r_c_o_b, u_r_c_d_b, v_r_c_d_b);
            cot_r_cand = d_p_r_cand / c_p_r_cand;
            do
            {
                prev = Prev(r_cand, dest_base);
                dest_prev = Other_point(prev, dest_base);
                Vector(dest_prev, org_base, u_p_o_b, v_p_o_b);
                Vector(dest_prev, dest_base, u_p_d_b, v_p_d_b);
                c_p_prev = Cross_product_2v(u_p_o_b, v_p_o_b, u_p_d_b, v_p_d_b);
                above_prev = c_p_prev > 0.0;
                if(!above_prev)
                    break;/**//*Finished*/
                d_p_prev = Dot_product_2v(u_p_o_b, v_p_o_b, u_p_d_b, v_p_d_b);
                cot_prev = d_p_prev / c_p_prev;
                if(cot_prev > cot_r_cand)
                    break;/**//*Finished*/
                delete_edge(r_cand);
                r_cand = prev;
                cot_r_cand = cot_prev;
            }while(TRUE);
        }
        /**//*Now add a cross edge from base to either l_cand or r_cand.
         * If both are valid choose on the basis of the in_circle test.
         * Advance base and  whichever candidate was chosen.*/
        dest_l_cand = Other_point(l_cand, org_base);
        dest_r_cand = Other_point(r_cand, dest_base);
        if(!above_l_cand || (above_l_cand && above_r_cand && cot_r_cand < cot_l_cand))
        {
            /**//*Connect to the right*/
            base = join(base, org_base, r_cand, dest_r_cand, right);
            dest_base = dest_r_cand;
        }
        else
        {
            /**//*Connect to the left*/
            base = join(l_cand, dest_l_cand, base, dest_base, right);
            org_base = dest_l_cand;
        }
    }while(TRUE);
}

void divide(point *p_sorted[], int l, int r, edge **l_ccw, edge **r_cw)
{
    int n;
    int split;
    edge *l_ccw_l, *r_cw_l, *l_ccw_r, *r_cw_r, *l_tangent;
    edge *a, *b, *c;
    Real c_p;
    n = r - l + 1;
    if(n == 2)
    {
        /**//*Bottom of the recursion. Make an edge*/
        *l_ccw = *r_cw = make_edge(p_sorted[l], p_sorted[r]);
    }
    else if(n == 3)
    {
        /**//*Bottom of the recursion. Make a triangle or two edges*/
        a = make_edge(p_sorted[l], p_sorted[l + 1]);
        b = make_edge(p_sorted[l + 1], p_sorted[r]);
        splice(a, b, p_sorted[l + 1]);
        c_p = Cross_product_3p(p_sorted[l], p_sorted[l + 1], p_sorted[r]);
        if(c_p > 0.0)
        {
            /**//*Make a triangle*/
            c = join(a, p_sorted[l], b, p_sorted[r], right);
            *l_ccw = a;
            *r_cw = b;
        }
        else if(c_p < 0.0)
        {
            /**//*Make a triangle*/
            c = join(a, p_sorted[l], b, p_sorted[r], left);
            *l_ccw = c;
            *r_cw = c;
        }
        else
        {
            /**//*Points are collinear,  no triangle*/
            *l_ccw = a;
            *r_cw = b;
        }
    }
    else if(n > 3)
    {
        /**//*Continue to divide */
        /**//*Calculate the split point */
        split = (l + r) / 2;
        /**//*Divide*/
        divide(p_sorted, l, split, &l_ccw_l, &r_cw_l);
        divide(p_sorted, split + 1, r, &l_ccw_r, &r_cw_r);
        /**//*Merge*/
        merge(r_cw_l, p_sorted[split], l_ccw_r, p_sorted[split + 1], &l_tangent);
        /**//*The lower tangent added by merge may have invalidated l_ccw_l or r_cw_r.Update them if necessary.*/
        if(Org(l_tangent) == p_sorted[l])
            l_ccw_l = l_tangent;
        if(Dest(l_tangent) == p_sorted[r])
            r_cw_r = l_tangent;
        /**//*Update edge refs to be passed back*/ 
        *l_ccw = l_ccw_l;
        *r_cw = r_cw_r;
    }
}

int n;

void initi()
{
    edge *l_cw, *r_ccw;
    int i;
    point **p_sorted, **p_temp;
    
    alloc_memory(n);
    read_points(n);
    
    for(i = 0; i < n; i++)
        p_array[i].entry_pt = NULL;
    
    p_sorted = (point **)malloc((unsigned)n*sizeof(point *));
    p_temp = (point **)malloc((unsigned)n*sizeof(point *));
    
    for(i = 0; i < n; i++)
        p_sorted[i] = p_array + i;
    
    merge_sort(p_sorted, p_temp, 0, n - 1);
    
    free((char *)p_temp);
    
    divide(p_sorted, 0, n - 1, &l_cw, &r_ccw);
    
    free((char *)p_sorted);
    
    print_results(n, 't');
    
    free_memory();
}

void handle(double x1, double y1, double x2, double y2)
{
    double x0 = (x1 + x2) / 2, y0 = (y1 + y2) / 2;
    double vx = x2 - x1;
    double vy = y2 - y1;
    double LL = hypot(vx, vy);
    vx /= LL, vy /= LL;
    double tx = vx * cos(-M_PI / 2.0) - vy * sin(-M_PI / 2.0);
    double ty = vx * sin(-M_PI / 2.0) + vy * cos(-M_PI / 2.0);
    double mm = 1e100;
    double eps = 1e-10;
    double xx, yy, L;
    if(fabs(tx) > eps)
    {
        L = (0 - x0) / tx;
        if(L > 0)
        {
            xx = 0;
            yy = y0 + L * ty;
            if(yy >= 0 && yy <= Y)
            {
                double dist = hypot(xx - x1, yy - y1);
                if(dist > safest)
                {
                    safest = dist;
                    answer_x = xx;
                    answer_y = yy;
                }
            }
        }
        L = (X - x0) / tx;
        if(L > 0)
        {
            xx = X;
            yy = y0 + L * ty;
            if(yy >= 0 && yy <= Y)
            {
                double dist = hypot(xx - x1, yy - y1);
                if(dist > safest)
                {
                    safest = dist;
                    answer_x = xx;
                    answer_y = yy;
                }
            }
        }
    }
    if(fabs(ty) > eps)
    {
        L = (0 - y0) / ty;
        if(L > 0)
        {
            xx = x0 + L * tx;
            yy = 0;
            if(xx >= 0 && xx <= X)
            {
                double dist = hypot(xx - x1, yy - y1);
                if(dist > safest)
                {
                    safest = dist;
                    answer_x = xx;
                    answer_y = yy;
                }
            }
        }
        L = (Y - y0) / ty;
        if(L > 0)
        {
            xx = x0 + L * tx;
            yy = Y;
            if(xx >= 0 && xx <= X)
            {
                double dist = hypot(xx - x1, yy - y1);
                if(dist > safest)
                {
                    safest = dist;
                    answer_x = xx;
                    answer_y = yy;
                }
            }
        }
    }
}

Point c[2000];
int bt[2000], tp[2000], v[2000];
int bt_top, tp_top;

int cmp(const void *p1, const void *p2)
{
    const Point *pp1 = (const Point *)p1;
    const Point *pp2 = (const Point *)p2;
    return pp1->x == pp2->x ? pp1->y - pp2->y : pp1->x - pp2->x;
}

int det(int x1, int y1, int x2, int y2)
{
    return x2 * y1 - x1 * y2;
}

int cross(Point a, Point b, Point c)
{
    return det(b.x - a.x, b.y - a.y, c.x - b.x, c.y - b.y);
}

void compare()
{
    int i, j, k;
    qsort(p, n, sizeof(p[0]), cmp);
    bt[0] = 0, tp[0] = 0, bt[1] = 1, tp[1] = 1;
    bt_top = 1, tp_top = 1;
    for(i = 0; i < n; i++)
    {
        if (cross(p[bt[1]], p[0], p[i]) <= 0)
            bt[1] = i;
        if (cross(p[tp[1]], p[0], p[i]) >= 0)
            tp[1] = i;
    }
    for(i = bt[bt_top] + 1; i < n; i++)
        while(1)
            if (cross(p[bt[bt_top - 1]], p[bt[bt_top]], p[i]) >= 0)
                bt_top--;
            else
            {
                bt[++bt_top] = i;
                break;
            }
    for(i = tp[tp_top] + 1; i < n; i++)
        while(1)
            if(cross(p[tp[tp_top - 1]], p[tp[tp_top]], p[i]) <= 0)
                tp_top--;
            else
            {
                tp[++tp_top] = i;
                break;
            }
    k = 0;
    for(i = 0; i <= bt_top; i++)
        c[k++] = p[bt[i]];
    for(i = tp_top - 1; i >= 1; i--)
        c[k++] = p[tp[i]];
    c[k] = c[0];
    for(i = 0; i < k; i++)
        handle(c[i].x, c[i].y, c[i + 1].x, c[i + 1].y);
}

void solve()
{
    safest = 0;
    scanf("%lf %lf %d", &X, &Y, &n);
    if(n == 1)
    {
        scanf("%d %d", &p[0].x, &p[0].y);
        double xx, yy, dist;
        xx = 0, yy = 0;
        dist = hypot(xx - p[0].x, yy - p[0].y);
        if(dist > safest)
        {
            safest = dist;
            answer_x = xx;
            answer_y = yy;
        }
        xx = X, yy = 0;
        dist = hypot(xx - p[0].x, yy - p[0].y);
        if(dist > safest)
        {
            safest = dist;
            answer_x = xx;
            answer_y = yy;
        }
        xx = 0, yy = Y;
        dist = hypot(xx - p[0].x, yy - p[0].y);
        if(dist > safest)
        {
            safest = dist;
            answer_x = xx;
            answer_y = yy;
        }
        xx = X, yy = Y;
        dist = hypot(xx - p[0].x, yy - p[0].y);
        if(dist > safest)
        {
            safest = dist;
            answer_x = xx;
            answer_y = yy;
        }
    }
    else
    {
        initi();
        compare();
    }
    printf("The safest point is (%.1lf, %.1lf).\n", answer_x, answer_y);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}