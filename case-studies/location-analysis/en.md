# Social media location analysis — MSc thesis and later rebuild

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md)

The principal work is a completed 2024 MSc thesis. A local, privacy-conscious software rebuild begun in 2026 is a separate engineering contribution.

**Thesis: completed in 2024. Software rebuild: in development.**

![Generated conceptual thesis cover; not a real map or research result](https://yahyaalali.com/images/editorial/location-analysis-r6.webp)

Generated conceptual illustration, not an actual interface or research result.

## Evidence lineage and bibliographic boundary

The early Computer Engineering graduation project was co-authored by Yahya ALALI and Muhammed Ayham Galavinci in the 2021–2022 academic period; the surviving record does not allocate individual roles. The individual MSc thesis “Sosyal Medya Lokasyon Analizi” was [accepted by Sakarya University on 5 July 2024](https://acikerisim.sakarya.edu.tr/xmlui/handle/20.500.12619/102984). A local PDF still carries an incomplete template approval page dated 24 June; it is not the final bibliographic authority.

A derivative full paper by Yahya ALALI and Nilüfer YURTAY appears on pages 43–50 of the [IMASCON 2024 Spring proceedings](https://www.imascon.com/kayit/kayittr/dosyalar/imascon_2024_spring/imascon_2024_spring_fen_tammetin_bildiriler.pdf), ISBN 978-605-72746-5-6. This is a conference paper, not a journal article; no DOI was verified. The 2026 rebuild is neither a thesis edition nor a paper result.

## The historical 2024 workflow

The thesis application retrieved targeted-account posts through Instaloader and stored application data in Firebase. It first used a post geotag, then Google Cloud Vision landmarks if the tag was absent, and finally OpenCV/TensorFlow image processing when earlier clues were insufficient. Geocoding resolved place names; country and city frequencies and shares appeared in a report and map. The thesis documents the workflow and example runs, not a reproducible labelled benchmark or comparative accuracy estimate. Targeting other people's accounts raises privacy and platform-terms concerns and is not a recommended current workflow.

## The separate 2026 software question

Authorised user exports can contain scattered location and time information. I develop this project to turn those observations into an organised view: where points cluster, how their distribution changes over time and how datasets differ. Local processing is part of a design that considers the privacy of its inputs.

## Connecting points and measures

The scope includes DBSCAN spatial clustering, radius of gyration for spatial spread, Shannon entropy for diversity and temporal analysis. Measures such as Jaccard similarity, Bray–Curtis dissimilarity and centroid distance compare datasets from different perspectives; they do not automatically collapse into a single conclusion.

A synthetic example can illustrate points around two locations and a distribution that changes between time periods. Such a figure explains the analysis; it is not a real person's movement trace or an unmeasured accuracy result.

## My contribution, tests and current stage

I develop the analysis tools and ways to interpret their output. This research-software rebuild began in 2026 and is separate from the [2024 master's thesis](https://yahyaalali.com/en/content-library/publication/masters-thesis/). An isolated copy passed 402 Python tests, with four optional-dependency skips; desktop-window tests hung, so the full gate remains open. The available package was not published as-is: historical `legacy` and login paths, unsupported claims, technical documentation and optional PDF-report dependency declarations need curation. Person-level exports, sessions and the similarity report remain private. Local processing alone does not establish universal legal compliance.

## At a glance

- **Problem:** Spatial and temporal analysis of user-authorised exports.
- **Audience:** Users analysing spatial data they are authorised to use.
- **My role:** Spatial and temporal analysis-tool development.
- **Technologies and method:** DBSCAN; radius of gyration; Shannon entropy; Jaccard; Bray–Curtis; centroid distance.
- **Engineering decision:** A local-first direction using authorised exports and privacy-aware analysis.
- **Available to review:** The official thesis and conference-proceedings citations, and this bounded account of a separate 2026 rebuild. No personal location dataset or public runnable package is offered yet.

[Continue reading on the website](https://yahyaalali.com/en/content-library/project/location-analysis/) · [Back to selected work](../../README.md)
