#! /usr/bin/python
import scrapy
from scrapy.selector import HtmlXPathSelector

class MagicSpider(scrapy.Spider):
    name = 'baseball'
    start_urls = []
    URL = 'http://www.baseball-reference.com/boxes/2012.shtml'
    file_name = ''

    def __init__(self):
        self.URL = raw_input("input url: ")
        self.start_urls.append(self.URL) 
        self.file_name = raw_input("input name of file: ")

    def parse( self, response):
        html_dump = open(self.file_name, "w")
        hxs = HtmlXPathSelector(response)
        url_starts_with = raw_input("href links start with: ")
        for url in hxs.select('//a/@href').extract():
            temp_url = url
            if not (url.startswith('http://') or url.startswith('https://')):
                temp_url = self.URL + url + "\n"
            if url.startswith(url_starts_with):
                html_dump.write(temp_url)
                yield scrapy.Request(temp_url, callback=self.parse)
