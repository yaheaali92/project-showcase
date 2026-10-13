# Intelligent routing and quality of service in SDN–MPLS networks

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md)

Doctoral research into routing decisions that respond to changing network load and failed links, evaluating their effect on quality of service in SDN–MPLS networks.

**Stage: Ongoing research**

![Intelligent routing and quality of service in SDN–MPLS networks](https://yahyaalali.com/images/editorial/routing-paths-r3.webp)

Generated conceptual illustration, not an actual interface or research result.

## The routing problem

When network load changes or a link fails, a route that was appropriate a moment ago may no longer be the best choice. My research examines how routing decisions can respond to these changes in software-defined networks using multiprotocol label switching (MPLS), and how their effects on quality of service can be evaluated.

I began my Computer Engineering doctorate at Istanbul University-Cerrahpaşa in September 2024. The work connects network observations, a representation of the current state and the selection of routes for data traffic.

## Connecting observations and decisions

I build an experimental environment linking network measurements, routing decisions and programmable forwarding. Load and link-state observations are prepared as inputs to the decision process. PPO is the routing-decision component: a reinforcement-learning method that learns from the effects of its decisions. LSTM-based traffic prediction is being studied as an auxiliary input, not as a replacement for the routing component.

Control instructions program the forwarding devices. User packets remain on the network's data paths; using an intelligent controller does not mean that every packet passes through the learning program.

## Evaluating the chosen route

The evaluation considers controlled congestion and link failures, comparing routing behaviour under defined experimental conditions. Measurements include latency, jitter, packet loss, throughput, link utilisation and recovery time. Quality-of-service requirements connect these measures to traffic needs rather than treating a short path as sufficient by itself.

My contribution covers the network environment, the measurement-to-decision integration and the evaluation method. Research is ongoing. The next step is to complete the comparisons and statistical validation for defined scenarios before presenting their results.

The [introduction to software-defined networking](https://yahyaalali.com/en/content-library/article/software-defined-networking-sdn/) explains the distinction between control and data forwarding.

## At a glance

- **Problem:** Studying routing decisions that adapt to network state and quality-of-service requirements.
- **Audience:** Network and systems researchers and engineers.
- **My role:** Computer Engineering doctoral student, pursuing the work since September 2024.
- **Technologies and method:** SDN, MPLS
- **Available to review:** An ongoing doctoral topic and public QoS evaluation questions, without published quantitative results.

[Continue reading on the website](https://yahyaalali.com/en/content-library/project/phd-routing/) · [Back to selected work](../../README.md)
