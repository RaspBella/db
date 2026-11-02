docs/index.json: gen docs
	./$<

docs:
	mkdir $@

clean:
	rm -rf gen docs
