BASE_CLASS=libbase_class.so
FACTORY=libfactory.so
IMPLEMENTATION1=libimplementation1.so
IMPLEMENTATION2=libimplementation2.so
IMPLEMENTATION3=libimplementation3.so

target=a.out

.PHONY: ${target}

${target}:main.cpp ${BASE_CLASS} ${FACTORY} ${IMPLEMENTATION1} ${IMPLEMENTATION2} ${IMPLEMENTATION3}
	${CXX} $< -L. -lfactory -limplementation1 -limplementation2 -limplementation3 -lbase_class

${BASE_CLASS}:base_class.cpp base_class.h
	${CXX} -fPIC -shared $^ -o $@

${FACTORY}:factory.cpp factory.h
	${CXX} -fPIC -shared $^ -o $@

${IMPLEMENTATION1}:implementation1.cpp implementation1.h ${BASE_CLASS}
	${CXX} -fPIC -shared $^ -o $@

${IMPLEMENTATION2}:implementation2.cpp implementation2.h ${BASE_CLASS}
	${CXX} -fPIC -shared $^ -o $@

${IMPLEMENTATION3}:implementation3.cpp implementation3.h ${BASE_CLASS}
	${CXX} -fPIC -shared $^ -o $@

clean:
	rm *.so ${target} -rf

