// Copyright (C) 2019 ~ 2020 Uniontech Software Technology Co.,Ltd.
// SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include "DebugTimeManager.h"

#include "gtest/src/stub.h"

#include <QTest>
#include <QAction>

#include <gtest/gtest.h>


/*******************************函数打桩************************************/

/*******************************函数打桩************************************/


class UT_DebugTimeManager : public ::testing::Test
{
public:
    UT_DebugTimeManager(): m_tester(nullptr) {}

public:
    virtual void SetUp()
    {
        m_tester = new DebugTimeManager;
    }

    virtual void TearDown()
    {
        delete m_tester;
    }

protected:
    DebugTimeManager *m_tester;
};

TEST_F(UT_DebugTimeManager, initTest)
{

}

TEST_F(UT_DebugTimeManager, test_clear)
{
    m_tester->m_MapPoint["1"] = PointInfo();
    m_tester->clear();
    EXPECT_EQ(m_tester->m_MapPoint.isEmpty(), true);
}

TEST_F(UT_DebugTimeManager, test_beginPointQt)
{
    m_tester->beginPointQt("1", "status");
    EXPECT_EQ(m_tester->m_MapPoint["1"].desc == "status", true);
}

TEST_F(UT_DebugTimeManager, test_endPointQt)
{
    m_tester->beginPointQt("1", "status");
    m_tester->endPointQt("1");
    EXPECT_EQ(m_tester->m_MapPoint.isEmpty(), true);
}

TEST_F(UT_DebugTimeManager, test_beginPointLinux)
{
    m_tester->beginPointQt("1", "status");
    EXPECT_EQ(m_tester->m_MapPoint["1"].desc == "status", true);
}

TEST_F(UT_DebugTimeManager, test_endPointLinux)
{
    m_tester->beginPointQt("1", "status");
    m_tester->endPointQt("1");
    EXPECT_EQ(m_tester->m_MapPoint.isEmpty(), true);
}
