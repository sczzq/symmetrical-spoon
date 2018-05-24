
extern vector<Record> goods;

template<typename Pred>
Record* find_rec(vector<Record>& vr, int first, int last, Pred pr)
{
	vector<Record>::iterator p = std::find_if(vr.begin()+first, vr.begin()+last, pr);
	if(p == vr.begin()+last)
		return nullptr;
	return &*p;
}

const int grain = 50000;

template<typename Pred>
Record* pfind(vector<Record>& vr, Pred pr)
{
	assert(vr.size%grain==0);
	vector<future<Record*>> res;
	for(int i = 0; i != vr.size(); i+=grain)
		res.push_back(async(find_rec<Pred>, ref(vr), i, i+grain, pr));

	for(int i = 0; i != res.size(); ++i)
		if(auto p = res[i].get())
			return p;

	return nullptr;
}

void find_cheap_red()
{
	assert(goods.size() % grain == 0);

	Record* p = pfind(goods, 
			[](Record& r){return r.price<200 && r.color==Color::red});

	cout << "record" << *p << '\n';
}

template<typename Pred>
Record* pfind_any(vector<Record>& vr, Pred pr)
{
	vector<future<Record*>> res;

	for(int i=0; i!=vr.size(); i+=grain)
		res.push_back(async(find_rec<Pred>, ref(vr), i, i+grain, pr));

	for(int count = res.size(); count; --count){
		int i = wait_for_any(res, microseconds{10});
		if(auto p = res[i].get())
			return p;
	}

	return nullptr;
}

template<typename Pred>
vector<Record*> find_all_rec(vector<Record>& vr, int first, int last, Pred pr)
{
	vector<Record*> res;
	for(int i = first; i != last; ++i)
		if(pr(vr[i]))
			res.push_back(&vr[i]);

	return res;
}

template<typename Pred>
vector<Record*> pfind_all(vector<Record>& vr, Pred pr)
{
	vector<future<vector<Record*>>> res;
	for(int i = 0; i!= vr.size(); i+= grain)
		res.push_back(async(find_all_rec<Pred>, ref(vr), i, i+grain, pr));

	vector<Record*> r;
	for(auto& x : r2)
		for(auto p : x)
			r.push_back(p);

	return r;
}

void find_all_cheap_red()
{
	assert(goods.size()%grain == 0);

	auto vp = pfind_all(goods,
			[](Record& r) {return r.price<200&&r.color==Color::red});

	for(auto p : vp)
		cout << "record" << *p << '\n';
}

void just_find_cheap_red()
{
	auto p = find_if(goods.begin(), goods.end(),
		[](Record& r){return r.price<200&&r.color==Color::red});

	if(p != goods.end())
		cout << "record" << *p << '\n';
	else
		cout << "not found\n";
}

void just_find_all_cheap_red()
{
	auto vp = find_all_rec(goods, 0, goods.size(),
		[](Record& r){return r.price<200&&r.color==Color::red});
	for(auto p : vp)
		cout << "record" << *p << '\n';
}

