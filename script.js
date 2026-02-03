// Spring Festival date for 2026 (January 29, 2026)
const springFestival2026 = new Date('2026-01-29T00:00:00');

// Red envelope activities data
const activities = [
    {
        name: '腾讯元宝分10亿',
        status: 'active',
        amount: '10亿元红包',
        description: '腾讯元宝AI助手春节期间发放10亿元红包，每天多次抽奖机会，最高可得888元！',
        dates: '2026年1月20日 - 2026年2月8日',
        platform: '微信小程序'
    },
    {
        name: '支付宝集五福',
        status: 'coming',
        amount: '5亿元红包',
        description: '经典的集五福活动，集齐五福平分5亿现金，还有各种惊喜福卡和权益！',
        dates: '2026年1月22日 - 2026年1月28日',
        platform: '支付宝'
    },
    {
        name: '抖音春节红包雨',
        status: 'active',
        amount: '20亿元红包',
        description: '抖音春节期间发放20亿元红包，看视频、直播、集卡都能领红包！',
        dates: '2026年1月15日 - 2026年2月15日',
        platform: '抖音APP'
    },
    {
        name: '快手春节大红包',
        status: 'active',
        amount: '15亿元红包',
        description: '快手春节发放15亿元红包，完成任务、邀请好友都能获得现金奖励！',
        dates: '2026年1月18日 - 2026年2月10日',
        platform: '快手APP'
    },
    {
        name: '京东年货节红包',
        status: 'active',
        amount: '10亿元红包',
        description: '京东年货节期间发放10亿元购物红包，买年货超划算！',
        dates: '2026年1月10日 - 2026年2月5日',
        platform: '京东APP'
    },
    {
        name: '拼多多现金大放送',
        status: 'coming',
        amount: '8亿元红包',
        description: '拼多多春节现金大放送，砍价、签到、邀请好友都能领现金！',
        dates: '2026年1月25日 - 2026年2月8日',
        platform: '拼多多APP'
    }
];

// Tutorial data
const tutorials = [
    {
        title: '腾讯元宝分10亿红包教程',
        steps: [
            '打开微信，搜索"腾讯元宝"小程序',
            '进入小程序后，点击"春节活动"入口',
            '每天可以抽奖3-5次，完成任务可获得额外抽奖机会',
            '分享给好友，双方都能获得抽奖机会',
            '中奖后红包会自动发放到微信零钱',
            '记得每天都来参与，连续签到还有额外奖励'
        ],
        tips: '建议每天早上9点、中午12点、晚上8点各抽一次，这些时间段中奖概率较高！'
    },
    {
        title: '支付宝集五福攻略',
        steps: [
            '打开支付宝APP，首页会出现"集五福"活动入口',
            '通过AR扫福字、蚂蚁森林浇水、答题等方式获得福卡',
            '五福包括：富强福、和谐福、友善福、爱国福、敬业福',
            '可以和好友互相赠送多余的福卡',
            '集齐五福后，除夕当天22:18开奖',
            '奖金会在春节后发放到支付宝余额'
        ],
        tips: '敬业福通常最难获得，可以通过支付宝搜索"敬业福"获取线索，或者用万能福兑换！'
    },
    {
        title: '抖音春节红包雨玩法',
        steps: [
            '打开抖音APP，首页搜索"春节红包"',
            '观看指定视频或直播可以获得红包',
            '参与话题挑战发布视频，可获得额外红包',
            '集齐指定卡片可瓜分大奖池',
            '邀请好友助力，双方都能获得红包',
            '每天晚上8-10点是红包雨高峰期'
        ],
        tips: '多关注热门创作者的直播间，经常会有红包雨活动！发布原创春节相关视频还能获得流量扶持和现金奖励。'
    },
    {
        title: '通用红包收集技巧',
        steps: [
            '设置手机日历提醒，不错过活动开始时间',
            '添加活动到日程，每天定时参与',
            '加入红包交流群，及时获取最新活动信息',
            '准备好家人朋友的联系方式，方便互助',
            '注意活动规则，避免违规操作导致封号',
            '及时提现或使用红包，避免过期'
        ],
        tips: '建议创建一个专门的文件夹，把所有红包APP放在一起，方便每天统一打卡领取！'
    }
];

// Update countdown timer
function updateCountdown() {
    const now = new Date();
    const diff = springFestival2026 - now;

    if (diff <= 0) {
        document.getElementById('countdown').innerHTML = '<div class="time-unit"><span class="time-value">春节到啦！</span></div>';
        return;
    }

    const days = Math.floor(diff / (1000 * 60 * 60 * 24));
    const hours = Math.floor((diff % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
    const minutes = Math.floor((diff % (1000 * 60 * 60)) / (1000 * 60));
    const seconds = Math.floor((diff % (1000 * 60)) / 1000);

    document.getElementById('days').textContent = days;
    document.getElementById('hours').textContent = String(hours).padStart(2, '0');
    document.getElementById('minutes').textContent = String(minutes).padStart(2, '0');
    document.getElementById('seconds').textContent = String(seconds).padStart(2, '0');
}

// Render activities
function renderActivities() {
    const activitiesContainer = document.getElementById('activities');
    
    activities.forEach(activity => {
        const card = document.createElement('div');
        card.className = 'activity-card';
        
        let statusText = '';
        switch(activity.status) {
            case 'active':
                statusText = '进行中';
                break;
            case 'coming':
                statusText = '即将开始';
                break;
            case 'ended':
                statusText = '已结束';
                break;
        }
        
        card.innerHTML = `
            <h3>${activity.name}</h3>
            <span class="status ${activity.status}">${statusText}</span>
            <p class="amount">${activity.amount}</p>
            <p>${activity.description}</p>
            <p class="date">📅 ${activity.dates}</p>
            <p class="date">📱 ${activity.platform}</p>
        `;
        
        activitiesContainer.appendChild(card);
    });
}

// Render tutorials
function renderTutorials() {
    const tutorialsContainer = document.getElementById('tutorials');
    
    tutorials.forEach(tutorial => {
        const item = document.createElement('div');
        item.className = 'tutorial-item';
        
        const stepsList = tutorial.steps.map((step, index) => 
            `<li>${step}</li>`
        ).join('');
        
        item.innerHTML = `
            <h3>${tutorial.title}</h3>
            <ol>
                ${stepsList}
            </ol>
            <div class="tips">
                <strong>💡 小贴士：</strong>${tutorial.tips}
            </div>
        `;
        
        tutorialsContainer.appendChild(item);
    });
}

// Initialize the page
function init() {
    updateCountdown();
    setInterval(updateCountdown, 1000);
    renderActivities();
    renderTutorials();
}

// Run when page loads
if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', init);
} else {
    init();
}
