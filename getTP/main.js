const puppeteer = require('puppeteer');
const fs = require('fs');
const path = require('path');
const axios = require('axios');
const url = require('url');

const baseUrl = 'http://vljn.me/#/virtual/td' + process.argv[2];
const targetFolder = './../TP' + process.argv[2];

// Ensure the target folder exists
if (!fs.existsSync(targetFolder)) {
    fs.mkdirSync(targetFolder);
}

const downloadFile = async (fileUrl, outputPath) => {
    try {
        const response = await axios({
            method: 'GET',
            url: fileUrl,
            responseType: 'stream'
        });

        response.data.pipe(fs.createWriteStream(outputPath));
        console.log(`Downloaded: ${outputPath}`);
    } catch (error) {
        console.error(`Error downloading ${fileUrl}: ${error.message}`);
    }
};

const findAndDownloadFiles = async (page) => {
    const hrefs = await page.$$eval('a', links => links.map(link => link.href));

    hrefs.forEach(href => {
        if (href.endsWith('Makefile') || href.endsWith('.sh') || href.endsWith('.h') || href.endsWith('.cc') || href.endsWith('.gz')) {
            const parsedUrl = url.parse(href);
            const filename = path.basename(parsedUrl.pathname);
            const outputPath = path.join(targetFolder, filename);
            downloadFile(href, outputPath);
        }
    });
};

const clickButton = async (page, buttonText) => {
    const [button] = await page.$x(`//button[contains(text(), '${buttonText}')]`);
    if (button) {
        await button.click();
        await page.waitForTimeout(1000); // Adjust timeout as necessary
        return true;
    } else {
        console.log(`Button with text "${buttonText}" not found`);
        return false;
    }
};

const getFiles = async () => {
    const browser = await puppeteer.launch({ headless: "new" });
    const page = await browser.newPage();
    await page.goto(baseUrl, { waitUntil: 'networkidle0' });

    // Download files from the base page first
    await findAndDownloadFiles(page);

    // Click on specific buttons and download files
    const buttonsTexts = 'Exercice ';
    for (var i = 1; i < 5; i++) {
        if(await clickButton(page, buttonsTexts + i)){
            await findAndDownloadFiles(page);
        }else{
            break;
        }
    }

    await browser.close();
};

getFiles();
