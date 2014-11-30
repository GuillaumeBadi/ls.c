typedef struct				s_lst
{
	void					*content;
	struct s_lst			*next;
}							t_lst;

#define FLAGS 0
#define OPTIONS 0

#define ST_SIZE(x) (int)x->st_size
#define ST_LINKS
#define ST_USR
#define ST_GROUP
#define ST_MONTH
#define ST_DAY
#define ST_YEAR
