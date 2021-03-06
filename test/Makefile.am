if TESTS
TEST_CFLAGS = -Wall -I$(top_srcdir)/include @liblo_CFLAGS@
TEST_CXXFLAGS = -Wall -I$(top_srcdir)/include @liblo_CFLAGS@

if WINDOWS_DLL
TEST_LDADD = $(top_builddir)/src/*.lo $(liblo_LIBS)
else
TEST_LDADD = $(top_builddir)/src/libmapper.la $(liblo_LIBS)
endif

noinst_PROGRAMS = test testconvergent testcpp testcustomtransport testdatabase \
                  testexpression testinstance testlinear testmany testmapinput \
                  testmapprotocol testmonitor testnetwork testparams testparser\
                  testprops testqueue testquery testrate testreverse testselect\
                  testsignals testspeed testvector

test_all_ordered = testparams testprops testdatabase testparser testnetwork    \
                   testmany test testlinear testexpression testqueue testquery \
                   testrate testinstance testreverse testselect testvector     \
                   testcustomtransport testspeed testcpp testmapinput          \
                   testconvergent testmapprotocol

test_CFLAGS = $(TEST_CFLAGS)
test_SOURCES = test.c
test_LDADD = $(TEST_LDADD)

testconvergent_CFLAGS = $(TEST_CFLAGS)
testconvergent_SOURCES = testconvergent.c
testconvergent_LDADD = $(TEST_LDADD)

testcpp_CXXFLAGS = $(TEST_CXXFLAGS)
testcpp_SOURCES = testcpp.cpp
testcpp_LDADD = $(TEST_LDADD)

testcustomtransport_CFLAGS = $(TEST_CFLAGS)
testcustomtransport_SOURCES = testcustomtransport.c
testcustomtransport_LDADD = $(TEST_LDADD)

testdatabase_CFLAGS = $(TEST_CFLAGS)
testdatabase_SOURCES = testdatabase.c
testdatabase_LDADD = $(TEST_LDADD)

testexpression_CFLAGS = $(TEST_CFLAGS)
testexpression_SOURCES = testexpression.c
testexpression_LDADD = $(TEST_LDADD)

testinstance_CFLAGS = $(TEST_CFLAGS)
testinstance_SOURCES = testinstance.c
testinstance_LDADD = $(TEST_LDADD)

testlinear_CFLAGS = $(TEST_CFLAGS)
testlinear_SOURCES = testlinear.c
testlinear_LDADD = $(TEST_LDADD)

testmany_CFLAGS = $(TEST_CFLAGS)
testmany_SOURCES = testmany.c
testmany_LDADD = $(TEST_LDADD)

testmapinput_CFLAGS = $(TEST_CFLAGS)
testmapinput_SOURCES = testmapinput.c
testmapinput_LDADD = $(TEST_LDADD)

testmapprotocol_CFLAGS = $(TEST_CFLAGS)
testmapprotocol_SOURCES = testmapprotocol.c
testmapprotocol_LDADD = $(TEST_LDADD)

testmonitor_CFLAGS = $(TEST_CFLAGS)
testmonitor_SOURCES = testmonitor.c
testmonitor_LDADD = $(TEST_LDADD)

testnetwork_CFLAGS = $(TEST_CFLAGS)
testnetwork_SOURCES = testnetwork.c
testnetwork_LDADD = $(TEST_LDADD)

testparams_CFLAGS = $(TEST_CFLAGS)
testparams_SOURCES = testparams.c
testparams_LDADD = $(TEST_LDADD)

testparser_CFLAGS = $(TEST_CFLAGS)
testparser_SOURCES = testparser.c
testparser_LDADD = $(TEST_LDADD)

testprops_CFLAGS = $(TEST_CFLAGS)
testprops_SOURCES = testprops.c
testprops_LDADD = $(TEST_LDADD)

testqueue_CFLAGS = $(TEST_CFLAGS)
testqueue_SOURCES = testqueue.c
testqueue_LDADD = $(TEST_LDADD)

testquery_CFLAGS = $(TEST_CFLAGS)
testquery_SOURCES = testquery.c
testquery_LDADD = $(TEST_LDADD)

testrate_CFLAGS = $(TEST_CFLAGS)
testrate_SOURCES = testrate.c
testrate_LDADD = $(TEST_LDADD)

testreverse_CFLAGS = $(TEST_CFLAGS)
testreverse_SOURCES = testreverse.c
testreverse_LDADD = $(TEST_LDADD)

testselect_CFLAGS = $(TEST_CFLAGS)
testselect_SOURCES = testselect.c
testselect_LDADD = $(TEST_LDADD)

testsignals_CFLAGS = $(TEST_CFLAGS)
testsignals_SOURCES = testsignals.c
testsignals_LDADD = $(TEST_LDADD)

testspeed_CFLAGS = $(TEST_CFLAGS)
testspeed_SOURCES = testspeed.c
testspeed_LDADD = $(TEST_LDADD)

testvector_CFLAGS = $(TEST_CFLAGS)
testvector_SOURCES = testvector.c
testvector_LDADD = $(TEST_LDADD)

tests: all
	for i in $(test_all_ordered); do echo Running $$i; if ! ./$$i -qt; then exit 1; fi; done
	echo Running testmonitor and testsignals; ./testmonitor -t & ./testsignals

memtest: all
	for i in $(noinst_PROGRAMS); do echo Running $$i; if ! LD_PRELOAD=/usr/local/lib/libmapper.dylib valgrind --leak-check=full ./.libs/$$i -qt; then exit 1; fi; done

endif
